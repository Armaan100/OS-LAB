#include <iostream> 
using namespace std; 


class A { 
public: 
void fun(int x) { 
cout << "Class A fun(int) called: " << x << endl; 
} 
void fun(double x) { 
cout << "Class A fun(double) called: " << x << endl; 
} 
}; 
class B : public A { 
public:   
using A::fun;
void fun(string x) { 
cout << "Class B fun(string) called: " << x << endl;
} 
}; 
int main() { 
B obj; 
obj.fun(10);          
obj.fun(3.14);        
obj.fun("Hello");     
return 0; 
}