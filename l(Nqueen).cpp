#include <iostream>
#include <vector>

using namespace std;

// Function to check if placing a queen at (row, col) is safe
bool isSafe(int row, int col, vector<int>& board) {
    for (int r = 0; r < row; ++r) {
        if (board[r] == col || abs(row - r) == abs(col - board[r])) {
            return false; // Conflict found
        }
    }
    return true; // No conflicts
}

// Function to solve N Queens problem recursively and store all solutions
void solveNQueens(int row, int n, vector<int>& board, vector<vector<int>>& solutions) {
    if (row == n) {
        solutions.push_back(board); // Store the found solution
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(row, col, board)) {
            board[row] = col;
            solveNQueens(row + 1, n, board, solutions);
            board[row] = -1; // backtrack
        }
    }
}

// Function to find and return all solutions of column indices of queens for each row
vector<vector<int>> nQueens(int n) {
    vector<int> board(n, -1); // board[i] = j means queen at row i, column j
    vector<vector<int>> solutions;

    solveNQueens(0, n, board, solutions);

    return solutions;
}

int main() {
    int n;
    cout << "Enter the number of queens (N): ";
    cin >> n;

    vector<vector<int>> solutions = nQueens(n);

    // Print all the solutions as column indices of queens for each row
    for (auto &sol : solutions) {
        for (int col : sol) {
            cout << col << " ";
        }
        cout << endl;
    }

    cout << "Total number of solutions: " << solutions.size() << endl;

    return 0;
}