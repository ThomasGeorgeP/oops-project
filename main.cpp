#include <iostream>
#include "attendance.h"
#include "gpa_calc.h"
#include "cgpa_estimator.h"
#include "class_grade.h"

using namespace std;

int main() {
    int ch;

    do{
        cout<<"STUDENT TOOLS\n\n1.Attendance calculator\n2.GPA Calculator\n3.CGPA Calculator\n4.Class grade Calculator\n5. Exit \n";
        cin>>ch;
        switch(ch){
            case 1:{
                Attendance attendance;
                attendance.inputData();
                
            }
        }
    } while (ch!=5);

    return 0;
} 