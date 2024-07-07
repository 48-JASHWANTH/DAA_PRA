#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void inputMatrix(vector<vector<int>>& matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix, int originalRows, int originalCols) {
    cout << "Resultant matrix:" << endl;
    for (int i = 0; i < originalRows; i++) {
        for (int j = 0; j < originalCols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> padMatrix(const vector<vector<int>>& matrix, int rows, int cols, int paddedSize) {
    vector<vector<int>> paddedMatrix(paddedSize, vector<int>(paddedSize, 0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            paddedMatrix[i][j] = matrix[i][j];
        }
    }
    return paddedMatrix;
}

void splitMatrix(const vector<vector<int>>& A, vector<vector<int>>& A11, vector<vector<int>>& A12, vector<vector<int>>& A21, vector<vector<int>>& A22) {
    int n = A.size() / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + n];
            A21[i][j] = A[i + n][j];
            A22[i][j] = A[i + n][j + n];
        }
    }
}

void joinMatrix(vector<vector<int>>& C, const vector<vector<int>>& C11, const vector<vector<int>>& C12, const vector<vector<int>>& C21, const vector<vector<int>>& C22) {
    int n = C.size() / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = C11[i][j];
            C[i][j + n] = C12[i][j];
            C[i + n][j] = C21[i][j];
            C[i + n][j + n] = C22[i][j];
        }
    }
}

vector<vector<int>> add(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

vector<vector<int>> sub(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

vector<vector<int>> strassenMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    // Base case for recursion
    if (n == 1) {
        vector<vector<int>> C(1, vector<int>(1, 0));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    // Divide matrices into submatrices
    int half_n = n / 2;
    vector<vector<int>> A11(half_n, vector<int>(half_n, 0));
    vector<vector<int>> A12(half_n, vector<int>(half_n, 0));
    vector<vector<int>> A21(half_n, vector<int>(half_n, 0));
    vector<vector<int>> A22(half_n, vector<int>(half_n, 0));
    vector<vector<int>> B11(half_n, vector<int>(half_n, 0));
    vector<vector<int>> B12(half_n, vector<int>(half_n, 0));
    vector<vector<int>> B21(half_n, vector<int>(half_n, 0));
    vector<vector<int>> B22(half_n, vector<int>(half_n, 0));

    splitMatrix(A, A11, A12, A21, A22);
    splitMatrix(B, B11, B12, B21, B22);

    // Recursive steps for Strassen algorithm
    vector<vector<int>> M1 = strassenMultiply(add(A11, A22), add(B11, B22));
    vector<vector<int>> M2 = strassenMultiply(add(A21, A22), B11);
    vector<vector<int>> M3 = strassenMultiply(A11, sub(B12, B22));
    vector<vector<int>> M4 = strassenMultiply(A22, sub(B21, B11));
    vector<vector<int>> M5 = strassenMultiply(add(A11, A12), B22);
    vector<vector<int>> M6 = strassenMultiply(sub(A21, A11), add(B11, B12));
    vector<vector<int>> M7 = strassenMultiply(sub(A12, A22), add(B21, B22));

    // Compute the submatrices of the result matrix
    vector<vector<int>> C11 = add(sub(add(M1, M4), M5), M7);
    vector<vector<int>> C12 = add(M3, M5);
    vector<vector<int>> C21 = add(M2, M4);
    vector<vector<int>> C22 = add(sub(add(M1, M3), M2), M6);

    // Combine submatrices into the result matrix
    vector<vector<int>> C(n, vector<int>(n, 0));
    joinMatrix(C, C11, C12, C21, C22);

    return C;
}

int main() {
    int m1, n1, m2, n2;
    cout << "Enter the dimensions of the first matrix (m1 x n1):" << endl;
    cin >> m1 >> n1;

    cout << "Enter the dimensions of the second matrix (m2 x n2):" << endl;
    cin >> m2 >> n2;

    if (n1 != m2) {
        cout << "Matrices cannot be multiplied." << endl;
        return 0;
    } 

    vector<vector<int>> A(m1, vector<int>(n1));
    vector<vector<int>> B(m2, vector<int>(n2));

    cout << "Enter the elements of the first matrix:" << endl;
    inputMatrix(A, m1, n1);
    cout << "Enter the elements of the second matrix:" << endl;
    inputMatrix(B, m2, n2);

    int maxSize = max(max(m1,n1),max(m2,n2));
    int size = pow(2, ceil(log2(maxSize))); // Ensure size is the next power of 2

    vector<vector<int>> paddedA = padMatrix(A, m1, n1, size);
    vector<vector<int>> paddedB = padMatrix(B, m2, n2, size);

    vector<vector<int>> C = strassenMultiply(paddedA, paddedB);

    printMatrix(C, m1, n2); // Print only the relevant part of the resultant matrix
}
