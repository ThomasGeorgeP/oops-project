
// This is the class_metrics.h

#include <iostream>
#include <string>
using namespace std;

class class_metrics {
private:
    string name;
    float cgpa;

public:
    void input(int index) {
        cout << "\nEnter name of student " << index + 1 << ": ";
        getline(cin, name);

        while (true) {
            cout << "Enter CGPA of " << name << ": ";
            cin >> cgpa;
            if (cgpa >= 0 && cgpa <= 10) break;
            cout << "CGPA must be between 0 and 10. Please enter again.\n";
        }

        cin.ignore(); // clear newline
    }

    float getCgpa() const {
        return cgpa;
    }

    string getName() const {
        return name;
    }

    static void run() {
        int totalStudents;

        while (true) {
            cout << "\n\nEnter number of students: ";
            cin >> totalStudents;
            cout<<"\n\n";
            if (totalStudents > 0) break;
            cout << "Number of students must be greater than zero.\n";
        }

        cin.ignore(); 

        class_metrics all[100];
        class_metrics top[100];
        
        int topCount = 0;
        float totalCgpa = 0, highestCgpa = 0;

        for (int i = 0; i < totalStudents; i++) {
            all[i].input(i);
            float cg = all[i].getCgpa();
            totalCgpa += cg;

            if (i == 0 || cg > highestCgpa) {
                highestCgpa = cg;
                topCount = 1;
                top[0] = all[i];
            } else if (cg == highestCgpa) {
                top[topCount] = all[i];
                topCount++;
            }
        }

        cout << "\nStudent(s) with highest CGPA:\n";
        for (int i = 0; i < topCount; i++) {
            cout << "Name: " << top[i].getName() << ", CGPA: " << top[i].getCgpa() << endl;
        }

        float avgCgpa = totalCgpa / totalStudents;
        cout << "\nAverage CGPA: " << avgCgpa << endl;
    }
};