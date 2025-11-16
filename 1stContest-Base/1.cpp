#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr;
    int n, a;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }

}