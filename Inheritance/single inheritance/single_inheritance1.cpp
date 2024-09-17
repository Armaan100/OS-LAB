#include<iostream>
using namespace std;

class Shape{
    protected:
    int width;
    int height;

    public:
    void setWidth(int w){
        width = w;
    }

    void setHeight(int h){
        height = h;
    }
};


class Rectangle: public Shape{
    public:
    int getArea(){
        return width*height;
    }
};

int main(){
    Rectangle R1;
    R1.setWidth(5);
    R1.setHeight(7);

    cout<<"Total Area: "<<R1.getArea()<< endl;
}