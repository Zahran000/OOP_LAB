#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace std;

class DimensionMismatchException : public exception {
private:
    string message;
public:
    DimensionMismatchException(int rows1, int cols1, int rows2, int cols2) {
        stringstream ss;
        ss << "DimensionMismatchException - Matrices must have same dimensions ("
           << rows1 << "x" << cols1 << " vs " << rows2 << "x" << cols2 << ")!";
        message = ss.str();
    }
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

template <typename T>
class Matrix {
private:
    T** data;
    int rows;
    int cols;
    
    void allocateMemory() {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
        }
    }
    
    void deallocateMemory() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
    
public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        allocateMemory();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = T();
            }
        }
    }
    
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        allocateMemory();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    
    ~Matrix() {
        deallocateMemory();
    }
    
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            deallocateMemory();
            rows = other.rows;
            cols = other.cols;
            allocateMemory();
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        return *this;
    }
    
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    
    T& operator()(int row, int col) {
        return data[row][col];
    }
    
    const T& operator()(int row, int col) const {
        return data[row][col];
    }
    
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw DimensionMismatchException(rows, cols, other.rows, other.cols);
        }
        
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    
    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    try {
        Matrix<int> A(2, 2);
        Matrix<int> B(2, 2);
        
        A(0, 0) = 1; A(0, 1) = 2;
        A(1, 0) = 3; A(1, 1) = 4;
        
        B(0, 0) = 5; B(0, 1) = 6;
        B(1, 0) = 7; B(1, 1) = 8;
        
        cout << "Matrix A:" << endl;
        A.print();
        cout << "\nMatrix B:" << endl;
        B.print();
        
        Matrix<int> C = A + B;
        cout << "\nA + B:" << endl;
        C.print();
        
        Matrix<int> D(3, 3);
        cout << "\nAttempting to add 2x2 and 3x3 matrices..." << endl;
        Matrix<int> E = A + D;
    }
    catch (const DimensionMismatchException& e) {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Standard exception: " << e.what() << endl;
    }
    
    return 0;
}
