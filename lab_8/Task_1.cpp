#include <iostream>
#include <string>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    Complex operator/(const Complex& other) {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex(
            (real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator
        );
    }

    friend double magnitude(const Complex& c) {
        return sqrt(c.real * c.real + c.imag * c.imag);
    }

    friend ostream& operator<<(ostream& os, const Complex& c) {
        if (c.imag >= 0)
            os << "(" << c.real << " + " << c.imag << "i)";
        else
            os << "(" << c.real << " - " << -c.imag << "i)";
        return os;
    }
};

int main() {
    Complex c1(2.5, 3.7);
    Complex c2(1.2, -4.1);

    cout << "Complex Number 1: " << c1 << endl;
    cout << "Complex Number 2: " << c2 << endl;

    cout << "\nSum: " << c1 + c2 << endl;
    cout << "Difference: " << c1 - c2 << endl;
    cout << "Product: " << c1 * c2 << endl;
    cout << "Division: " << c1 / c2 << endl;
    cout << "Magnitude of c1 Number: " << magnitude(c1) << endl;

    return 0;
}
