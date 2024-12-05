#include <iostream> 
using namespace std; 

class MyException: public exception 
{ 
    public: MyException(){} 
    const char* what() const throw() 
    { 
        return "Defined My Own Exception"; 
    }
};

int main() { 
    try  
    { 
        throw MyException(); 
    }catch (MyException e) 
    {              
        cout<<"Caught:"<<e.what()<<endl; 
    } 
    return 0; 
} 