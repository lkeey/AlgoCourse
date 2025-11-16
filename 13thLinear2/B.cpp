#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int ma=0, left=0, height=arr[0];

    for (int right=1; right<n; right++) {
        if (arr[right] < height) {
            height = arr[right];
        }


    }

    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}