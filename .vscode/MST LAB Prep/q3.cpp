#include<iostream>
using namespace std;

class B1{
    public:
    B1(){
        cout<<"Default Base Class B1\n";
    }
};

class B2{
    public:
    B2(){
        cout<<"Default Base Class B2\n";
    }
};

class D: public B1, virtual B2{
    public:
    D(): B1(), B2(){
        cout<<
        "Default Derived Class D\n";
    }
};

int main(){
    D d;
}
