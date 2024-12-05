#include <iostream> 
#include <exception> 
using namespace std; 

class MyException: public exception 
{ 
    public: MyException(){
        cout<<"Created Own Exception Object"<<endl; cout<<what();
    } 
  
    virtual const char* what() const throw(){ 
        try{  

        }catch(MyException &e){              
            cout<<"Caught:"<<what()<<endl;
        } 
        return "Defined My Own Exception"; 
    } 
}; 

int main(){ 
    MyException e; 
    return 0;
}