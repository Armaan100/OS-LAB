#include <iostream> 
using namespace std; 

class A { 
public: 
virtual void show() { cout << "A class\n"; } 
}; 
class B : public virtual A { 
public: 
void show()  { cout << "B class\n"; } 
}; 
class C : public virtual A { 
public: 
void show()  { cout << "C class\n"; } 
}; 
class D : public B, public C {  
public: 
void show()  { cout << "D class\n"; 
}
};

int main(){
    D obj;
    A *ptr = &obj;
    ptr->show();
    return 0;
}

