#ifndef STUDENT_H
#define STUDENT_H

#include "Grade.h"
#include <string>
#include <vector>
using namespace std;

class Student {

public:
    string name;
    vector<Grade> grades;

    Student(string n);

    double getAverage();

    int numAssignments();

    void getInfo();

    void addGrade(Grade x);

    int highestGrade();
    int lowestGrade();

    string letterGrade(double score);
    string averageLetterGrade();
};

#endif