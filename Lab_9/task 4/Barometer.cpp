#include "Barometer.h"
#include <iostream>

Barometer::Barometer(string u) : unit(u), pressure(0.0) {}

void Barometer::readData() {
    pressure = 1013.25; 
}
void Barometer::displayReport() const {
    cout << "Barometer Reading:\n";
    cout << "Pressure: " << pressure << " " << unit << "\n";
}