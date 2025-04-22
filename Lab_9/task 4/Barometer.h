#ifndef BAROMETER_H
#define BAROMETER_H
#include "WeatherSensor.h"

class Barometer : public WeatherSensor {
private:
    double pressure;
    string unit;

public:
    Barometer(string u = "hPa");
    void readData() override;
    void displayReport() const override;
};

#endif