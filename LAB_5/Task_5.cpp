#include <iostream>
using namespace std;

class Doctor {
public:
    string name;
    string specialization;
    int experience;

    Doctor(string n, string s, int e) : name(n), specialization(s), experience(e) {}

    void displayDetails() {
        cout << "Name: " << name << ", Specialization: " << specialization << ", Experience: " << experience << " years" << endl;
    }
};

class Hospital {
private:
    Doctor* doctors[100]; 
    int count;

public:
    Hospital() : count(0) {}

    void addDoctor(Doctor* doctor) {
        if (count < 100) {
            doctors[count++] = doctor;
        }
    }

    void displayHospitalDetails() {
        cout << "Hospital Details:" << endl;
        for (int i = 0; i < count; ++i) {
            doctors[i]->displayDetails();
        }
    }
};

int main() {
    Doctor doctor1("Dr. Smith", "Cardiology", 10);
    Doctor doctor2("Dr. Johnson", "Neurology", 15);

    Hospital hospital;
    hospital.addDoctor(&doctor1);
    hospital.addDoctor(&doctor2);

    hospital.displayHospitalDetails();

    return 0;
}
