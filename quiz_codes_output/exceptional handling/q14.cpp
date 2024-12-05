#include<iostream> 
using namespace std; 
class positive{}; 
class negative{}; 
class zero{}; 
 
void what_sign(int num) throw (positive,negative){ 
 if(num>0) 
  throw positive(); 
 else if (num<0) 
  throw negative(); 
 else 
  throw zero(); 
} 

int main(void){ 
 int num; 
 cin>>num; 
 try{ 
  what_sign(num); 
 } 
 catch(positive){ cout<<"+ve number\n"; 
 } 
 catch(negative){ cout<<"-ve number\n"; 
 } 
 catch(zero){ cout<<"0 exception\n"; 
 } 
 return 0; 
} 