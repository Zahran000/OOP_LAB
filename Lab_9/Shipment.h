#ifndef SHIPMENT_H
#define SHIPMENT_H
#include <string>
using namespace std;

class Shipment {
protected:
    string trackingNumber;
    double weight;

public:
    Shipment(const string& num, double w) : trackingNumber(num), weight(w) {}
    virtual ~Shipment() {}
    virtual int estimateDeliveryTime() const = 0;
    virtual void showDetails() const = 0;
};

#endif