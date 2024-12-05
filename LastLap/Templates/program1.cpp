#include <iostream>
using namespace std;


//template function
template <typename T> 
T MaxElement(T x, T y){ 
    return x>y?x:y;
}

int main(){
   cout<<MaxElement (10,20)<<endl;
    cout<<MaxElement ('a','z')<<endl;
    cout<<MaxElement (-2.5,7.7)<<endl; 
}

