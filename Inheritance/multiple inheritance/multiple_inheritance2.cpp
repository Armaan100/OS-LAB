#include<iostream>
using namespace std;

class Shape{
    public:
    void setWidth(int w){
        width = w;
    }
    void setHeight(int h){
        height = h;
    }

    protected:
    int width;
    int height;
};


class PaintCost{
    public:
    int getCost(int area){
        return area*70;
    }
};

//Derived Class
class Rectangle: public PaintCost, public Shape{
    public:
    int getArea(){
        return width*height;
    }
};

int main(){
    Rectangle R1;
    int area;
    R1.setWidth(5);
    R1.setHeight(4);

    area = R1.getArea();

    cout<<"Total Paint Cost: "<< R1.getCost(area)<<endl;
}