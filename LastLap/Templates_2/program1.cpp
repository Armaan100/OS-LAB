#include<iostream>
using namespace std;

//base template
template<typename T>
T sum(T arg){
    return arg;
}

//vardiac template
template<typename T, typename... args>
T sum(T first, args... rest){
    return first+sum(rest...);
}

int main(){
    cout<<sum(1, 2, 3, 4, 5)<<endl;
}