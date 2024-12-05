#include<iostream>
using namespace std;

class Point{
    int x, y;

    public:
    Point(int a, int b): x(a), y(b) {}

    bool operator==(Point& p) const{
        return x == p.x && y==p.y;
    }
};

int main(){
    Point p1(1, 4), p2(1, 4);
    cout<<(p1==p2?"Equal":"Not equal")<<endl;
}