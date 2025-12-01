#include <iostream>
using namespace std;

class stack {
int size;
int top;
  public:
    Stack() {
      top = -1;
      size = 1000;
      arr = new int[size];
    }
  void push(int x) {
    top++;
    arr[top] = x;
  }
  int pop() {
    if ( top==-1) return -1;
    int x = arr[top];
    top--;
    return x;
  }
int top(){
  return arr[top];
}
bool isEmpty() {
    return top == -1;
}
bool isFull() {
    return top == size - 1;
}
void display() {
    if (isEmpty()) {
        cout << "Stack is Empty!" << endl;
        return;
    }
  cout << "Stack Elements: ";
    for (int i = top; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int peek() {
    if (isEmpty()) {
        cout << "Stack is Empty!" << endl;
        return -1;
    }
    cout << "Top Element: " << arr[top] << endl;
    return arr[top];
}

  

 
int main() {

  Stack s;
  s.push(6);
  s.push(3);
  s.push(7);
  cout << "Top of stack is before deleting any element " << s.Top() << endl;
  cout << "Size of stack before deleting any element " << s.Size() << endl;
  cout << "The element deleted is " << s.pop() << endl;
  cout << "Size of stack after deleting an element " << s.Size() << endl;
  cout << "Top of stack after deleting an element " << s.Top() << endl;
  return 0;
}
        
        return;
    }
    arr[++top] = x;
    cout << x << " pushed to stack." << endl;
}
