#include<iostream>
using namespace std;

//Base Class
class base{
    public:
    void display1(){
        cout<<"Basss class Content\n";
    }
};

//Derived1 Class
class derived: public base{
    public:
    void display2(){
        cout<<"1st derived content\n";
    }
};

//derived2 class
class derived2: public derived{
    public:
    void display3(){
        cout<<"2nd Derived class content\n";
    }
};

int main(){
    derived2 D;
    D.display1();
    D.display2();
    D.display3();
}