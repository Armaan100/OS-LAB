#include<iostream>
using namespace std;

class Base{
    int i, j;
    
    public:
    void set(int a, int b){
        i=a; j=b;
    }

    void show(){
        cout<<i<<" "<<j<<endl;
    }
};


class Derived: public Base{
    int k;

    public:
    Derived(int x){
        k=x;
    }

    void showK(){
     cout<<k<<endl;   
    }
};

int main(){
    Derived obj(3);
    obj.set(1, 2);
    obj.show();
    obj.showK();
}