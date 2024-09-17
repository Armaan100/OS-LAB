#include<iostream>
using namespace std;

class shared{
    public:
    static int a;
};

int shared::a;

int main(){
    shared::a = 99;
    cout<<"This is initial value of of a: "<<shared::a;
    cout<<endl;
    shared x;
    cout<<"This is x.a: "<<x.a<<endl;
}