#ifndef THERMOMETER_H
#define THERMOMETER_H
#include "WeatherSensor.h"

class Thermometer : public WeatherSensor {
private:
    double temperature;
    string unit;

public:
    Thermometer(string u = "Celsius");
    void readData() override;
    void displayReport() const override;
};

#endif