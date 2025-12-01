#include <iostream>
#include <queue>
using namespace std;

class StackUsingOneQueue {
    queue<int> q; 

public:
    void push(int x) {
        q.push(x);
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (q.empty()) {
            cout << "Stack is empty! Cannot pop.\n";
            return;
        }
        q.pop();
    }
    int top() {
        if (q.empty()) {
            cout << "Stack is empty! No top element.\n";
            return -1; 
        }
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};

int main() {
    StackUsingOneQueue stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.top() << endl; 

    stack.pop();
    cout << "After popping, top element: " << stack.top() << endl; 

    stack.pop();
    stack.pop();

    if (stack.empty())
        cout << "Stack is empty now.\n";
    else
        cout << "Stack is not empty.\n";

    return 0;
}
