#include<iostream>
using namespace std;

class Base{
    private:
    int k;

    public:
    Base(){
        cout<<"Constructor of Base Class"<<endl;
    }

    ~Base(){
        cout<<"Destructor of Base Class"<<endl;
    }
};

class Derived: private Base{
    int j;

    public:
    Derived(){
        cout<<"Derived Constructor Called"<<endl;
    }  

    ~Derived(){
        cout<<"Derived Destructor called"<<endl;
    }
};

int main(){
    Derived* p = new Derived[3];
    delete[] p;
    return 0;
}