#include<iostream> 
using namespace std; 
class MyClass { 
private: 
int value; 
public: 
MyClass(int val) : value(val) {} 

MyClass& add(int val) { 
value += val; 
return *this; 
} 
void display() const { 
cout << "Value: " << value << endl; 
} 
};

int main() { 
MyClass obj(10); 
obj.add(5).add(10).display(); 
return 0; 
} 