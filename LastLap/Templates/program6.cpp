#include<iostream>
using namespace std;

template<typename T1, typename T2>
void show(T1 a, T2 b){
    cout<<a<<b<<endl;
    cout<<"muff";
}

void show(int a, int b){
    cout<<a<<b<<endl;
    cout<<"muff muff";
}


int main(){
    show("hello", "hi");
    show(1, "1");
}


