##Task 3: Employee Salary Calculator

#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    double hoursWorked;
    double hourlyRate;
    double totalSalary;
};

int main() {
    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    Employee* employees = new Employee[numEmployees];

    for (int i = 0; i < numEmployees; ++i) {
        cout << "Enter details for employee " << i + 1 << ":\n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, employees[i].name);
        cout << "Hours Worked: ";
        cin >> employees[i].hoursWorked;
        cout << "Hourly Rate: ";
        cin >> employees[i].hourlyRate;

        employees[i].totalSalary = employees[i].hoursWorked * employees[i].hourlyRate;
    }

    cout << "\nEmployee Salary Details:\n";
    for (int i = 0; i < numEmployees; ++i) {
        cout << "Name: " << employees[i].name 
             << ", Total Salary: " << employees[i].totalSalary << endl;
    }

    delete[] employees;
    return 0;
}


