#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr;
    int n, a, chet_mark = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            cout << arr[i] << " ";
        }
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            chet_mark ++;
            cout << arr[i] << " ";
        }
    }

    if (chet_mark >= (n - chet_mark)) {
        cout << endl << "YES";
    } else {
        cout << endl << "NO";
    }

}