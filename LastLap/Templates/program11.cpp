#include<iostream>
using namespace std;

template<typename T1, typename T2>
class Pair{
    private:
    T1 first;
    T2 second;

    public:
    Pair(T1 a, T2 b){
        first = a;
        second = b;
    }

    void display() const{
        cout<<"First: "<<first<<" Second: "<<second<<endl;
    }
};


int main(){
    Pair<int, int> p1 = Pair<int, int>(10, 20);

    p1.display();
}