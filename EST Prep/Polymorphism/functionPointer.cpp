#include<iostream>
using namespace std;

void add(int i, int j){
    cout<<i+j<<endl;
}

void subtract(int i, int j){
    cout<<i-j<<endl;
}

int main(){
    void (*ptr)(int, int);

    ptr = &add;
    ptr(1, 2);

    ptr = &subtract;
    ptr(3, 5);
}