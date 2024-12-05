#include<iostream> 
using namespace std; 
class ClassB; 
class ClassA { 
private: 
int valueA; 
public: 
ClassA(int val) : valueA(val) {} 
friend int sum(ClassA, ClassB); 
}; 
class ClassB { 
private: 
int valueB; 
public: 
ClassB(int val) : valueB(val) {} 
friend int sum(ClassA, ClassB); 
}; 
int sum(ClassA objA, ClassB objB) { 
return objA.valueA + objB.valueB; 
} 
int main() { 
ClassA a(10); 
ClassB b(20); 
cout << "Sum: " << sum(a, b) << endl; 
return 0;
}