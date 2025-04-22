#ifndef WEATHERSENSOR_H
#define WEATHERSENSOR_H
#include <string>
using namespace std;

class WeatherSensor {
public:
    virtual ~WeatherSensor() {}
    virtual void readData() = 0;
    virtual void displayReport() const = 0;
};

#endif