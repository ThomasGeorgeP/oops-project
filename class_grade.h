#include <iostream>
#include <math.h>
#include "useful_commands.h"

using namespace std;

float mean(float *marks,int n){
    float sum=0;
    for(int i=0;i<n;i++){
        sum+=marks[i];
    }
    return sum/n;
}

float standard_deviation(float *marks,int n){
    float variance=0;
    float avg=mean(marks,n);

    for(int i=0;i<n;i++){
        variance+=pow((avg-marks[i]),2);
    }
    variance/=n;
    return sqrt(variance);
}

typedef struct {
    string name;
    float mark;
} student;

class class_grade{

    private:

        int number_of_students;
        float *marks;
        student *students;

        float avg;
        float SD;
        void calculate(){
            avg=mean(marks,number_of_students);
            SD=standard_deviation(marks,number_of_students);
        }
    public:
        class_grade(){}

        class_grade(int n){

            number_of_students=n;
            marks=new float[number_of_students];
            students= new student[number_of_students];
            
            for (int i=0;i<number_of_students;i++){
                cout<<"\nEnter name of student "<<i+1<<": ";
                cin.ignore();
                getline(cin,students[i].name);
                students[i].mark=input("Enter marks of "+students[i].name,0,100);
                marks[i]=students[i].mark;
            }
            
            calculate();

        }
        
        ~class_grade(){
            delete []marks;
            delete []students;
        }

        void grade_gen(){
            float s_threshold,a_threshold,b_threshold,c_threshold,d_threshold;

            s_threshold=avg+1.5f*SD;
            a_threshold=avg+0.5f*SD;
            b_threshold=avg-0.5f*SD;
            c_threshold=avg-SD;
            d_threshold=avg-1.5f*SD;

            cout<<endl<<endl;
            for (int i=0;i<number_of_students;i++){
                cout<<students[i].name<<" : ";
                if (students[i].mark>s_threshold){
                    cout<<"S";
                }
                else if (students[i].mark>a_threshold){
                    cout<<"A";
                }
                else if (students[i].mark>b_threshold){
                    cout<<"B";
                }
                else if (students[i].mark>c_threshold){
                    cout<<"C";
                }
                else if (students[i].mark>d_threshold){
                    cout<<"D";
                }
                else{
                    cout<<"FAILED ";
                }
                cout<<endl;
            }
        }
    void metrics(){
        cout<<"\n\nAverage: "<<avg<<endl;
        cout<<"Standard Deviation: "<<SD<<endl;
    }
};