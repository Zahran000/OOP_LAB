#include "Thermometer.h"
#include <iostream>

Thermometer::Thermometer(string u) : unit(u), temperature(0.0) {}

void Thermometer::readData() {
    temperature = 25.0; 
}

void Thermometer::displayReport() const {
    cout << "Thermometer Reading:\n";
    cout << "Temperature: " << temperature << " " << unit << "\n";
}