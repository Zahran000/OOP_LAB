#ifndef LECTURECOURSE_H
#define LECTURECOURSE_H
#include "Course.h"

class LectureCourse : public Course {
private:
    double midterm;
    double final;
    double assignments;

public:
    LectureCourse(const string& code, int creds, double mid, double fin, double assign);
    double calculateGrade() override;
    void displayInfo() override;
};

#endif