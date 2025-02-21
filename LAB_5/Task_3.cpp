#include <iostream>
using namespace std;

class Employee {
public:
    string name;
    string designation;

    Employee(const string& name, const string& designation)
        : name(name), designation(designation) {}
};

class Project {
public:
    string title;
    string deadline;
    Employee* employees[10]; 
    int employeeCount;

    Project(string title,string deadline) : title(title), deadline(deadline), employeeCount(0) {}

    void addEmployee(Employee* employee) {
        if (employeeCount < 10) {
            employees[employeeCount++] = employee;
        } else {
            cout << "Cannot add more employees to this project." << endl;
        }
    }

    void display() const {
        cout << "Project Title: " << title << endl;
        cout << "Deadline: " << deadline << endl;
        cout << "Assigned Employees:" << endl;
        for (int i = 0; i < employeeCount; ++i) {
            cout << employees[i]->name << " (" << employees[i]->designation << ")" << endl;
        }
    }
};

int main() {
    Employee emp1("Maaz Iqbal", "chicken");
    Employee emp2("Zahran", "Asddasdas");

    Project proj1("Website making", "2008-12-01");
    Project proj2("App Development", "2030-02-15");

    proj1.addEmployee(&emp1);
    proj1.addEmployee(&emp2);
    proj2.addEmployee(&emp2);

    cout << "Project 1 Details:" << endl;
    proj1.display();
    cout << endl;

    cout << "Project 2 Details:" << endl;
    proj2.display();

    return 0;
}
