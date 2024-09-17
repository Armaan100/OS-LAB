#include<iostream>
using namespace std;

class A{
    public:
    int x;
};

class B: public A{
    public:
    //constructor to initialize x in base class
    B(){
        x = 10;
    }
};

class C{
    public:
    int y;

    public:
    //Constructor to initialize y in C
    C(){
        y = 4;
    }
};

class D: public B, public C{
    //D is derived from class B and C
    public:
    void sum(){
        cout<<"Sum="<<x+y<<endl;
    }
};

int main(){
    D obj1;
    obj1.sum();
}