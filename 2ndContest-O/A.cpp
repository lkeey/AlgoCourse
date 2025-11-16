#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, a;
    cin >> n;

    vector<int> arr;
    for (int i=0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end(), greater<int>());
    
    for (int a : arr) {
        cout << a << " "; 
    }
    
}
