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
    // Resolve ambiguity by specifying whether to use Account's or Admin's Master
    Account::name = name;       // Using 'name' from Account's Master
    Account::code = code;       // Using 'code' from Account's Master
    this->pay = pay;
    Admin::experience = experience;  // Using 'experience' from Admin
}

void Person::DisplayPerson() {
    // Resolve ambiguity for 'name' and 'code'
    cout << "NAME (from Account): " << Account::name << "  "
         << "CODE (from Account): " << Account::code << "  "
         << "PAY: " << pay << "  "
         << "EXPERIENCE: " << Admin::experience << endl;  // Using 'experience' from Admin
}

int main() {
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

    return 0;
}
