#include <iostream>

#ifndef USEFUL_COMMANDS_H
#define USEFUL_COMMANDS_H

using namespace std;

float input(string message="",float lower_limit=0,float higher_limit=0){ //to take in input between a certain range and call again if invalid
    
    float user_input;
    cout<<message<<": ";
    cin>>user_input;
    
    if ( lower_limit!=higher_limit&&(user_input<lower_limit||user_input>higher_limit)){

        cout<<"Invalid Input Please enter again. Number should be between "<<lower_limit<<" and "<<higher_limit<<" \n";
        return input(message,lower_limit,higher_limit);

    }
    return user_input;
}
#endif