#include <iostream>
using namespace std;

class Student {
private:
    int id;
    string name;
    int* examScores;
    int numScores;  
public:
    Student(int id, const string& name, const int* scores, int numScores) {
        this->id = id;
        this->name = name;
        this->numScores = numScores;
        examScores = new int[numScores]; 
        for (int i = 0; i < numScores; ++i) {
            examScores[i] = scores[i];
        }
    }

    Student(const Student& other) {
        id = other.id;
        name = other.name;
        numScores = other.numScores;
        examScores = new int[numScores]; 
        for (int i = 0; i < numScores; ++i) {
            examScores[i] = other.examScores[i];
        }
    }


    void display() const {
        cout << "Student ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Exam Scores: ";
        for (int i = 0; i < numScores; ++i) {
            cout << examScores[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int scores1[] = {85, 90, 78};
    Student student1(542, "mmaaz", scores1, 3);
    student1.display();

    Student student2 = student1;
    student2.display();

    int scores2[] = {88, 92, 80};
    Student student3(762, "zahran", scores2, 3);
    student2 = student3; 
    student2.display();

    student1.display();

    return 0;
}
