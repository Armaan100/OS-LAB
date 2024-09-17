#include<iostream>
using namespace std;

class base{
    public:
    base(){
        cout<<"Constructing Base\n";
    }

    ~base(){
        cout<<"Destructing Base\n";
    }
};


class derived1: public base{
    public:
    derived1(){
        cout<<"Constructing Derived1\n";
    }

    ~derived1(){
        cout<<"Destructing Derived1\n";
    }
};



class derived2: public derived1{
    public:
    derived2(){
        cout<<"Constructing Derived2\n";
    }

    ~derived2(){
        cout<<"Destructing Derived2\n";
    }
};

int main(){
    derived2 ob;
}