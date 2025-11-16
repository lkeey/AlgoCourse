#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m, a;
    vector<int> nums, searches, result;

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a;
        nums.push_back(a);
    }

    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> a;
        searches.push_back(a);
    }

    sort(nums.begin(), nums.end());

    for (int i=0; i < searches.size(); i++) {
        result.push_back(0);

        int left=0, right=nums.size()-1;
        
        while (left <= right) {
            int medium = left + (right - left)/2;
            if (nums[medium] < searches[i]) {
                left = medium + 1;
                result[i] = medium + 1;
            } else {
                right = medium - 1; 
            } 
        }
    }

    for (int n : result) {
        cout << n << " ";
    }

    return 0;
}
