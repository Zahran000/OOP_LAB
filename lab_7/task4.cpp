#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string contactNumber;
    string address;
public:
    Person(string n, int a, string contact, string addr) 
        : name(n), age(a), contactNumber(contact), address(addr) {}
    
    virtual void displayInfo() {
        cout << "Name: " << name << "\nAge: " << age 
             << "\nContact: " << contactNumber << "\nAddress: " << address << endl;
    }
    
    virtual void updateInfo(string n, int a, string contact, string addr) {
        name = n;
        age = a;
        contactNumber = contact;
        address = addr;
    }
};

class Patient : public Person {
    string patientID;
    string medicalHistory;
    string doctorAssigned;
public:
    Patient(string id, string n, int a, string contact, string addr, string history, string doctor) 
        : Person(n, a, contact, addr), patientID(id), medicalHistory(history), doctorAssigned(doctor) {}
    
    void displayInfo() override {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << "\nMedical History: " << medicalHistory 
             << "\nDoctor: " << doctorAssigned << endl;
    }
};

class Doctor : public Person {
    string specialization;
    float consultationFee;
    string patientList[10];
    int patientCount;
public:
    Doctor(string n, int a, string contact, string addr, string spec, float fee) 
        : Person(n, a, contact, addr), specialization(spec), consultationFee(fee), patientCount(0) {}
    
    void displayInfo() override {
        Person::displayInfo();
        cout << "Specialization: " << specialization << "\nFee: Rs." << consultationFee << endl;
        cout << "Patients: ";
        for (int i = 0; i < patientCount; i++) {
            cout << patientList[i] << ", ";
        }
        cout << endl;
    }
    
    void addPatient(string patientName) {
        if (patientCount < 10) {
            patientList[patientCount++] = patientName;
        }
    }
};

class Nurse : public Person {
    string assignedWard;
    string shiftTimings;
public:
    Nurse(string n, int a, string contact, string addr, string ward, string shift) 
        : Person(n, a, contact, addr), assignedWard(ward), shiftTimings(shift) {}
    
    void displayInfo() override {
        Person::displayInfo();
        cout << "Ward: " << assignedWard << "\nShift: " << shiftTimings << endl;
    }
};

class Administrator : public Person {
    string department;
    float salary;
public:
    Administrator(string n, int a, string contact, string addr, string dept, float sal) 
        : Person(n, a, contact, addr), department(dept), salary(sal) {}
    
    void updateInfo(string n, int a, string contact, string addr) override {
        Person::updateInfo(n, a, contact, addr);
        cout << "Administrative record updated for " << name << endl;
    }
    
    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << "\nSalary: Rs." << salary << endl;
    }
};

int main() {
    Patient ali("P001", "Ali Raza", 35, "03001234567", "House 1, Lahore", "Diabetes", "Dr. Ahmed");
    Doctor ahmed("Dr. Ahmed Khan", 45, "03009876543", "House 2, Karachi", "Cardiology", 2000);
    Nurse sana("Sana Fatima", 28, "03005556677", "House 3, Islamabad", "Emergency", "Night Shift");
    Administrator admin("Bilal Akhtar", 40, "03001112233", "House 4, Peshawar", "HR", 100000);
    
    ahmed.addPatient("Ali Raza");
    
    ali.displayInfo();
    cout << endl;
    
    ahmed.displayInfo();
    cout << endl;
    
    sana.displayInfo();
    cout << endl;
    
    admin.displayInfo();
    admin.updateInfo("Bilal Akhtar", 41, "03001113344", "New House, Peshawar");
    admin.displayInfo();
    
    return 0;
}
