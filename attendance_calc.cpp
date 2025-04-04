#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;

const int MAX_SUBJECTS = 10;
const int MAX_CLASSES = 100;
const int MAX_STUDENTS = 5;

class Subject {
public:
    string name;
    string type;
    int totalClasses;
    char attendance[MAX_CLASSES];

    void inputAttendance() {
        for (int i = 0; i < totalClasses; ++i) {
            cout << "Class " << (i + 1) << " [P: Present, A: Absent, D: On Duty]: ";
            cin >> attendance[i];
        }
    }

    double getAttendancePercent() {
        int present = 0;
        for (int i = 0; i < totalClasses; ++i) {
            if (attendance[i] == 'P' || attendance[i] == 'D')
                present++;
        }
        return (present / (double)totalClasses) * 100.0;
    }

    bool isShortage() {
        return getAttendancePercent() < 75.0;
    }
};

class Student {
public:
    string name;
    double cgpa;
    int subjectCount;
    Subject subjects[MAX_SUBJECTS];

    void inputData() {
        cout << "Enter name: ";
        cin >> ws;
        getline(cin, name);

        cout << "Enter CGPA: ";
        cin >> cgpa;

        cout << "Enter number of subjects: ";
        cin >> subjectCount;

        for (int i = 0; i < subjectCount; ++i) {
            cout << "Subject " << (i + 1) << " name: ";
            cin >> ws;
            getline(cin, subjects[i].name);

            cout << "Type (Theory/Lab): ";
            cin >> subjects[i].type;

            cout << "Total classes held: ";
            cin >> subjects[i].totalClasses;

            subjects[i].inputAttendance();
        }
    }

    void displayReport() {
        cout << "\n=== Report for " << name << " ===\n";
        cout << fixed << setprecision(2);
        bool shortage = false;

        for (int i = 0; i < subjectCount; ++i) {
            double perc = subjects[i].getAttendancePercent();
            cout << subjects[i].name << " (" << subjects[i].type << ") => " << perc << "%";
            if (subjects[i].isShortage()) {
                cout << " [Shortage]";
                shortage = true;
            }
            cout << endl;
        }

        cout << "CGPA: " << cgpa << endl;
        if (shortage && cgpa <= 9.0)
            cout << "Status: DEBARRED\n";
        else
            cout << "Status: ELIGIBLE\n";
    }
};

void predictAttendance() {
    cout << "\n--- Attendance Predictor ---\n";
    int attended, totalSoFar, totalPlanned;
    cout << "Enter number of classes conducted so far: ";
    cin >> totalSoFar;
    cout << "Enter number of classes attended (P or D): ";
    cin >> attended;
    cout << "Enter total number of classes planned: ";
    cin >> totalPlanned;

    if (attended > totalSoFar || totalSoFar > totalPlanned) {
        cout << "Invalid input.\n";
        return;
    }

    double currentPercent = (attended / (double)totalSoFar) * 100.0;
    cout << fixed << setprecision(2);
    cout << "Current Attendance: " << currentPercent << "%\n";

    int remaining = totalPlanned - totalSoFar;

    // Solve inequality:
    // (attended + x) / totalPlanned >= 0.75
    // x is the number of classes to be attended out of remaining
    int minRequired = (int)ceil(0.75 * totalPlanned - attended);

    if (minRequired <= remaining) {
        cout << "You must attend at least " << minRequired << " out of " << remaining << " remaining classes.\n";
    } else {
        cout << "It's NOT POSSIBLE to reach 75%. You can reach max: ";
        int maxPossible = attended + remaining;
        double maxPercent = (maxPossible / (double)totalPlanned) * 100.0;
        cout << maxPercent << "% if you attend all remaining.\n";
    }
}

int main() {
    int choice;
    cout << "==============================\n";
    cout << "Attendance System\n";
    cout << "1. Student Attendance Entry\n";
    cout << "2. Predict Attendance\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int n;
        cout << "Enter number of students (max " << MAX_STUDENTS << "): ";
        cin >> n;

        if (n > MAX_STUDENTS) {
            cout << "Too many students. Exiting.\n";
            return 0;
        }

        Student students[MAX_STUDENTS];

        for (int i = 0; i < n; ++i) {
            cout << "\n--- Student " << (i + 1) << " ---\n";
            students[i].inputData();
        }

        cout << "\n******** Final Attendance Summary ********\n";
        for (int i = 0; i < n; ++i) {
            students[i].displayReport();
            cout << "---------------------------------------\n";
        }

    } else if (choice == 2) {
        predictAttendance();
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
