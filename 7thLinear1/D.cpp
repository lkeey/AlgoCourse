#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    vector<long long> prefix(n + 1, 0);
    map<int, int> first_occurrence;
    
    first_occurrence[0] = 0;
    
    int best_start = -1, best_end = -1;
    
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
        int remainder = ((prefix[i] % 3) + 3) % 3;
        
        if (first_occurrence.find(remainder) != first_occurrence.end()) {
            int start_idx = first_occurrence[remainder] + 1;
            int end_idx = i;
            
            if (best_start == -1 || (end_idx - start_idx) > (best_end - best_start)) {
                best_start = start_idx;
                best_end = end_idx;
            }
            else if ((end_idx - start_idx) == (best_end - best_start) && start_idx < best_start) {
                best_start = start_idx;
                best_end = end_idx;
            }
        } else {
            first_occurrence[remainder] = i;
        }
    }
    
    if (best_start == -1) {
        cout << -1 << endl;
    } else {
        cout << best_start << " " << best_end << endl;
    }
    
    return 0;
}