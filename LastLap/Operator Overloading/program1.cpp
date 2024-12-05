#include<iostream>
using namespace std;

//to overload unary - operator

class Test{
    int x, y;

    public:
    Test(int a, int b): x(a), y(b) {}

    void operator-(){
        x=-x;
        y=-y;
    }

    void display() const{
        cout<<x<<" "<<y<<endl;
    }
};

int main(){
    Test t(10, -20);
    -t;
    t.display();
}