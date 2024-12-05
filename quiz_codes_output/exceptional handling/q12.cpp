#include<iostream> 
using namespace std; 
const int ARR_SIZE=10; 

class array{ 
 private: 
  int *arr; 
  int size; 
 public: 
  class SIZE{}; 
  class RANGE{}; 
  array(int sizeRequest){ 
  
 if(sizeRequest<0||sizeRequest>ARR_SIZE)  
    throw SIZE(); 
   size=sizeRequest; 
   arr=new int[size]; 
  } 
  int &operator[](int i){ 
   if(i<0||i>=size) 
    throw RANGE(); 
   return arr[i]; 
  } 
}; 

int main(void){ 
 try{ 
  array a(5); 
  a[1]=10;  
  cout<<a[1]; 
   
  a[10]=6; 
  cout<<a[10]; 
   
  array b(15); 
  b[19]=23; 
  cout<<b[19]; 
 } 
 catch(array::SIZE){cout<<"size exceeds";} 
  
 catch(array::RANGE){cout<<"out of range";} 
  
  
 return 0; 
} 