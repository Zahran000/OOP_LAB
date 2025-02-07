Task 6: Dynamic Memory Allocation for Student Records

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int rollNumber;
    float marks[3];
    float average;
};

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    Student* students = new Student[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, students[i].name);
        cout << "Roll Number: ";
        cin >> students[i].rollNumber;
        cout << "Enter marks for 3 subjects:\n";
        students[i].average = 0;
        for (int j = 0; j < 3; ++j) {
            cin >> students[i].marks[j];
            students[i].average += students[i].marks[j];
        }
        students[i].average /= 3;
    }

    cout << "\nStudent Records:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << "Name: " << students[i].name
             << ", Roll Number: " << students[i].rollNumber
             << ", Average Marks: " << students[i].average << endl;
    }

    delete[] students;
    return 0;
}
