#include<iostream>
using namespace std;

class Tracker { 
private: 
    static int objectCount; 
public: 
    Tracker() { 
        objectCount++; 
    } 
    ~Tracker() { 
        objectCount--; 
    } 
    static int getObjectCount() { 
        return objectCount; 
    } 
}; 


int Tracker::objectCount = 0; 


void createAndDestroy() { 
    static Tracker temp1; 
} 


int main() { 
    Tracker obj1, obj2; 

    cout<< "Count 1: "<<Tracker::getObjectCount()<<endl; 

    for(int i=0;i<5;i++) 
        createAndDestroy();

    cout<<"Count 2: "<<Tracker::getObjectCount()<<endl; 
    return 0; 
} 