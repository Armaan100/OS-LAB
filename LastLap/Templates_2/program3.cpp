#include<iostream>
using namespace std;

template<typename T>
T maxValue(T a, T b){
    return (a>b)? a: b;
}

template<typename T>
class Compare{
    T a;
    T b;
    public:
    Compare(T a, T b){
        this->a = a;
        this->b = b;
    }
};

//overloaded template
template<typename T, typename Compare>
T maxValue(T a, T b, Compare C){
    return C(a, b)? a: b;
}


int main(){

}