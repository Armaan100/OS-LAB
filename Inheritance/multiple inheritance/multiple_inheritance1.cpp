#include<iostream>
using namespace std;

class base1{
    protected:
    int x;

    public:
    void showx(){
        cout<<x<<endl;
    }
};


class base2{
    protected:
    int y;

    public:
    void showy(){
        cout<<y<<endl;
    }
};


class derived: public base1, public base2{
    public:
    void set(int i, int j){
        x=i; y=j;
    }
};

//everywhere just default constructor called yo

int main(){
    derived obj1;
    obj1.set(1, 2);
    obj1.showx();
    obj1.showy();    
}