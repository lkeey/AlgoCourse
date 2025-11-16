#include <iostream>

using namespace std;

int main() {

    string s, result = "";

    cin >> s;

    for (int i=0; i < s.length();) {
    
        int num = 0;
        while (i < s.length() && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            i++;
        }
        if (i >= s.length()) break;
        char c = s[i];

        i++;

        for (int j=0; j < num; j++) {
            result += c;
        }
    }

    cout << result;

    return 0;
}