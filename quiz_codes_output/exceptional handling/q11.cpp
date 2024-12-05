#include <iostream> 
#include <exception> 
using namespace std; 
class MyException: public exception 
{ 
 public:  
 
    MyException(){
        cout<<"Created Own Exception Object"<<endl; cout<<what();
    } 
  
    virtual const char* what() const throw(){ 
        return "Defined My Own Exception"; 
    } 
}; 

int main(){ 
    try{   
        MyException e; 
    }catch(MyException &e){              
        cout<<"Caught:"<<e.what()<<endl; 
    }   //This catch will not execute as there wasn't any expection thrown yo...so, try succesfully completed yayy
    return 0;
}