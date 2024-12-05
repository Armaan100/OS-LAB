#include<iostream>

using namespace std;

class space{
    int x, y, z;

    public:
    void getData(int a, int b, int c){
        x=a; y=b; z=c;
    }

    void display(){
        cout<<x<<y<<z<<endl;
    }

    //overload unary minus
    void operator -(){
        x=-x;
        y=-y;
        z=-z;
    }
};


int main(){
    space S;
    S.getData(10, 20, -30);
    S.display();

    -S;
    S.display();    
}