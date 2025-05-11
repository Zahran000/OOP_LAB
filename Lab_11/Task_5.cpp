#include <iostream>
#include <stdexcept>

using namespace std;

class NegativeStockException : public exception {};
class OverCapacityException : public exception {};

template <typename T>
class InventoryItem {
private:
    T stock;
    T maxCapacity;

public:
    InventoryItem(T max) : maxCapacity(max), stock(0) {}

    void setStock(T newStock) {
        if (newStock < 0) {
            throw NegativeStockException();
        }
        if (newStock > maxCapacity) {
            throw OverCapacityException();
        }
        stock = newStock;
    }

    T getStock() const {
        return stock;
    }
};

int main() {
    InventoryItem<int> item(100);

    try {
        cout << "Attempting to set stock to -5..." << endl;
        item.setStock(-5);
    }
    catch (const NegativeStockException& e) {
        cerr << "Caught NegativeStockException - what(): " << e.what() << endl;
    }

    try {
        cout << "Attempting to set stock to 120 (max 100)..." << endl;
        item.setStock(120);
    }
    catch (const OverCapacityException& e) {
        cerr << "Caught OverCapacityException - what(): " << e.what() << endl;
    }

    try {
        cout << "Setting valid stock (50)..." << endl;
        item.setStock(50);
        cout << "Current stock: " << item.getStock() << endl;
    }
    catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    }

    return 0;
}
