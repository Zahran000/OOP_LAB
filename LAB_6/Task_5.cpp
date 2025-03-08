#include <iostream>
using namespace std;

class Device {
protected:
    int deviceID;
    bool status;

public:
    Device(int id, bool st) : deviceID(id), status(st) {}

    void displayDetails() {
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << (status ? "Active" : "Inactive") << endl;
    }
};

class SmartPhone : public Device {
protected:
    float screenSize;

public:
    SmartPhone(int id, bool st, float size) : Device(id, st), screenSize(size) {}

    void displayDetails() {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
    }
};

class SmartWatch : public Device {
protected:
    bool heartRateMonitor;

public:
    SmartWatch(int id, bool st, bool hrm) : Device(id, st), heartRateMonitor(hrm) {}

    void displayDetails() {
        Device::displayDetails();
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
    }
};

class SmartWearable : public SmartPhone, public SmartWatch {
private:
    int stepCounter;

public:
    SmartWearable(int id, bool st, float size, bool hrm, int steps)
        : SmartPhone(id, st, size), SmartWatch(id, st, hrm), stepCounter(steps) {}

    void displayDetails() {
        SmartPhone::displayDetails();
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
        cout << "Step Counter: " << stepCounter << " steps" << endl;
    }
};

int main() {
    int deviceID = 123;
    bool status = true;
    float screenSize = 1.5;
    bool heartRateMonitor = true;
    int stepCounter = 5000;

    SmartWearable wearable(deviceID, status, screenSize, heartRateMonitor, stepCounter);
    wearable.displayDetails();

    return 0;
}
