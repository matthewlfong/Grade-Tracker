#include <vector>
#include <string>
#include <iostream>
#include "Student.h"
#include "GradeManager.h"

GradeManager::GradeManager() {
}

void GradeManager::addStudent(string name) {
    students.push_back(Student(name));
}


Student* GradeManager::findStudent(string name) {
    for (Student &s : students) {
        if (s.name == name) {
            return &s;
        }
    }
    return nullptr;
}

void GradeManager::showAllStudents() {
    for (Student s : students) {
        s.getInfo();
        cout << "-------------------\n";
    }
}