#include<iostream>
using namespace std;

class Master{
    protected:
    string name, code;

    public:
    Master(string name, string code){
        this->name = name;
        this->code = code;
    }
};

class Account: virtual public Master{
    protected:
    int pay;

    public:
    Account(string name, string code, int pay): Master(name, code){
        this->pay = pay;
    }
};

class Admin: public virtual Master{
    protected:
    int experience;

    public:
    Admin(string name, string code, int experience): Master(name, code){
        this->experience = experience;
    }
};

class Person: public Account, public Admin{
    public:
    //Create It
    Person(string name, string code, int experience, int pay): Master(name, code), Account(name, code, pay), Admin(name, code, experience){}

    //Update It
    void UpdatePerson(string, string, int, int);

    //Display It
    void DisplayPerson();
};

void Person::UpdatePerson(string name, string code, int experience, int pay){
    this->name = name;
    this->code = code;
    this->pay = pay;
    this->experience = experience;
}

void Person::DisplayPerson(){
    cout<<"NAME: "<<name<<"  "<<"CODE: "<<code<<"  "<<"PAY: "<<pay<<"  "<<"EXPERIENCE: "<<experience<<endl;
}

int main(){
    // Create a Person object
    Person person("Alice", "P123", 5, 3000);
    
    // Display initial details
    cout << "Initial details:" << endl;
    person.DisplayPerson();

    // Update person details
    person.UpdatePerson("Bob", "P456", 10, 5000);
    
    // Display updated details
    cout << "Updated details:" << endl;
    person.DisplayPerson();
}