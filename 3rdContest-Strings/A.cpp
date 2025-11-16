#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2;

    cin >> s1;
    cin >> s2;

    for (int i=0; i < min(s1.length(), s2.length()); i++) {
        if (s1[i] != s2[i]) {
            if (s1[i] < s2[i]) {
                cout << "<";
            } else {
                cout << ">";
            }
            return 0;
        }
    }

    if (s1.length() == s2.length()) {
        cout << "=";
    } else if (s1.length() < s2.length()) {
        cout << "<";
    } else {
        cout << ">";
    }

    return 0;
}
