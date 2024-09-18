#include<iostream>
using namespace std;

class Rectangle{
    private:
    int length, breadth;
    Rectangle(int a, int b, int c){}
    
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

    ~Rectangle(){
    }
};


//Just Create An Array Of Objects

int main(){
    int max;
    cout<<"Enter the number of objects you want to create: ";
    cin>>max;

    int i=0;

    Rectangle* p = new Rectangle[max];

    while(i<max){
        p[i] = Rectangle(10, 20);
        i++;
    }

    for(int i=0; i<max; i++){
        p[i].printArea();
    }
}
