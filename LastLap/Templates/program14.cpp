#include<iostream>
using namespace std;

/*
Variadic templates allow a template to accept an arbitrary number of
template parameters. This is useful for functions like printf-style
functions or containers that handle multiple elements of varying
types.
*/

template<typename T>
void print(T value){
    cout<<value<<endl;
}

template<typename T, typename... Args>
void print(T value, Args... arg){
    cout<<value<<" ";
    print(arg...);  //recursive call with reduced argument pack
}

int main(){
    print("hello", 1, 2);
}