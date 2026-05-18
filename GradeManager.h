#ifndef GRADEMANAGER_H
#define GRADEMANAGER_H

#include <vector>
#include <string>
#include "Student.h"

using namespace std;

class GradeManager {

private:
    vector<Student> students;

public:
    GradeManager();

    void addStudent(string name);
    Student* findStudent(string name);

    void showAllStudents();

};

#endif