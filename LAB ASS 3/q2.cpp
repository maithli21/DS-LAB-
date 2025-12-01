# include <iostream>
using namespace std;

string ReverseUsingStack ( const string& str){
  stack <char> charStack;
for ( char ch : stack)
  charStack.push(ch);
}
string reversedStr;
while(!charStack.empty()){
reversedStr = reversedStr + charStack.top();
charStack.pop();
}
return reversedStr;
int main() {
    string input = "DataStructure";
    string output = reverseUsingStack(input);
    cout << output << endl;  
    return 0;
}
    
