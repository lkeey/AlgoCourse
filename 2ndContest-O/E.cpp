#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n, a, cnt=0;
    vector<int> arr;

    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    for (int i=0; i < n; i++) {
        for (int j=i+1; j < n; j++) {
            for (int k=j+1; k<n; k++) {
                if ((arr[i] + arr[j] > arr[k]) && (arr[i] + arr[k] > arr[j]) && (arr[j] + arr[k] > arr[i])) {
                    cnt ++;
                }
            }
        }
    }

    cout << cnt;

}
