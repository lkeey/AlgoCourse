#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int mi = nums[0], min_i = 0;
    double best_ratio = 1.0;
    int best_i = -1, best_j = -1;

    for (int j = 1; j < n; j++) {
        double ratio = (double)nums[j] / mi;
        if (ratio > best_ratio) {
            best_ratio = ratio;
            best_i = min_i;
            best_j = j;
        }
        if (nums[j] < mi) {
            mi = nums[j];
            min_i = j;
        }
    }

    if (best_i == -1)
        cout << "0 0";
    else
        cout << best_i + 1 << " " << best_j + 1;

    return 0;
}
