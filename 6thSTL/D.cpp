#include <iostream>
#include <set>
#include <string>
using namespace std;

// Компаратор: сравнивает числа как строки, но по числовому значению
struct NumCompare {
    bool operator()(const string& a, const string& b) const {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    }
};

int main() {
    int n;
    cin >> n;

    set<string, NumCompare> nums; // упорядочено как числа

    for (int i = 0; i < n; i++) {
        string m;
        cin >> m;

        string small = "-1", big = "-1";

        auto it = nums.lower_bound(m); // первое >= m

        if (it != nums.begin()) {
            auto prev_it = prev(it);
            small = *prev_it;
        }

        if (it != nums.end()) {
            if (*it != m) big = *it;
            else {
                ++it;
                if (it != nums.end()) big = *it;
            }
        }

        cout << small << " " << big << endl;

        nums.insert(m);
    }

    return 0;
}
