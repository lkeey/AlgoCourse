#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    int n, is_reversed;
    string s;
    vector<string> strs;

    cin >> n;
    cin >> s;
    cin >> is_reversed;

    for (int i=0; i < n; i++) {
        strs.push_back(s.substr(i));
    }

    sort(strs.begin(), strs.end());

    if (is_reversed == -1) {
        reverse(strs.begin(), strs.end());
    }

    for (string s: strs) {
        cout << s << endl;
    }


    return 0;
}