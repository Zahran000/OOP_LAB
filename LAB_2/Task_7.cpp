Task 7: Matrix Multiplication Using Pointers

#include <iostream>
using namespace std;

void allocateMatrix(int**& matrix, int rows, int cols) {
    matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
}

void deallocateMatrix(int**& matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void inputMatrix(int** matrix, int rows, int cols, const string& name) {
    cout << "Enter elements of " << name << " matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }
}

void multiplyMatrices(int** matrix1, int** matrix2, int** result, int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void displayMatrix(int** matrix, int rows, int cols, const string& name) {
    cout << name << " matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows1, cols1, rows2, cols2;
    cout << "Enter rows and columns for the first matrix: ";
    cin >> rows1 >> cols1;
    cout << "Enter rows and columns for the second matrix: ";
    cin >> rows2 >> cols2;

    if (cols1 != rows2) {
        cout << "Matrix multiplication is not possible.";
        return 1;
    }

    int **matrix1, **matrix2, **result;
    allocateMatrix(matrix1, rows1, cols1);
    allocateMatrix(matrix2, rows2, cols2);
    allocateMatrix(result, rows1, cols2);

    inputMatrix(matrix1, rows1, cols1, "Matrix 1");
    inputMatrix(matrix2, rows2, cols2, "Matrix 2");

    multiplyMatrices(matrix1, matrix2, result, rows1, cols1, cols2);

    displayMatrix(result, rows1, cols2, "Result");

    deallocateMatrix(matrix1, rows1);
    deallocateMatrix(matrix2, rows2);
    deallocateMatrix(result, rows1);

    return 0;
}
