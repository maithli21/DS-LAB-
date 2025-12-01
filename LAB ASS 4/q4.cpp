#include <iostream>
#include <queue>
using namespace std;

void FirstNonRepeatingCharInStream(const string& str) {
    int freq[256] = {0}; 
    queue<char> q; 

    for (char ch : str) {
        freq[ch]++;   
        q.push(ch);    

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

       
        if (q.empty()) {
            cout << -1 << " ";
        } else {
            cout << q.front() << " ";
        }
    }
    cout << endl;
}

int main() {
    string input;
    cout << "Enter characters (without spaces): ";
    cin >> input;

    firstNonRepeatingCharInStream(input);

    return 0;
}
