#include<iostream>
using namespace std;

class X{
    protected:
    char x='m';

    public:
    X(){
        cout<<"I have m"<<endl;
    }

    ~X(){
        cout<<"m bye"<<endl;
    }
};

class Y{
    protected:
    char y='i';

    public:
    Y(){
        cout<<"I have i"<<endl;
    }

    ~Y(){
        cout<<"i bye"<<endl;
    }
};

class Z: public X, public Y{
    protected:
    char z[2];

    public:
    Z(){
        z[0] = x;
        z[1] = y;
        cout<<"I have mixed"<<endl;
        
        cout<<z[0]<<z[1]<<endl;
    }

    ~Z(){
        cout<<z[0]<<z[1]<<" bye"<<endl;
    }
};

int main(){
    Z z;
}