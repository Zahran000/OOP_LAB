#ifndef GROUNDSHIPMENT_H
#define GROUNDSHIPMENT_H
#include "Shipment.h"

class GroundShipment : public Shipment {
private:
    string city;

public:
    GroundShipment(const string& num, double w, const string& c);
    int estimateDeliveryTime() const override;
    void showDetails() const override;
};

#endif
