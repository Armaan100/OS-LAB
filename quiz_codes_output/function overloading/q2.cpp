#include <iostream> 
using namespace std; 
class A 
{ public: void funA(){cout<<"A";} 
}; 
class B: public A{
 public: void funA(){cout<<"B";} 
}; 
int main() { 
    A *b=new B(); 
    b->funA(); 
    return 0;
}