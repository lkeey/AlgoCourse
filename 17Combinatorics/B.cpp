#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Create a 2D vector to store Pascal's triangle
    vector<vector<long long>> triangle(n);
    
    // Build Pascal's triangle row by row
    for (int i = 0; i < n; i++) {
        triangle[i].resize(i + 1);
        
        // First and last elements of each row are 1
        triangle[i][0] = triangle[i][i] = 1;
        
        // Each inner element is the sum of the two elements above it
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }
    
    // Print Pascal's triangle
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << triangle[i][j];
            if (j < i) {
                cout << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}