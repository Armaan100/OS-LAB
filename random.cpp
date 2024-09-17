#include<iostream>
using namespace std;

class c2;

class c1{
    int status;
    
    public:
    void setStatus(int state){
        status = state;
    }

    friend int idle(c1, a, c2 b);
};

