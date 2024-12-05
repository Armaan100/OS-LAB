#include<iostream>
using namespace std;

//base class template
template<typename T>
class Base{
    public:
    T value;
    Base(T val): value(val){}

    void show(){
        cout<<"Base value: "<<value<<endl;
    }
};

template<typename T>
class Derived: public Base<T>{
    public:
    Derived(T val): Base<T>(val){}

    void display() const{
        cout<<"Derived value: "<<this->value<<endl;
    }
};


int main(){
    Derived<int> obj(10);
    obj.show();
    obj.display();
}