#include<iostream>
using namespace std;

class Base{
    public:
    void display(){
        cout<<"Display Base\n";
    }

    //virtual function 
    virtual void show(){
        cout<<"Show Base\n";
    }
};

class Derived: public Base{
    public:
    void display(){
        cout<<"Display Derived\n";
    }

    void show(){
        cout<<"Show Derived\n";
    }
};


int main(){
    Base B; //base object created

    Derived D;  //derived object created

    Base *bptr; //pointer to base class

    cout<<"\nbptr points to base\n";
    bptr=&B;    //base pointer pointing to base object

    bptr->display();
    bptr->show();

    bptr=&D;    //base pointer pointing to derived class object

    bptr->display();
    bptr->show();
}