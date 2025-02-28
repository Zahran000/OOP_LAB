#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Teacher : virtual public Person {
protected:
    string subject;

public:
    Teacher(string n, int a, string s) : Person(n, a), subject(s) {}

    void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << ", Subject: " << subject << endl;
    }
};

class Researcher : virtual public Person {
protected:
    string researchArea;

public:
    Researcher(string n, int a, string r) : Person(n, a), researchArea(r) {}

    void displayDetails() {
        cout << "name: " << name << ", age: " << age << ", esearch Area: " << researchArea << endl;
    }
};

class Professor : public Teacher, public Researcher {
private:
    int publications;

public:
    Professor(string n, int a, string s, string r, int p) 
        : Person(n, a), Teacher(n, a, s), Researcher(n, a, r), publications(p) {}

    void displayDetails() {
        cout << "name: " << name << ", age: " << age << ", subject: " << subject 
             << ", researc Area: " << researchArea << ", publications: " << publications << endl;
    }
};

int main() {
    string name, subject, researchArea;
    int age, publications;

    cout << "Enter naame: ";
    cin >> name;
    cout << "Enter aggee: ";
    cin >> age;
    cout << "Enter subjects: ";
    cin >> subject;
    cout << "Enter researchs area: ";
    cin >> researchArea;
    cout << "Enter publications: ";
    cin >> publications;

    Professor professor(name, age, subject, researchArea, publications);
    professor.displayDetails();

    return 0;
}
