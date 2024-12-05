#include<iostream>
#include<string>

using namespace std;

class Person{
    string name;
    int age;

    public:
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }

    Person& greater(Person &x){
        if(x.age >= age)
            return x;
        else    
            return *this;
    }

    void display(){
        cout<<"Name: "<<name<<" "<<"Age: "<<age<<endl;
    }
};

int main(){
    Person P1 = Person("Milk", 20);
    Person P2("Choco", 30);

    Person P3 = P1.greater(P2);

    P3.display();

    P3 = P2.greater(P1);
    P3.display();
}