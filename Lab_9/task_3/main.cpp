#include "LectureCourse.h"
#include "LabCourse.h"
#include <iostream>
using namespace std;

int main() {
    Course* courses[2];
    
    courses[0] = new LectureCourse("CS101", 3, 80, 85, 90);
    courses[1] = new LabCourse("CS102L", 1, 90, 85, 80);

    for (int i = 0; i < 2; i++) {
        courses[i]->displayInfo();
        cout << "------------------" << endl;
        delete courses[i];
    }

    return 0;
}