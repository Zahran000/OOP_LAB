#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;

class Course {
protected:
    string courseCode;
    int credits;

public:
    Course(const string& code, int creds) : courseCode(code), credits(creds) {}
    virtual ~Course() {}
    virtual double calculateGrade() = 0;
    virtual void displayInfo() = 0;
};

#endif