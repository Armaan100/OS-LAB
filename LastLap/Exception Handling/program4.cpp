#include<iostream>
using namespace std;

class Resource{
    public:
    Resource(){
        cout<<"Resource acquired"<<endl;
    }    
    ~Resource(){
        cout<<"Resource released"<<endl;
    }
};

void process(){
    Resource res;
    throw runtime_error("Procesing error");
}

int main(){
    try{
        process();
    }catch(runtime_error& e){
        cout<<"Exception caught"<<e.what()<<endl;
    }
}