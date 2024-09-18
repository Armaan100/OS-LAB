#include<iostream>
using namespace std;

class Rectangle{
    private:
    int length, breadth;

    public:
    Rectangle(){
        length = 0;
        breadth = 0;
    }

    Rectangle(int length, int breadth){
        this->length = length;
        this->breadth = breadth;
    }

    Rectangle(int x){
        length = breadth = x;
    }

    void printArea(){
        cout<<"Area: "<<length*breadth<<endl;
    }
};


int main(){
    //explicitly
    Rectangle R1 = Rectangle(9, 8);
    R1.printArea();

    //implicitly
    Rectangle R2(10);
    R2.printArea();

    Rectangle R3;
    R3.printArea();
}