#include<iostream>
using namespace std;

class Complex{
    float x, y;

    public:
    Complex(){}

    Complex(float real, float img){
        x = real;
        y = img;
    }

    void display(){

    }

    //Operator Overloading +
    Complex operator+(Complex C){
        Complex temp;
        temp.x = this->x + C.x;
        temp.y = this->y + C.y;
        cout<<this->x<<endl;
        cout<<C.x;
        return temp;
    }
};


int main(){
    Complex C1, C2, C3;
    
    C1 = Complex(2.3, 1.4);     //explicitly calling the constructor
    C2 = Complex(1.2, 1.1);     //same as above

    C3 = C1+C2;
}

/*
🟢🟢🟢
In overloading of binary operators, the left hand operand is used to invoke the operator function 
and the right hand operand is passed as the argument
🟢🟢🟢
*/