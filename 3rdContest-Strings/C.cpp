#include <iostream>
#include <string>

using namespace std;

int main() {
    int cnt = 0;
    string s1, s2;

    cin >> s1;
    cin >> s2;

    for (int left=0; left < s2.length(); left++) {
        if (s2.substr(left, s1.length()) == s1) {
            cnt ++;
        }
    }

    cout << cnt;

}