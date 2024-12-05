#include<iostream> 
class Base{ 
    public: 
    Base(){std::cout<<"Base Constructure";} 
    ~Base(){std::cout<<"Base Destructure";} 
}; 
class Derived: public Base{ 
    public: 
    Derived(){std::cout<<"Derived Constructure";} 
    ~Derived(){std::cout<<"Derived Destructure";} 
}; 

int main(void){ 
    Base *obj=new Derived(); 
    delete obj; 
    return 0; 
} 

/*Ans:
Base Cons
Derived Cons
Base Des
*/