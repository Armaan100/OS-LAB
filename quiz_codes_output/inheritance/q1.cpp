#include <iostream> 
using namespace std; 
class Base { 
    public: 
    virtual void show() { 
    cout << "Base class show function\n"; 
    } 
    void display() { 
        cout << "Base class display function\n"; 
    } 
}; 

class Derived : public Base { 
    public: 
    void show() override { 
        cout << "Derived class show function\n"; 
    } 
    void display() { 
        cout << "Derived class display function\n"; 
    } 
};

void print(Base *obj) { 
    obj->show(); 
    obj->display(); 
}

int main() { 
    Derived d; 
    print(&d); 
    return 0;
} 

/*
OUTPUT:
Derived class show function
Base class display function
*/