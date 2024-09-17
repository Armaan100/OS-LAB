#include<iostream>
using namespace std;

class myClass{
    int a, b;

    public:
    friend int sum(myClass x);

    void set_ab(int i, int j);
};

void myClass::set_ab(int i, int j){
    a = i;
    b = j;
}


int sum(myClass x){
    return x.a + x.b;
}

int main(){
    myClass n;
    n.set_ab(4, 5);
    cout<<sum(n);
}