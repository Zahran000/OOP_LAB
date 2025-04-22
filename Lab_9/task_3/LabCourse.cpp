#include "LabCourse.h"
#include <iostream>

LabCourse::LabCourse(const string& code, int creds, double perf, double rep, double viv)
    : Course(code, creds), performance(perf), report(rep), viva(viv) {}

double LabCourse::calculateGrade() {
    return performance * 0.4 + report * 0.4 + viva * 0.2;
}

void LabCourse::displayInfo() {
    cout << "Lab Course: " << courseCode << endl;
    cout << "Credits: " << credits << endl;
    cout << "Instructor: Talha Shahid" << endl;
    cout << "Grade: " << calculateGrade() << endl;
}