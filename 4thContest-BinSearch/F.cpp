#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 

using namespace std;

bool canPass(long long x, const vector<pair<int,int>>& arr) {
    __int128 cur = x;
    
    for (pair<int, int> com : arr) {
        if (com.first == 1) {
            cur *= com.second;
        } else if (com.first == 2) {
            cur += com.second;
        } else {
            cur -= com.second;
        }

        if (cur <= 0) {
            return false;
        } 
    }

    return true;
}

int main() {

    int n;
    vector<pair<int, int>> arr;

    cin >> n;

    for (int i=0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({a,b});
    }

    long long l = 1, r = 1;
    while(!canPass(r, arr)) r *= 2;
    
    while (l < r) {
        long long m = (r+l) / 2;

        if (canPass(m, arr)) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    cout << l;

    return 0;
}
