#include <iostream> 
using namespace std; 
void func() { 
throw 42;  // Throwing an integer exception 
} 
int main() { 
try { 
func(); 
} catch (const char* e) { 
cout << "Caught a string exception: " << e << endl; 
} catch (...) { 
cout << "Caught an unknown exception" << endl; 
} 
return 0; 
} 