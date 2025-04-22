#ifndef LABCOURSE_H
#define LABCOURSE_H
#include "Course.h"

class LabCourse : public Course {
private:
    double performance;
    double report;
    double viva;

public:
    LabCourse(const string& code, int creds, double perf, double rep, double viv);
    double calculateGrade() override;
    void displayInfo() override;
};

#endif