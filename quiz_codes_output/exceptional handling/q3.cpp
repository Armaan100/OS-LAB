#include<iostream> 
using namespace std; 
class A 
{ 
 public: A(){} 
  
 A(int a){} 
  
 float f(int a, int b) 
  { 
   if(b==0) throw exception(); 
    return a/b; 
  } 
}; 
 
int main() 
{ 
 A a; 
 try{ 
  cout<<"Division="<<a.f(5,0); 
  cout<<"Hello"; 
 } 
 catch(...){ 
  cout<<"Division Error!"; 
 } 
  
 return 0; 
} 