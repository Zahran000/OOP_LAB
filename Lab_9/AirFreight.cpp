#include "AirFreight.h"
#include <iostream>

AirFreight::AirFreight(const string& num, double w, const string& code)
    : Shipment(num, w), airportCode(code) {}

int AirFreight::estimateDeliveryTime() const {
    return (weight < 50) ? 2 : 3; // Days (lighter packages faster)
}

void AirFreight::showDetails() const {
    cout << "Air Freight Details:\n";
    cout << "Tracking: " << trackingNumber << endl;
    cout << "Weight: " << weight << " kg\n";
    cout << "Airport: " << airportCode << endl;
    cout << "Handler: Ali Cargo Services\n";
    cout << "Est. Delivery: " << estimateDeliveryTime() << " days\n";
}
