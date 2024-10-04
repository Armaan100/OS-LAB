//Class to represent a vector
#include<iostream>
using namespace std;

class MyVector{
    private:
    int *arr;
    int iterator;
    int size;

    public:
    //create the vector
    MyVector(int size){
        this->size = size;
        arr = new int[size];
        iterator = 0;
    }

    //Enter values
    void push_back(int);

    //display vector
    void display();

    //multiply by scale
    void multiply(int);
};

void MyVector::display(){
    for(int i=0; i<iterator; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void MyVector::push_back(int value){
    arr[iterator] = value;
    iterator++; 
}

void MyVector::multiply(int value){
    for(int i=0; i<iterator; i++){
        arr[i]*=value;
    }
}

int main(){
}