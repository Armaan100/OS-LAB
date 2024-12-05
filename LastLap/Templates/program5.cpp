#include<iostream>
using namespace std;

template<typename T, int size>
void show(T a){
    cout<<a<<size;
}

int main(){
    show<std::string, 10>("helllo");
}