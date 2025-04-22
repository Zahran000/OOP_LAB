#ifndef AIRFREIGHT_H
#define AIRFREIGHT_H
#include "Shipment.h"

class AirFreight : public Shipment {
private:
    string airportCode;

public:
    AirFreight(const string& num, double w, const string& code);
    int estimateDeliveryTime() const override;
    void showDetails() const override;
};

#endif