#include <iostream>
#include "book_class.h"
#include <string>

using namespace std;

int main(){
    book a;
    
    cout<<"Enter book name: ";
    getline(cin,a.name);
    cout<<"Book name: "<<a.name<<"\n";
    return 0;
}