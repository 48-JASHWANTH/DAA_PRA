/* 1.	Suppose that you are given an m × n grid of integers where each row and each column are in sorted order (we'll call this a sorted grid). Design an O(m + n)-time algorithm that, given as input a sorted m × n grid and an integer, returns whether or not that integer is contained in the grid. Your algorithm should use only O(1) additional space.*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n, target;
    
    // Input the dimensions of the grid
    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;
    
    vector<vector<int>> v(m, vector<int>(n));
    
    // Input the grid elements
    cout << "Enter the elements of the grid in sorted order for each row and column:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }
    
    // Input the target element to find
    cout << "Enter the target element to find: ";
    cin >> target;
    
    // Initialize the starting point for the search
    int i = 0, j = n - 1;
    bool flag = false;
    
    // Search for the target element in O(m + n) time
    while (i >= 0 && j >= 0 && i < m && j < n) {
        if (v[i][j] == target) {
            flag = true;
            break;
        } else if (v[i][j] > target) {
            j--;
        } else {
            i++;
        }
    }
    
    // Output the result
    if (flag) {
        cout << "Element found" << endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    return 0;
}
