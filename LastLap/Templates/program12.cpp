#include<iostream>
using namespace std;

// class template specialization

template<typename T>
class Display{
    public:
    void show(T value){
        cout<<"General display: "<<value<<endl;
    }
};


//specialization for 'bool' type
template<>
class Display<bool>{
    public:
    void show(bool value){
        cout<<"Boolean Display: "<<value<<endl;
    }
};


int main(){
    Display<int> intDisp;
    intDisp.show(10);

    Display<bool> boolDisp;
    boolDisp.show(1);

    Display<string> sDisp;
    sDisp.show("Hiii");
}