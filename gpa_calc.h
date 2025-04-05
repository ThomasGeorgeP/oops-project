#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;

class Course {
protected:
    int n;
    float credits[20];
    char grades[20];

    bool isValidCredit(float c) {
        if (c == 1.5f) return true;
        if (c <= 0) return false;
        return floor(c) == c;
    }

public:
    void inputCourses() {
        cout << "Enter number of courses: ";
        cin >> n;

        while (cin.fail() || n <= 0 || n > 20) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter a number between 1 and 20: ";
            cin >> n;
        }

        float totalCredits = 0;

        for (int i = 0; i < n; i++) {
            float c;
            char g;

            // Credit input
            while (true) {
                cout << "Course " << i + 1 << " - Credits: ";
                cin >> c;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input. Please enter a number.\n";
                    continue;
                }

                if (!isValidCredit(c)) {
                    cout << "Credit must be a positive integer or 1.5 only.\n";
                    continue;
                }

                if (totalCredits + c > 27.5) {
                    cout << "Total credits would exceed 27.5. Re-enter this course.\n";
                    continue;
                }

                credits[i] = c;
                totalCredits += c;
                break;
            }

            // Grade input
            while (true) {
                cout << "         Grade: ";
                cin >> g;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input. Please enter a single character.\n";
                    continue;
                }

                g = toupper(g);

                if (g != 'S' && g != 'A' && g != 'B' && g != 'C' &&
                    g != 'D' && g != 'E' && g != 'F' && g != 'N') {
                    cout << "Invalid grade entered. Try again.\n";
                    cin.ignore(1000, '\n'); // Clear any leftover
                    continue;
                }

                grades[i] = g;
                break;
            }
        }

        if (totalCredits == 0) {
            cout << "Total credits is zero. CGPA cannot be calculated.\n";
            exit(0);
        }
    }

    int getNumCourses() {
        return n;
    }

    float getCredit(int i) {
        return credits[i];
    }

    char getGrade(int i) {
        return grades[i];
    }
};

class CGPACalculator : public Course {
private:
    int gradePoint(char grade) {
        switch (grade) {
            case 'S': return 10;
            case 'A': return 9;
            case 'B': return 8;
            case 'C': return 7;
            case 'D': return 6;
            case 'E': return 5;
            case 'F':
            case 'N': return 0;
            default: return -1;
        }
    }

public:
    void calculateCGPA() {
        float totalCredits = 0;
        float totalPoints = 0;

        for (int i = 0; i < getNumCourses(); i++) {
            int gp = gradePoint(getGrade(i));
            totalCredits += getCredit(i);
            totalPoints += getCredit(i) * gp;
        }

        float cgpa = totalPoints / totalCredits;
        cout << "Your CGPA is: " << cgpa << endl;
    }
};

int main() {
    CGPACalculator calc;
    calc.inputCourses();
    calc.calculateCGPA();
    return 0;
}