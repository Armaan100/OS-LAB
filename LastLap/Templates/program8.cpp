#include<iostream>
using namespace std;

template<class T>
class Test{
    T var;
    public:
    Test(T i){
        var = i;
    }

    T divideBy2(){
        return var/2;
    }
};

int main(){
    Test<int> t1(50);
    cout<<t1.divideBy2();
}