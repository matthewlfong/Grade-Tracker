#include <iostream>
#include <limits>
#include "GradeManager.h"

using namespace std;

int main() {

    GradeManager manager;

    int choice;

    while (true) {

        cout << "\n--- Grade Tracker ---\n";
        cout << "1. Add student\n";
        cout << "2. Add grade\n";
        cout << "3. Show all students\n";
        cout << "4. Show student info\n";
        cout << "5. Show highest grade\n";
        cout << "6. Show lowest grade\n";
        cout << "7. Show letter grade\n";
        cout << "8. Exit\n";
        cout << "Choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {

            string name;

            cout << "Student name: ";
            getline(cin, name);

            manager.addStudent(name);

            cout << "Student added.\n";
        }

        else if (choice == 2) {

            string name;

            cout << "\n\nStudent name: ";
            getline(cin, name);

            Student* s = manager.findStudent(name);

            if (s == nullptr) {
                cout << "Student not found.\n";
            }

            else {

                Grade g;

                cout << "Assignment name: ";
                getline(cin, g.assignmentName);

                cout << "Score: ";
                cin >> g.score;

                s->addGrade(g);
            }
        }

        else if (choice == 3) {
            manager.showAllStudents();
        }

        else if (choice == 4) {

            string name;

            cout << "Student name: ";
            getline(cin, name);

            Student* s = manager.findStudent(name);

            if (s == nullptr) {
                cout << "Student not found.\n";
            }

            else {
                s->getInfo();
            }
        }

        else if (choice == 5) {

            string name;
            cout << "Student name: ";
            getline(cin, name);

            Student* s = manager.findStudent(name);

            if (s == nullptr) {
                cout << "Student not found.\n";
            } else {
                cout << "Highest Grade: " << s->highestGrade() << endl;
            }
        }

        else if (choice == 6) {

            string name;
            cout << "Student name: ";
            getline(cin, name);

            Student* s = manager.findStudent(name);

            if (s == nullptr) {
                cout << "Student not found.\n";
            } else {
                cout << "Lowest Grade: " << s->lowestGrade() << endl;
            }
        }

        else if (choice == 7) {

            string name;
            cout << "Student name: ";
            getline(cin, name);

            Student* s = manager.findStudent(name);

            if (s == nullptr) {
                cout << "Student not found.\n";
            } else {
                cout << "Letter Grade: " << s->averageLetterGrade() << endl;
            }
        }

        else if (choice == 8) {
            break;
        }

        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}