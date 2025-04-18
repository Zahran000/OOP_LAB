#include <iostream>
#include <string>
using namespace std;

class MenuItem {
protected:
    string dishName;
    double price;

public:
    MenuItem(const string& name, double price) : dishName(name), price(price) {}
    virtual ~MenuItem() {}

    virtual void showDetails() const = 0;
    virtual void prepare() const = 0;
};

class Appetizer : public MenuItem {
private:
    string dipSauce;

public:
    Appetizer(const string& name, double price, const string& sauce)
        : MenuItem(name, price), dipSauce(sauce) {}

    void showDetails() const override {
        cout << "APPETIZER DETAILS:" << endl;
        cout << "Dish: " << dishName << endl;
        cout << "Price: $" << price << endl;
        cout << "Comes with: " << dipSauce << " dip" << endl;
    }

    void prepare() const override {
        cout << "Preparing " << dishName << ":" << endl;
        cout << "1. Plate the appetizer portions" << endl;
        cout << "2. Add " << dipSauce << " dip on the side" << endl;
        cout << "3. Garnish with herbs" << endl;
    }
};

class MainCourse : public MenuItem {
private:
    string sideDish;

public:
    MainCourse(const string& name, double price, const string& side)
        : MenuItem(name, price), sideDish(side) {}

    void showDetails() const override {
        cout << "MAIN COURSE DETAILS:" << endl;
        cout << "Dish: " << dishName << endl;
        cout << "Price: $" << price << endl;
        cout << "Includes: " << sideDish << " side" << endl;
    }

    void prepare() const override {
        cout << "Preparing " << dishName << ":" << endl;
        cout << "1. Cook main protein to perfection" << endl;
        cout << "2. Prepare " << sideDish << " side dish" << endl;
        cout << "3. Plate with proper presentation" << endl;
        cout << "4. Add final garnishes" << endl;
    }
};

int main() {
    MenuItem* item1 = new Appetizer("Bruschetta", 8.99, "Balsamic");
    MenuItem* item2 = new MainCourse("Grilled Salmon", 22.99, "Mashed Potatoes");

    cout << "=== Menu Item 1 ===" << endl;
    item1->showDetails();
    cout << "\nPreparation Steps:" << endl;
    item1->prepare();
    cout << endl;

    cout << "=== Menu Item 2 ===" << endl;
    item2->showDetails();
    cout << "\nPreparation Steps:" << endl;
    item2->prepare();
    cout << endl;

    delete item1;
    delete item2;

    return 0;
}
