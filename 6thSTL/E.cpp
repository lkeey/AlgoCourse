#include <iostream>
#include <string>
using namespace std;

bool isUpper(char c) {
    return c >= 'A' && c <= 'Z';
}

int main() {
    string s;
    cin >> s;

    int len = s.length();
    int rune_len = 0;
    bool ok = true;

    for (int i = 0; i < len; i++) {
        if (isUpper(s[i])) {
            // если не первая руна — проверяем предыдущую
            if (i > 0) {
                if (rune_len < 2 || rune_len > 4)
                    ok = false;
            }
            rune_len = 1; // начинаем новую руну
        } else {
            rune_len++;
        }
    }

    // проверяем последнюю руну
    if (rune_len < 2 || rune_len > 4)
        ok = false;

    cout << (ok ? "Yes" : "No");
    return 0;
}
