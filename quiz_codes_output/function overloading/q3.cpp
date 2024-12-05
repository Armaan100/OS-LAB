#include<iostream>

using namespace std;

class A{
    public:
    A(){
        cout<<"A Called"<<endl;
    }

    virtual void speak(){
        cout<<"Speak"<<endl;
    }
};

class B: public A{
    public:
    B(){
        cout<<"B Called"<<endl;
    }

    void speak(){
        cout<<"speak 2"<<endl;
    }

    void tell(){
        cout<<"Tell 2"<<endl;
    }
};

int main(){
    A *obj = new B;
    obj->speak();
    // obj->tell();
}