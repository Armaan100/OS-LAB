#include <iostream> 
using namespace std; 
 
int main() { 
    try { 
        try { 
            throw "Inner exception"; 
        } catch (const char* e) { 
            cout << "Caught inner exception: " << e << endl; 
        } 
        throw "milk";
    } catch (const char* e) { 
        cout << "Caught outer exception: " << e << endl; 
    } 
    return 0; 
} 