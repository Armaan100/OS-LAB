#include<iostream>
using namespace std;


//Base Class
class base{
    public:
    base(){
        cout<<"Constructing base\n";
    }

    ~base(){
        cout<<"Destructing base\n";
    }
};


//Derived Class
class derived: public base{
    public:
    derived(){
        cout<<"Constructing derived\n";
    }

    ~derived(){
        cout<<"Destructing derived\n";
    }
};


int main(){
    derived obj1;
}