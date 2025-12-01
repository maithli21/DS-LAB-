#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

void concatenateStrings() {
    string s1, s2;
    cout << "Enter first string: ";
    getline(cin, s1);
    cout << "Enter second string: ";
    getline(cin, s2);
    string result = s1 + s2;
    cout << "Concatenated string: " << result << endl;
}

void reverseString() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    int i = 0, j = s.size() - 1;
    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    cout << "Reversed string: " << s << endl;
}

bool isVowelChar(char c) {
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
           c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
}

void deleteVowels() {
    string s, t = "";
    cout << "Enter a string: ";
    getline(cin, s);
    for (char c : s) {
        if (!isVowelChar(c)) t += c;
    }
    cout << "String without vowels: " << t << endl;
}

void sortStrings() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<string> v(n);
    cout << "Enter " << n << " strings (one per line):" << endl;
    for (int i = 0; i < n; i++) getline(cin, v[i]);
    sort(v.begin(), v.end());
    cout << "Strings in alphabetical order:" << endl;
    for (int i = 0; i < n; i++) cout << v[i] << endl;
}

void uppercaseToLowercase() {
    char c;
    cout << "Enter an uppercase character: ";
    cin >> c;
    if (c >= 'A' && c <= 'Z') c = c + 32;
    cout << "Lowercase character: " << c << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    int choice;
    while (true) {
        cout << "\nSTRING MENU\n";
        cout << "1. Concatenate two strings\n";
        cout << "2. Reverse a string\n";
        cout << "3. Delete all vowels from a string\n";
        cout << "4. Sort strings in alphabetical order\n";
        cout << "5. Convert uppercase character to lowercase\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) concatenateStrings();
        else if (choice == 2) reverseString();
        else if (choice == 3) deleteVowels();
        else if (choice == 4) sortStrings();
        else if (choice == 5) uppercaseToLowercase();
        else if (choice == 6) break;
        else cout << "Invalid choice\n";
    }
    return 0;
}
