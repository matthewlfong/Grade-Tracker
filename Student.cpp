#include "Student.h"
#include <iostream>
#include <iomanip>

Student::Student(string n) {
    name = n;
}

double Student::getAverage() {
    if (grades.empty()) {
        return 0;
    }

    int sum = 0;

    for(Grade x : grades) {
        sum += x.score;
    }
    
    double average = (double)sum / grades.size();

    return  average;
}

int Student::numAssignments() {
    return grades.size();
}

void Student::getInfo() {
    std::cout << "Student name: " << name << endl;

    if (grades.empty()) {
            std::cout << "No grades yet" << endl;
            return;
        }

    std::cout << "Average: " << fixed << setprecision(2) << getAverage() << "%" << endl;

    for (Grade x : grades) {
        std::cout << x.assignmentName << ": " << x.score << endl;
    }

}

void Student::addGrade(Grade x) {
    if (x.score < 0 || x.score > 100) {
        std::cout << "Invalid score!" << endl;
        return;
    }
    grades.push_back(x);
}
    
int Student::highestGrade() {

    if (grades.empty()) {
        return 0;
    }

    int highest = grades[0].score;
    for (Grade x : grades) {
        if (x.score > highest) {
            highest = x.score;
        }
    }
    return highest;
}

int Student::lowestGrade() {

    if (grades.empty()) {
        return 0;
    }

    int lowest = grades[0].score;
    for (Grade x : grades) {
        if (x.score < lowest) {
            lowest = x.score;
        }
    }
    return lowest;
}

string Student::letterGrade(double score) {

    if (score >= 97) return "A+";
    else if (score >= 93) return "A";
    else if (score >= 90) return "A-";
    else if (score >= 87) return "B+";
    else if (score >= 83) return "B";
    else if (score >= 80) return "B-";
    else if (score >= 77) return "C+";
    else if (score >= 73) return "C";
    else if (score >= 70) return "C-";
    else if (score >= 67) return "D+";
    else if (score >= 63) return "D";
    else if (score >= 60) return "D-";
    else return "F";
}

string Student::averageLetterGrade() {
    return letterGrade(getAverage());
}
