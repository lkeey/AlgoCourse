#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string s, int i, int j) {

    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i ++;
        j --;
    }

    return true;
}

int main() {
    string s, max_s;
    int ma = 0;

    cin >> s;

    for (int i=0; i < s.length(); i++) {
        for (int j=i; j < s.length(); j++) {
            if (j-i+1 > ma && is_palindrome(s, i, j)) {
                ma = j-i+1;
                max_s = s.substr(i, j-i+1);
            }
        }
    }

    cout << ma << endl << max_s << endl;

    return 0;
}