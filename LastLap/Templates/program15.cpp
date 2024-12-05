#include<iostream>
using namespace std;


struct A{
    int x, y;
};

struct B{
    int x;
    double y;
};

template<typename T>
void Assign_A(T a, T b, A& s1){
    s1.x = a;
    s1.y = b;
}

template<typename T, typename U>
void Assgin_B(T a, U b, B& s2){
    s2.x = a;
    s2.y = b;
}


int main(){
    A s1;
    B s2;
    Assign_A<int>(4.6, 5.7, s1);
    cout<<"Struct A: "<<s1.x<<" "<<s1.y<<endl;

    Assgin_B(3.4, 4.3, s2);
    cout<<"Struct B "<<s2.x<<" "<<s2.y<<endl;
}