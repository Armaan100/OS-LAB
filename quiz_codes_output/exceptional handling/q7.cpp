#include <iostream> 
using namespace std; 
int main() { 
    try { 
        try { 
            throw exception(); 
         }catch (const char* e){              
            cout << "Caught inner exception: " <<e.what()<< endl;} //Error 
        throw "outer exception"; 
        }catch (const char* e){ 
            cout << "Caught outer exception: " << e << endl;
        }

        return 0;
}