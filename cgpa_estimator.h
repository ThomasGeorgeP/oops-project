#include <iostream>
#include "useful_commands.h"

using namespace std;

class cgpa_estimator{
    private:
        float current_cgpa;
        float credits_completed;
    public:
        cgpa_estimator(){};
        void calculate_cgpa(){
            current_cgpa=input("\n\nEnter current gpa",0,10);
            credits_completed=input("Enter credits completed so far",0,200);

            float gpa;
            float current_credits;

            gpa=input("Enter current gpa",0,10 );
            current_credits=input("Enter credits being completed this sem",0,27.5);

            float future_cgpa,total_credits;
            total_credits=credits_completed + current_credits;
            future_cgpa=current_cgpa*credits_completed+gpa*current_credits;
            future_cgpa/=total_credits;

            cout<<"Expected CGPA: "<<future_cgpa<<"\n\n";
        }

};