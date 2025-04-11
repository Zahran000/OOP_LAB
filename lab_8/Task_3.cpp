#include <iostream>
#include <string>

using namespace std;

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double xVal = 0.0, double yVal = 0.0) : x(xVal), y(yVal) {}

    Vector2D operator+(const Vector2D& other) {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator*(double scalar) {
        return Vector2D(x * scalar, y * scalar);
    }

    friend double dotProduct(const Vector2D& v1, const Vector2D& v2) {
        return v1.x * v2.x + v1.y * v2.y;
    }

    friend ostream& operator<<(ostream& os, const Vector2D& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
};

int main() {
    Vector2D v1(3.0, 4.0);
    Vector2D v2(1.5, 2.5);

    cout << "Ahmed's Vector 1: " << v1 << endl;
    cout << "Usman's Vector 2: " << v2 << endl;

    Vector2D sum = v1 + v2;
    Vector2D diff = v1 - v2;
    Vector2D scaled = v1 * 2.0;

    cout << "\nSum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Ahmed's Vector scaled by 2: " << scaled << endl;
    cout << "Dot Product: " << dotProduct(v1, v2) << endl;

    return 0;
}
