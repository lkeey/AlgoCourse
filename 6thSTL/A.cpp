#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    string s;
    vector<string> strs;

    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> s;
        strs.push_back(s);
    }

    sort(strs.begin(), strs.end());

    for (string s: strs) {
        cout << s << endl;
    }

    return 0;
}