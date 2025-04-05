#include <iostream>
#include "attendance.h"
#include "gpa_calc.h"
#include "cgpa_estimator.h"
#include "class_grade.h"
#include "useful_commands.h"

using namespace std;

int main() {
    int ch;

    do{
        cout<<"\n\nSTUDENT TOOLS\n\n1.Attendance calculator\n2.GPA Calculator\n3.CGPA Calculator\n4.Class grade Calculator\n5.Class average and highest CGPA\n6. Exit \n\n";
        cin>>ch;
        cout<<"\n\n";
        switch(ch){
            case 1:{
                Attendance attendance;
                attendance.inputData();
                attendance.calculateAttendance();
                attendance.futureMissedOption();
                break;
            }
            case 2:{
                GPACalculator gpacalc;
                gpacalc.inputCourses();
                gpacalc.calculateCGPA();
                break;
            }
            case 3:{
                cgpa_estimator cgpacalc;
                cgpacalc.calculate_cgpa();
                break;
            }
            case 4:{
                int n;
                cout<<"Enter number of students in class: ";
                cin>>n;
                if (n>0){
                    class_grade a(n);
                    a.grade_gen();
                    a.metrics();

                }
                else{
                    cout<<"Number of students should be positive! ";
                }
                break;
            }
            case 5:{
                break;
            }
            case 6:{
                cout<<"Thank You!\n\n Exiting program..\n\n";
                break;

            }
            default:{
                cout<<"Invalid input please enter again! ";
                break;
            }
        }
    } while (ch!=6);

    return 0;
} 