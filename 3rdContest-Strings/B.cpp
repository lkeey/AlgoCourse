#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    vector<char> stack;

    cin >> s;

    for (int i=0; i<s.length(); i++) {
        
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack.push_back(s[i]);
        } else {

            if (stack.empty()) {  
                cout << "NO";
                return 0;
            }

            if ((stack[stack.size()-1] == '(' && s[i] == ')') || (stack[stack.size()-1] == '[' && s[i] == ']') || (stack[stack.size()-1] == '{' && s[i] == '}')) {
                stack.pop_back();
            } else {
                cout << "NO";
                return 0;
            }
        }
    }

    if (stack.empty()) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}