#include<iostream>

template<typename T>
void Print(T value){
    std::cout<<value<<std::endl;
}

int main(){
    Print<int>(5);
    Print<std::string>("Hey");
}