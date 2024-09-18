#include<iostream>
using namespace std;

class c2; //forward declaration of class c2 as c1::friend void swap(c1, c2👈)

class c1{
    int a;
    public:
    c1(int x){
        a = x;
    }
    friend void swap(c1 &x, c2 &y);
    void show(){
        cout<<"c1's a: "<<a<<endl;
    }
};


class c2{
    int b;
    public:
    c2(int y){
        b=y;
    }
    friend void swap(c1 &x, c2 &y);
    void show(){
        cout<<"c2's b: "<<b<<endl;
    }
};


void swap(c1 &x, c2 &y){
    int temp = x.a;
    x.a = y.b;
    y.b = temp;
}

int main(){
    c1 obj1(10);
    c2 obj2(20);

    cout << "Before swapping:" << endl;
    obj1.show();
    obj2.show();

    swap(obj1, obj2);

    cout << "After swapping:" << endl;
    obj1.show();
    obj2.show();

    return 0;
}