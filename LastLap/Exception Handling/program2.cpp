#include<iostream>
#include<exception>
#include<vector>
#include<cmath>

using namespace std;

/*
logic_error
    invalid_argument
    domain_error
    length_error
    out_of_range
*/

void checkAge(int age){
    if(age<0){
        throw invalid_argument("Age cannot be negative");
    }else{
        cout<<"Valid age: "<<age<<endl;
    }
}

double calculateSquareRoot(double num){
    if(num<0){
        throw domain_error("Cant compute the square root of a negative number");
    }
    return sqrt(num);
}


void createLargeString(double num){
    if(num<0){
        
    }
}

int main(){

}