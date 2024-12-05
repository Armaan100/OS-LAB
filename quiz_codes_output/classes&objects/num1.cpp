#include<iostream> 
class A{ 
    int x;  
    public: 
    A(int x):x(x){} 
    int getX() const {return x;} 
};

int main(void){ 
    A *obj=nullptr; 
    std::cout<<obj->getX()<<std::endl; 
    return 0; 
}

//ANS: Undefined behaviour