#include <iostream> 
using namespace std; 

class Resource { 
public: 
Resource() { cout << "Resource acquired" << endl; } 
~Resource() { cout << "Resource released" << endl; }; 
};

int main() { 
    try { 
        Resource res;  // Automatic resource acquisition 
        throw runtime_error("An error occurred"); 
    } catch (exception& e) { 
        cout << "Caught exception: " << e.what() << endl; 
    } 
    return 0; 
} 