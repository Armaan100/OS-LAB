#include<iostream>
using namespace std;

template<typename T1, typename T2>
void displayPair(T1 a, T2 b){
    cout<<"First: "<<a<<" "<<"Second: "<<b<<endl;
}

int main(){
    displayPair(10, "hello");
}