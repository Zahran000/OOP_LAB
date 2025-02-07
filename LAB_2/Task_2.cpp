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
    matrix = nullptr;
}

void inputMatrix(int** matrix, int rows, int cols, const string& name) {
    cout << "Enter elements of " << name << " matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
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

void matrixAddition(int** matrix1, int** matrix2, int** result, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrixSubtraction(int** matrix1, int** matrix2, int** result, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns for the matrices: ";
    cin >> rows >> cols;

    int **matrix1, **matrix2, **resultAdd, **resultSub;

    allocateMatrix(matrix1, rows, cols);
    allocateMatrix(matrix2, rows, cols);
    allocateMatrix(resultAdd, rows, cols);
    allocateMatrix(resultSub, rows, cols);

    inputMatrix(matrix1, rows, cols, "Matrix 1");
    inputMatrix(matrix2, rows, cols, "Matrix 2");

    matrixAddition(matrix1, matrix2, resultAdd, rows, cols);
    matrixSubtraction(matrix1, matrix2, resultSub, rows, cols);

    displayMatrix(resultAdd, rows, cols, "Addition");
    displayMatrix(resultSub, rows, cols, "Subtraction");

    deallocateMatrix(matrix1, rows);
    deallocateMatrix(matrix2, rows);
    deallocateMatrix(resultAdd, rows);
    deallocateMatrix(resultSub, rows);

    return 0;
}

