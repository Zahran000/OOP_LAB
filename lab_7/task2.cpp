#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    string productID;
    string productName;
    float price;
    int stockQuantity;
public:
    Product(string id, string name, float p, int stock) 
        : productID(id), productName(name), price(p), stockQuantity(stock) {}
    
    virtual void applyDiscount(float percent) {
        price *= (1 - percent/100);
    }
    
    virtual float calculateTotalPrice(int quantity) {
        return price * quantity;
    }
    
    virtual void displayProductInfo() {
        cout << "ID: " << productID << "\nName: " << productName 
             << "\nPrice: Rs." << price << "\nStock: " << stockQuantity << endl;
    }
    
    // Operator overloading
    float operator+(Product& p) {
        return this->price + p.price;
    }
    
    friend ostream& operator<<(ostream& os, Product& p);
};

ostream& operator<<(ostream& os, Product& p) {
    p.displayProductInfo();
    return os;
}

class Electronics : public Product {
    int warrantyPeriod;
    string brand;
public:
    Electronics(string id, string name, float p, int stock, int warranty, string b) 
        : Product(id, name, p, stock), warrantyPeriod(warranty), brand(b) {}
    
    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Brand: " << brand << "\nWarranty: " << warrantyPeriod << " months" << endl;
    }
};

class Clothing : public Product {
    string size;
    string color;
    string fabricMaterial;
public:
    Clothing(string id, string name, float p, int stock, string s, string c, string fabric) 
        : Product(id, name, p, stock), size(s), color(c), fabricMaterial(fabric) {}
    
    void applyDiscount(float percent) override {
        if (color == "Summer" || color == "Winter") {
            price *= (1 - (percent + 10)/100); // Extra 10% for seasonal
        } else {
            price *= (1 - percent/100);
        }
    }
};

class FoodItem : public Product {
    string expirationDate;
    int calories;
public:
    FoodItem(string id, string name, float p, int stock, string exp, int cal) 
        : Product(id, name, p, stock), expirationDate(exp), calories(cal) {}
    
    float calculateTotalPrice(int quantity) override {
        if (quantity > 5) {
            return price * quantity * 0.9; // 10% bulk discount
        }
        return price * quantity;
    }
};

class Book : public Product {
    string author;
    string genre;
public:
    Book(string id, string name, float p, int stock, string a, string g) 
        : Product(id, name, p, stock), author(a), genre(g) {}
    
    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Author: " << author << "\nGenre: " << genre << endl;
    }
};

int main() {
    Electronics pixel("E001", "Google Pixel", 150000, 10, 12, "Google");
    Clothing shalwar("C001", "Pakistani Shalwar Kameez", 5000, 20, "M", "Summer", "Cotton");
    FoodItem basmati("F001", "Basmati Rice", 2000, 50, "2024-12-31", 350);
    Book islamicBook("B001", "Seerat-un-Nabi", 1500, 5, "Dr. Israr Ahmed", "Islamic");
    
    cout << pixel << endl;
    cout << shalwar << endl;
    
    shalwar.applyDiscount(15);
    cout << "Shalwar after discount: Rs." << shalwar.calculateTotalPrice(1) << endl;
    
    cout << "6 bags of rice cost: Rs." << basmati.calculateTotalPrice(6) << endl;
    
    cout << islamicBook << endl;
    
    cout << "Combined price: Rs." << (pixel + shalwar) << endl;
    
    return 0;
}
