Task 9: Real-World Use Case - Product Inventory

#include <iostream>
#include <string>
using namespace std;

struct Product {
    int productID;
    string name;
    int quantity;
    float price;
};

int main() {
    int numProducts;
    cout << "Enter the number of products: ";
    cin >> numProducts;

    Product* products = new Product[numProducts];

    for (int i = 0; i < numProducts; ++i) {
        cout << "Enter details for product " << i + 1 << ":\n";
        cout << "Product ID: ";
        cin >> products[i].productID;
        cout << "Name: ";
        cin.ignore();
        getline(cin, products[i].name);
        cout << "Quantity: ";
        cin >> products[i].quantity;
        cout << "Price: ";
        cin >> products[i].price;
    }

    float totalValue = 0;
    for (int i = 0; i < numProducts; ++i) {
        totalValue += products[i].quantity * products[i].price;
    }

    cout << "\nTotal inventory value: " << totalValue << endl;

    delete[] products;
    return 0;
}

