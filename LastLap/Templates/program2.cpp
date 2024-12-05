#include<iostream>
using namespace std;

template<typename T>
void swapValues(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

int main(){
    int a = 10;
    int b = 20;
    swapValues(a, b);
    cout<<a<<b;
}