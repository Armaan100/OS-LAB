#include<iostream> 
using namespace std; 
const int ARR_SIZE=10; 
class array{ 
 private:
 int arr[ARR_SIZE]; 
 public: 
  array(){ 
   for(int i=0;i<ARR_SIZE;i++)  
     arr[i]=i; 
  } 
  class RANGE{}; 
  int &operator[](int i){ 
   if(i<0||i>=ARR_SIZE) 
    throw RANGE(); 
   return arr[i]; 
  } 
}; 
int read(array &a, int index){ 
 int element; 
 try{ 
  element=a[index]; 
 } 
 catch(array::RANGE){ 
  cout<<"\n Parent passing exception"; 
  cout<<"to child to handle \n"; 
  throw; 
 } 
 return element; 
} 
int main(void){ 
 array a; 
 int index, element; 
 while(1){ 
  cout<<"enter element to referenced:\n"; 
  cin>>index; 
  try{ 
   element=read(a,index); 
   cout<<"element in array="<<element<<endl; 
  } 
  catch(array::RANGE){ 
   exit(1); 
  } 
 }}