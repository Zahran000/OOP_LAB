#include "LectureCourse.h"
#include <iostream>

LectureCourse::LectureCourse(const string& code, int creds, double mid, double fin, double assign)
    : Course(code, creds), midterm(mid), final(fin), assignments(assign) {}

double LectureCourse::calculateGrade() {
    return midterm * 0.3 + final * 0.5 + assignments * 0.2;
}

void LectureCourse::displayInfo() {
    cout << "Lecture Course: " << courseCode << endl;
    cout << "Credits: " << credits << endl;
    cout << "Instructor: Talha Shahid" << endl;
    cout << "Grade: " << calculateGrade() << endl;
}