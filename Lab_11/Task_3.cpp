#include <iostream>
#include <stdexcept>

using namespace std;

class InvalidTemperatureException : public exception {};

template <typename T>
T convertToFahrenheit(T celsius) {
    if (celsius < -273.15) {
        throw InvalidTemperatureException();
    }
    return celsius * 9.0 / 5.0 + 32;
}

int main() {
    try {
        cout << "Attempting to convert -300C..." << endl;
        double result = convertToFahrenheit(-300.0);
        cout << "Result: " << result << "F" << endl;
    }
    catch (const InvalidTemperatureException& e) {
        cerr << "Caught InvalidTemperatureException - what(): " << e.what() << endl;
    }

    try {
        cout << "Attempting to convert 0C..." << endl;
        double result = convertToFahrenheit(0.0);
        cout << "Result: " << result << "F" << endl;
    }
    catch (const InvalidTemperatureException& e) {
        cerr << "Caught InvalidTemperatureException - what(): " << e.what() << endl;
    }

    try {
        cout << "Attempting to convert -273.15C..." << endl;
        double result = convertToFahrenheit(-273.15);
        cout << "Result: " << result << "F" << endl;
    }
    catch (const InvalidTemperatureException& e) {
        cerr << "Caught InvalidTemperatureException - what(): " << e.what() << endl;
    }

    return 0;
}
