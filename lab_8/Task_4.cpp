#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string model;
    double price;

public:
    Car(string m, double p) : model(m), price(p) {}

    friend class InventoryManager;
    friend void comparePrice(const Car& car1, const Car& car2);
};

class InventoryManager {
public:
    void updatePrice(Car& car, double newPrice) {
        car.price = newPrice;
        cout << car.model << " ka price update ho gaya: Rs. " << car.price << endl;
    }

    void displayCar(const Car& car) {
        cout << "Model: " << car.model << ", Price: Rs. " << car.price << endl;
    }
};

void comparePrice(const Car& car1, const Car& car2) {
    if (car1.price > car2.price) {
        cout << car1.model << " mehnga hai " << car2.model << " se (" << car1.price << " vs " << car2.price << ")" << endl;
    } else if (car2.price > car1.price) {
        cout << car2.model << " mehnga hai " << car1.model << " se (" << car2.price << " vs " << car1.price << ")" << endl;
    } else {
        cout << "Dono cars ka price barabar hai: Rs. " << car1.price << endl;
    }
}

int main() {
    Car car1("Toyota Corolla", 4500000);
    Car car2("Honda Civic", 4200000);

    InventoryManager manager;

    cout << "Car Dealership Inventory:" << endl;
    manager.displayCar(car1);
    manager.displayCar(car2);

    manager.updatePrice(car1, 4600000);
    comparePrice(car1, car2);

    Car car3("Suzuki Alto", 2000000);
    cout << "\nNayi car add hui:" << endl;
    manager.displayCar(car3);

    comparePrice(car1, car3);

    return 0;
}
