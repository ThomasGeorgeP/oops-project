#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    float cgpa;
};

int main() {
    int totalStudents;

    while (true) {
        cout << "Enter number of students: ";
        cin >> totalStudents;
        if (totalStudents > 0) break;
        cout << "Number of students must be greater than zero.\n";
    }

    cin.ignore();

    Student allStudents[100];
    Student topStudents[100];
    int topCount = 0;
    float highestCgpa = 0, totalCgpa = 0;

    for (int i = 0; i < totalStudents; i++) {
        cout << "Enter name of student " << i + 1 << ": ";
        getline(cin, allStudents[i].name);

        float inputCgpa;
        while (true) {
            cout << "Enter CGPA of " << allStudents[i].name << ": ";
            cin >> inputCgpa;

            if (inputCgpa >= 0 && inputCgpa <= 10) break;
            cout << "CGPA must be between 0 and 10. Please enter again.\n";
        }

        allStudents[i].cgpa = inputCgpa;
        cin.ignore();

        totalCgpa += inputCgpa;

        if (i == 0 || inputCgpa > highestCgpa) {
            highestCgpa = inputCgpa;
            topCount = 1;
            topStudents[0] = allStudents[i];
        } else if (inputCgpa == highestCgpa) {
            topStudents[topCount] = allStudents[i];
            topCount++;
        }
    }

    cout << "\nStudent(s) with highest CGPA:\n";
    for (int i = 0; i < topCount; i++) {
        cout << "Name: " << topStudents[i].name << ", CGPA: " << topStudents[i].cgpa << endl;
    }

    float averageCgpa = totalCgpa / totalStudents;
    cout << "\nAverage CGPA: " << averageCgpa << endl;

    return 0;
}
