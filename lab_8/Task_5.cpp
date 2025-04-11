#include <iostream>
#include <string>
using namespace std;

class Matrix2x2;

class MatrixHelper {
public:
    void updateElement(Matrix2x2& m, int index, int newValue);
};

class Matrix2x2 {
private:
    int data[4];
public:
    Matrix2x2(int a = 0, int b = 0, int c = 0, int d = 0) {
        data[0] = a;
        data[1] = b;
        data[2] = c;
        data[3] = d;
    }

    Matrix2x2 operator+(const Matrix2x2& other) {
        return Matrix2x2(data[0] + other.data[0], data[1] + other.data[1],
                         data[2] + other.data[2], data[3] + other.data[3]);
    }

    Matrix2x2 operator-(const Matrix2x2& other) {
        return Matrix2x2(data[0] - other.data[0], data[1] - other.data[1],
                         data[2] - other.data[2], data[3] - other.data[3]);
    }

    Matrix2x2 operator*(const Matrix2x2& other) {
        return Matrix2x2(
            data[0] * other.data[0] + data[1] * other.data[2],
            data[0] * other.data[1] + data[1] * other.data[3],
            data[2] * other.data[0] + data[3] * other.data[2],
            data[2] * other.data[1] + data[3] * other.data[3]
        );
    }

    friend int determinant(const Matrix2x2& m) {
        return m.data[0] * m.data[3] - m.data[1] * m.data[2];
    }

    friend class MatrixHelper;

    friend ostream& operator<<(ostream& out, const Matrix2x2& m) {
        out << "[" << m.data[0] << " " << m.data[1] << "]" << endl;
        out << "[" << m.data[2] << " " << m.data[3] << "]";
        return out;
    }
};

void MatrixHelper::updateElement(Matrix2x2& m, int index, int newValue) {
    if(index >= 0 && index < 4) {
        m.data[index] = newValue;
    }
}

int main() {
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(5, 6, 7, 8);

    cout << "Matrix 1:" << endl << m1 << endl;
    cout << "Matrix 2:" << endl << m2 << endl;

    Matrix2x2 sum = m1 + m2;
    cout << "Sum:" << endl << sum << endl;

    Matrix2x2 diff = m1 - m2;
    cout << "Difference:" << endl << diff << endl;

    Matrix2x2 product = m1 * m2;
    cout << "Product:" << endl << product << endl;

    cout << "Determinant of Matrix 1: " << determinant(m1) << endl;

    MatrixHelper helper;
    helper.updateElement(m1, 2, 99);
    cout << "Matrix 1 after update:" << endl << m1 << endl;

    return 0;
}
