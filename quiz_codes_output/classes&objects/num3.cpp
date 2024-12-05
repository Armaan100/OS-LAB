#include<iostream> 
using namespace std;


void increment(int* x){
    std::cout<<"In *"<<endl;
    (*x)++;
} 
void increment(int& x){
    cout<<"in &"<<endl;
    x++;
}

int main(void){ 
    int a=5; 
    int *b = &a;

    increment(a);
    cout<<a<<endl;
    increment(b); 
    cout<<a<<endl;
}