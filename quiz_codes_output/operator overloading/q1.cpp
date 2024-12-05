#include <iostream> 
using namespace std; 
void func(int x) { 
cout << "Integer: " << x << endl; 
} 
void func(double y) { 
cout << "Double: " << y << endl; 
} 
int main() { 
func(5.0); 
}