#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    cin >> n;
    cout << (1LL << n) - n - 1 << endl;

}