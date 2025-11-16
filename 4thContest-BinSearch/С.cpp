#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 

using namespace std;

int main() {
    int n, k;
    vector<int> nums;

    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> k;
        nums.push_back(k);
    }

    cin >> k;

    int l=*max_element(nums.begin(), nums.end()), r=accumulate(nums.begin(), nums.end(), 0);

    while (l < r) {
        int medium = l + (r-l)/2;

        int current_tom=0, tom_size=1;
        
        for (int n : nums) {
        
            if (current_tom + n <= medium) {
                current_tom += n;
            } else {
                tom_size ++;
                current_tom = n;
            }
            
        }

        if (tom_size <= k) {
            r = medium;
        } else {
            l = medium + 1;
        }
    }

    cout << l;

    return 0;
}