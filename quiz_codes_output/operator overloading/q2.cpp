#include<iostream>
using namespace std;
 
void func(int& x) { 
cout << "Lvalue Reference: " << x << endl; 
} 
void func(int&& x) { 
cout << "Rvalue Reference: " << x << endl; 
} 
int main() { 
int a = 10; 
func(a); 
func(20); 
return 0; 
}