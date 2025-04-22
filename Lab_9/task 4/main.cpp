#include "Thermometer.h"
#include "Barometer.h"
#include <iostream>
using namespace std;

int main() {
    WeatherSensor* sensors[2];
    
    sensors[0] = new Thermometer();
    sensors[1] = new Barometer();

    for (int i = 0; i < 2; i++) {
        sensors[i]->readData();
        sensors[i]->displayReport();
        cout << "------------------\n";
        delete sensors[i];
    }

    return 0;
}