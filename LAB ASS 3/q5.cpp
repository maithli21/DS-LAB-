#include <iostream>
using namespace std;

int evaluatePostfix(const string& expr) {
    stack<int> s;

    for (char ch : expr) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();

            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                default:
                    cout << "Invalid operator encountered: " << ch << endl;
                    return -1;
            }
        }
    }
    return s.top();
}

int main() {
    string postfixExpr;
    cout << "Enter postfix expression (single digit operands): ";
    cin >> postfixExpr;

    int result = evaluatePostfix(postfixExpr);
    cout << "Result: " << result << endl;

    return 0;
}
