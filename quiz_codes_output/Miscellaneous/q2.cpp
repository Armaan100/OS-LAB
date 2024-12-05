#include<iostream>
using namespace std;

class A{
    public:
    A(){
        cout<<"C: A"<<endl;
    }

    virtual ~A(){
        cout<<"D: A"<<endl;
    }
};

class B: public A{
    public:
    B(){
        cout<<"C: B"<<endl;
    }

    ~B(){
        cout<<"D: B"<<endl;
    }
};


int main(){
    A *obj = new B;
    delete obj;
}