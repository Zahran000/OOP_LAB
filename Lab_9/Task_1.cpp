#include <iostream>
#include <string>
using namespace std;

class Patient {
protected:
    string name;
    string id;

public:
    Patient(const string& name, const string& id) : name(name), id(id) {}
    virtual ~Patient() {}

    virtual void displayTreatment() const = 0;
    virtual double calculateCost() const = 0;
};

class InPatient : public Patient {
private:
    int daysAdmitted;
    double dailyRate;

public:
    InPatient(const string& name, const string& id, int days, double rate)
        : Patient(name, id), daysAdmitted(days), dailyRate(rate) {}

    void displayTreatment() const override {
        cout << "InPatient Treatment Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Days Admitted: " << daysAdmitted << endl;
        cout << "Daily Rate: $" << dailyRate << endl;
        cout << "Includes: Room, Nursing Care, Meals, Doctor Visits" << endl;
    }

    double calculateCost() const override {
        return daysAdmitted * dailyRate;
    }
};

class OutPatient : public Patient {
private:
    int numProcedures;
    double procedureCost;

public:
    OutPatient(const string& name, const string& id, int procedures, double cost)
        : Patient(name, id), numProcedures(procedures), procedureCost(cost) {}

    void displayTreatment() const override {
        cout << "OutPatient Treatment Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Number of Procedures: " << numProcedures << endl;
        cout << "Cost per Procedure: $" << procedureCost << endl;
        cout << "Includes: Consultation, Tests, Minor Procedures" << endl;
    }

    double calculateCost() const override {
        return numProcedures * procedureCost;
    }
};

int main() {
    Patient* patient1 = new InPatient("John Doe", "IP123", 5, 350.0);
    Patient* patient2 = new OutPatient("Jane Smith", "OP456", 3, 120.0);

    cout << "=== Patient 1 ===" << endl;
    patient1->displayTreatment();
    cout << "Total Cost: $" << patient1->calculateCost() << endl << endl;

    cout << "=== Patient 2 ===" << endl;
    patient2->displayTreatment();
    cout << "Total Cost: $" << patient2->calculateCost() << endl << endl;

    // Clean up
    delete patient1;
    delete patient2;

    return 0;
}
