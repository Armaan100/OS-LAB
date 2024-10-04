#include <iostream>
using namespace std;

class Master {
protected:
    string name, code;

public:
    Master(string name, string code) {
        this->name = name;
        this->code = code;
    }
};

class Account : public Master {
protected:
    int pay;

public:
    Account(string name, string code, int pay) : Master(name, code) {
        this->pay = pay;
    }
};

class Admin : public Master {
protected:
    int experience;

public:
    Admin(string name, string code, int experience) : Master(name, code) {
        this->experience = experience;
    }
};

class Person : public Account, public Admin {
public:
    // Constructor for Person class
    Person(string name, string code, int experience, int pay)
        : Account(name, code, pay), Admin(name, code, experience) {
        // No need to call Master() here, because Account and Admin will call it
    }

    // Update It
    void UpdatePerson(string name, string code, int experience, int pay);

    // Display It
    void DisplayPerson();
};

void Person::UpdatePerson(string name, string code, int experience, int pay) {
    this->name = name;  // Which name? This will create ambiguity.
    this->code = code;  // Which code? This will create ambiguity.
    this->pay = pay;
    this->experience = experience;
}

void Person::DisplayPerson() {
    // Ambiguity occurs: Which 'name' and 'code' from Account or Admin's Master?
    cout << "NAME: " << name << "  "
         << "CODE: " << code << "  "
         << "PAY: " << pay << "  "
         << "EXPERIENCE: " << experience << endl;
}

int main() {
    // Create a Person object
    Person person("Alice", "P123", 5, 3000);

    // Display initial details
    cout << "Initial details:" << endl;
    person.DisplayPerson();

    return 0;
}