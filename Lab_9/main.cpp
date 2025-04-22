#include "AirFreight.h"
#include "GroundShipment.h"
#include <iostream>
using namespace std;

int main() {
    Shipment* shipments[2];
    
    shipments[0] = new AirFreight("PK123AIR", 45.5, "LHE");
    shipments[1] = new GroundShipment("PK456GRD", 75.0, "Islamabad");

    cout << "=== TALHA SHAHID LOGISTICS ===\n";
    for (int i = 0; i < 2; i++) {
        shipments[i]->showDetails();
        cout << "------------------------\n";
        delete shipments[i];
    }

    return 0;
}
