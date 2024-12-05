#include<iostream>
using namespace std;

//Base Class
class BC{
    public:
    int b;
    void show(){
        cout<<"b ="<<b<<endl;
    }
};

//Derived Class
class DC: public BC{
    public:
    int d;
    void show(){
        cout<<"b = "<<b<<endl;
        cout<<"d = "<<d<<endl;
    }
};

int main(){
    BC *bptr;   //base pointer
    BC base;
    bptr = &base;    //base address

    bptr->b = 100;
    bptr->show();

    DC derived;
    bptr = &derived;    //address of derived object
    bptr->b = 20;
    //bptr->d = 200;  //won't work
    bptr->show();
}

/*
C++ permits a base pointer to point to any object derived from the base, the pointer cannot be directly used to access all the members of the serived class. We may have to use another pointer declared as pointer to the derived type.
*/