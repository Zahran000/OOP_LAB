#include "GroundShipment.h"
#include <iostream>

GroundShipment::GroundShipment(const string& num, double w, const string& c)
    : Shipment(num, w), city(c) {}

int GroundShipment::estimateDeliveryTime() const {
    return (weight < 20) ? 3 : 5; // Days (lighter packages faster)
}

void GroundShipment::showDetails() const {
    cout << "Ground Shipment Details:\n";
    cout << "Tracking: " << trackingNumber << endl;
    cout << "Weight: " << weight << " kg\n";
    cout << "Destination: " << city << endl;
    cout << "Handler: Karachi Logistics\n";
    cout << "Est. Delivery: " << estimateDeliveryTime() << " days\n";
}
