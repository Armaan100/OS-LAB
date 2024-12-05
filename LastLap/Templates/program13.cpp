#include<iostream>
using namespace std;

/*
Partial specialization is only available for class templates (not function
templates) and allows us to specialize a template for a subset of its
template parameters.
*/

template<typename T, typename U>
class Pair{
    public:
    void show(){
        cout<<"General Pair"<<endl;
    }
};

//partial specialization when both types are the same
template<typename T>
class Pair<T, T>{
    public:
    void show(){
        cout<<"Specialized Pair for the same type"<<endl;
    }
};

int main(){
    Pair<int, double> p1;
    p1.show();

    Pair<int, int> p2;
    p2.show();
}