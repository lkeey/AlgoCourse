#include <iostream>
#include <string>


using namespace std;

string getString(string cur, int cur_n, int m) {

    if (cur_n == m) {
        return cur;
    }

    string part;
    cin >> part;

    return getString(part + " " + cur, cur_n+1, m);
}

int main() {

    int n;

    cin >> n;
    
    string result = getString("", 0, n);
    cout << result;

    return 0;
}