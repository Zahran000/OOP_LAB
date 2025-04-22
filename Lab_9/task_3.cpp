#include <iostream>
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

class LectureCourse : public Course {
private:
    double midtermMarks;
    double finalMarks;
    double assignmentMarks;

public:
    LectureCourse(const string& code, int creds, double mid, double fin, double assign)
        : Course(code, creds), midtermMarks(mid), finalMarks(fin), assignmentMarks(assign) {}

    double calculateGrade() override {
        return (midtermMarks * 0.3) + (finalMarks * 0.5) + (assignmentMarks * 0.2);
    }

    void displayInfo() override {
        cout << "Lecture Course: " << courseCode << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: Prof. Ali Raza" << endl;
        cout << "Midterm: " << midtermMarks << endl;
        cout << "Final: " << finalMarks << endl;
        cout << "Assignments: " << assignmentMarks << endl;
        cout << "Final Grade: " << calculateGrade() << endl;
    }
};

class LabCourse : public Course {
private:
    double labPerformance;
    double labReport;
    double vivaMarks;

public:
    LabCourse(const string& code, int creds, double labPerf, double labRep, double viva)
        : Course(code, creds), labPerformance(labPerf), labReport(labRep), vivaMarks(viva) {}

    double calculateGrade() override {
        return (labPerformance * 0.4) + (labReport * 0.4) + (vivaMarks * 0.2);
    }

    void displayInfo() override {
        cout << "Lab Course: " << courseCode << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: Dr. Fatima Sheikh" << endl;
        cout << "Lab Performance: " << labPerformance << endl;
        cout << "Lab Report: " << labReport << endl;
        cout << "Viva: " << vivaMarks << endl;
        cout << "Final Grade: " << calculateGrade() << endl;
    }
};

int main() {
    Course* courses[2];
    
    courses[0] = new LectureCourse("CS101", 3, 85.5, 92.0, 88.5);
    courses[1] = new LabCourse("CS102L", 1, 90.0, 87.5, 85.0);

    cout << "University of Punjab - Course Results\n";
    cout << "-----------------------------------\n";
    for (int i = 0; i < 2; i++) {
        courses[i]->displayInfo();
        cout << "-----------------------------------\n";
    }

    for (int i = 0; i < 2; i++) {
        delete courses[i];
    }

    return 0;
}
