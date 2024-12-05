#include<iostream>
using namespace std;

template<typename T>
class woDeVector{
    T *arr;
    int size;

    public:
    woDeVector(int s){
        this->size = s;
        arr = new T[size];
    }

    void setValue(T arg, int index){
        if(index<size)
            arr[index] = arg;
        else    
            cout<<"Out of bounds"<<endl;
    }

    void getValue(int index){
        if(index<size)
            cout<<arr[index]<<endl;
        else    
            cout<<"Out of bounds"<<endl;
    }
};
int main(){
    woDeVector<char> x(10);
    x.setValue('c', 3);
    x.setValue('a', 5);
    x.getValue(5);
}