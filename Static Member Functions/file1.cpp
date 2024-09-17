/*
Q. 
*/

#include<iostream>
using namespace std;


class shared{
    static int resource;

    public:
    static int getResource(){
        if(resource){
            return 0;
        }else{
            resource = 1;
            return 1;
        }
    }

    void freeResource(){
        resource = 0;
    }
};

int shared::resource;

int main(){
    shared o1, o2;

    if(o1.getResource()){
        cout<<"1 has no resource"<<endl;
    }
    if(!shared::getResource())
        cout<<"o2 access denied"<<endl;
    
    o1.freeResource();

    if(shared::getResource()){
        cout<<"o2 has resource"<<endl;
    }
}