#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string name;
    float salary;

public:
    Employee(string n, float s) : name(n), salary(s) {}

    void displayDetails() {
        cout << "Name: " << name << ", Salary: " << salary << endl;
    }
};

class Manager : public Employee {
private:
    float bonus;

public:
    Manager(string n, float s, float b) : Employee(n, s), bonus(b) {}

    void displayDetails() {
        cout << "Name: " << name << ", Salary: " << salary << ", Bonus: " << bonus << endl;
    }
};

int main() {
    
    string name;
    float salary, bonus;

    cout << "Enter managerr name: ";
    cin >> name;
    cout << "Enter managgeer salary: ";
    cin >> salary;
    cout << "Enter manaaager bonus: ";
    cin >> bonus;

    Manager manager(name, salary, bonus);
    manager.displayDetails();

    return 0;
}
