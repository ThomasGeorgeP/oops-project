#include <iostream>
using namespace std;

class Attendance {
private:
    int present;
    int absent;
    int onDuty;
    int remaining;
    bool eligibleToMiss = false; // New flag

public:
    void inputData() {
        cout << "Number of classes attended: ";
        cin >> present;

        cout << "Number of classes absent: ";
        cin >> absent;

        cout << "Number of classes with OD: ";
        cin >> onDuty;

        cout << "Number of remaining classes: ";
        cin >> remaining;

        if (present < 0 || absent < 0 || onDuty < 0 || remaining < 0) {
            cout << "ERROR: Class counts cannot be negative.\n";
            exit(1);
        }
    }

    void calculateAttendance() {
        int totalConducted = present + absent + onDuty;
        int totalPlanned = totalConducted + remaining;

        double currentPercentage = ((present + onDuty) * 100.0) / totalConducted;
        double maxFuturePercentage = ((present + onDuty + remaining) * 100.0) / totalPlanned;

        cout << "Current attendance percentage: " << currentPercentage << "%\n";
        cout << "Attendance percentage if all classes attended: " << maxFuturePercentage << "%\n";

        if (maxFuturePercentage < 75.0) {
            cout << "WARNING: Even if you attend all remaining classes, your attendance will be below 75%.\n";
            cout << "Maximum number of future classes that can be skipped: 0 (Likely to be debarred)\n";
        } else {
            eligibleToMiss = true;

            int attended = present + onDuty;
            int maxSkips = 0;

            for (int miss = 0; miss <= remaining; miss++) {
                int futureAttended = remaining - miss;
                double perc = ((attended + futureAttended) * 100.0) / totalPlanned;
                if (perc >= 75.0) {
                    maxSkips = miss;
                } else {
                    break;
                }
            }

            cout << "Maximum number of future classes that can be skipped: " << maxSkips << "\n";
        }
    }

    void futureMissedOption() {
        if (!eligibleToMiss) {
            cout << "Skipping future missed option as you're not eligible to skip any classes.\n";
            return;
        }

        char choice;
        cout << "Do you want to enter number of future classes you may miss? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            int futureMiss;
            cout << "Enter number of future classes you plan to miss: ";
            cin >> futureMiss;

            if (futureMiss < 0) {
                cout << "You can't miss negative classes.\n";
                return;
            }

            if (futureMiss > remaining) {
                cout << "You can't miss more than the remaining classes.\n";
                return;
            }

            int totalPlanned = present + absent + onDuty + remaining;
            int futureAttended = remaining - futureMiss;
            double futurePercentage = ((present + onDuty + futureAttended) * 100.0) / totalPlanned;

            cout << "Expected attendance after missing " << futureMiss << " future classes: ";
            cout << futurePercentage << "%\n";

            if (futurePercentage < 75.0) {
                cout << "WARNING: Your future attendance will drop below 75%. You may get debarred from exams.\n";
            }
        }
    }
};
