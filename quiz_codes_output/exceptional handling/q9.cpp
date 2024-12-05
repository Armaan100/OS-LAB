#include <iostream> 
#include <exception> 

using namespace std; 

class MyException: public exception 
{ 
 public: MyException(){} 
  
 virtual const char* what() const 
 { 
  return "Defined My Own Exception"; 
 } 
}; 
int main() { 
 try 
 { 
        throw MyException(); 
    }catch (MyException &e){              
   cout<<"Caught:"<<e.what()<<endl;} 
    return 0; 
} 