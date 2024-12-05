#include<iostream>
#include<exception>
#include<limits>
#include<cmath>

using namespace std;


/*
runtime_error
    range_error ->  thrown when a result of a computation is out of bound
    overflow_error  ->  thrown when an arithmeytic overflow occurs
    underflow_error ->  thrown when an aruthmetic underflow occurs
*/

//range_error
double computeLog(double x){
    if(x<=0){
        throw range_error("Logarithm fomain error: x must be positive");
    }

    return log(x);  //natural logarithm
}

//overflow_error
int multiplyLargeNumbers(int a, int b){
    if(a>0 && b>0 && a>(numeric_limits<int>::max()/b)){
        throw overflow_error("Multiplication overflow");
    }

    return a*b;
}


//underflow_error
double divideBySmallNumbers(double a, double b){
    if(b==0){
        throw underflow_error("Division underflow: Division by Zero");
    }
    return a/b;
}


int main(){
    try{
        cout<<"Logarithm of -1 "<<computeLog(-1)<<endl;
    }
    catch(range_error& e){
        cout<<"Range Error: "<<e.what()<<endl;
    }

    try{
        int a = numeric_limits<int>::max()/2;
        int b = 3;
        cout<<"Multiplication of large numbers: "<<multiplyLargeNumbers(a, b)<<endl;
    }
    catch(overflow_error& e){
        cout<<"Overflow Error: "<<e.what()<<endl;
    }

    try{
        double a = numeric_limits<double>::min();
        double b = 0;
        cout<<"Multiplication of large numbers: "<<divideBySmallNumbers(a, b)<<endl;
    }
    catch(underflow_error& e){
        cout<<"Underflow Error: "<<e.what()<<endl;
    }
}