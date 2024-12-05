#include <iostream> 
#include <stdexcept> 

using namespace std; 

class BaseException {}; 

class DerivedException : public BaseException {}; 

int main() { 
    try { 
        throw DerivedException(); 
    } catch (BaseException& e) { 
        cout << "Caught BaseException" << endl; 
    } catch (DerivedException& e) { 
        cout << "Caught DerivedException" << endl; 
    } 
    return 0; 
} 

//OUTPUT: Caught BaseException