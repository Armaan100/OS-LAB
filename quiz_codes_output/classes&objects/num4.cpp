#include<iostream> 
class Base{ 
    public:  
    virtual void print(){std::cout<<"Base\n";} 
}; 
class Derived: public Base{ 
    public: 
    void print() {std::cout<<"Derived\n";} 
}; 
int main(){ 
    Base *b=new Derived(); 
    b->print(); 
    delete b; 
    return 0;
} 