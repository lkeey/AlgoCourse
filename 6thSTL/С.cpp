#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    int q; 
    string s; 

    cin >> n;

    map<string, int> counts; 

    for (int i = 0; i < n; ++i) {
        cin >> q >> s; 

        if (q == 1) {
            counts[s]++; 
        } else if (q == 2) {
            if (counts.count(s)) {
                cout << counts[s] << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}
