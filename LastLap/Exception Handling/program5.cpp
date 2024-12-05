#include <iostream> 
#include <stdexcept> 
using namespace std; 
void func2() { 
throw runtime_error("Exception from func2"); 
} 
void func1() { 
func2(); 
} 
int main() { 
try { 
func1(); 
} catch (const runtime_error& e) { 
cout << "Caught exception: " << e.what() << endl; 
} 
return 0; 
} 