#include<iostream>
using namespace std;


class base{
    public:
    int i;
};

class derived1: public base{
    public:
    int j;
};

class derived2: public base{
    public:
    int k;
};

class derived3: public derived1, public derived2{
    public:
    int sum;
};



int main(){
    derived3 obj;
    obj.i = 10; // i is ambiguous
    obj.j = 30; 
    obj.k = 40;
    
    //which i is being referred to... the one in derived1 or the one derived in derived2 ???

    //Because there are two copies of the base present in object ob... there are two obj.i s'  => so, the statement is inherently ambiguous

    //There are two way to remedy -> 
    //1. Scope Resolution Operator to i and manually select one i  (in -> c_and_d_6.cpp)

    //Before that Question. What if one i needed and don't need two copies of i... just prevent two copies from being included in derived3??
    //We can do this by👇
    //2. Virtual Base Classes✅ (in c_and_d_7.cpp)

    obj.sum = obj.i + obj.j + obj.k;
    obj.sum = obj.j + obj.k;
}