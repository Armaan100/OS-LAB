#include <iostream> 
using namespace std; 
 
class Shape { 
public: 
    virtual void draw() = 0;   
    void info() { 
        cout << "Shape info\n"; 
    } 
}; 
class Circle : public Shape { 
public: 
    void draw() override { 
        cout << "Drawing Circle\n"; 
    } 
    void info()  { 
        cout << "Circle info\n"; 
    } 
}; 

//Abstract classes no object should not be created
 
int main() { 
    Circle c; 
    // Shape s;
    Shape *shape = &c; 
    shape->draw();     
    shape->info();   
return 0; 
}