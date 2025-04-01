
#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
    string deviceID;
    string deviceName;
    string location;
    bool status;
public:
    Device(string id, string name, string loc) : deviceID(id), deviceName(name), location(loc), status(false) {}
    
    void turnOn() { status = true; }
    void turnOff() { status = false; }
    string getStatus() { return status ? "ON" : "OFF"; }
    virtual void displayInfo() {
        cout << "Device ID: " << deviceID << "\nName: " << deviceName 
             << "\nLocation: " << location << "\nStatus: " << getStatus() << endl;
    }
};

class Light : public Device {
    int brightnessLevel;
    string colorMode;
public:
    Light(string id, string name, string loc, int bright, string color) 
        : Device(id, name, loc), brightnessLevel(bright), colorMode(color) {}
    
    void displayInfo() override {
        Device::displayInfo();
        cout << "Brightness: " << brightnessLevel << "%\nColor Mode: " << colorMode << endl;
    }
};

class Thermostat : public Device {
    float temperature;
    string mode;
    float targetTemperature;
public:
    Thermostat(string id, string name, string loc, float temp, string m, float target) 
        : Device(id, name, loc), temperature(temp), mode(m), targetTemperature(target) {}
    
    string getStatus() override {
        return "Current Temp: " + to_string(temperature) + "°C, Target: " + to_string(targetTemperature) + "°C";
    }
};

class SecurityCamera : public Device {
    string resolution;
    bool recordingStatus;
    bool nightVisionEnabled;
public:
    SecurityCamera(string id, string name, string loc, string res, bool nightVision) 
        : Device(id, name, loc), resolution(res), nightVisionEnabled(nightVision), recordingStatus(false) {}
    
    void turnOn() override {
        Device::turnOn();
        recordingStatus = true;
        cout << "Recording started for " << deviceName << " in " << location << endl;
    }
};

class SmartPlug : public Device {
    float powerConsumption;
    string timeSetting;
public:
    SmartPlug(string id, string name, string loc, float power, string time) 
        : Device(id, name, loc), powerConsumption(power), timeSetting(time) {}
    
    void turnOff() override {
        Device::turnOff();
        cout << "Logged power usage: " << powerConsumption << " kWh for " << deviceName << endl;
    }
};

int main() {
    Light chandniChowk("L001", "Chandni Chowk Light", "Lounge", 75, "Warm White");
    Thermostat lahoreHeat("T001", "Lahore Heat Control", "Bedroom", 28.5, "Cooling", 24.0);
    SecurityCamera karachiCam("C001", "Karachi Security", "Front Door", "1080p", true);
    SmartPlug islamabadPlug("P001", "Islamabad Smart Plug", "Study", 2.5, "18:00-22:00");
    
    chandniChowk.turnOn();
    chandniChowk.displayInfo();
    cout << endl;
    
    cout << lahoreHeat.getStatus() << endl;
    cout << endl;
    
    karachiCam.turnOn();
    cout << endl;
    
    islamabadPlug.turnOn();
    islamabadPlug.turnOff();
    
    return 0;
}
