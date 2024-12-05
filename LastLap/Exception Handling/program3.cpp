#include<iostream>
#include<exception>
using namespace std;

int main(){
    try{
        cout<<"Outer block"<<endl;
        try{
            cout<<"Inner block"<<endl;
            throw runtime_error("error in inner block");
        }catch(exception& e){
            cout<<"Exception caught in inner block "<<e.what()<<endl;
            throw;  
        }
        cout<<"Ending outer block"<<endl;
    }catch(exception& e){
        cout<<"Exception caught in outer block"<<e.what()<<endl;
    }

}