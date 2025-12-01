#include <iostream>
using namespace std;
int arr[100], n = 0;
void createArr() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
}
void display() {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
void insertVal() {
    int pos, val;
    cin >> pos >> val;
    for(int i = n; i > pos; i--) arr[i] = arr[i - 1];
    arr[pos] = val;
    n++;
}
void deleteVal() {
    int pos;
    cin >> pos;
    for(int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
    n--;
}
void linearSearch() {
    int key;
    cin >> key;
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}
int main() {
    int choice;
    while(1) {
        cin >> choice;
        switch(choice) {
            case 1: createArr(); break;
            case 2: display(); break;
            case 3: insertVal(); break;
            case 4: deleteVal(); break;
            case 5: linearSearch(); break;
            case 6: return 0;
        }
    }
}
