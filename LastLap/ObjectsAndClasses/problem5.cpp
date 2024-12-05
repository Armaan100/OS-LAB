#include<iostream>
using namespace std;

//abstract class
class Student{
    public:
    string name;
    int age;

    //pure virtual function
    virtual void setInfo(string name, int age) = 0;

    virtual void displayInfo() const = 0;

    //virtual destructor
    virtual ~Student() {} 
};

class Science: public Student{
    private:
    string branch;

    public:
    void setInfo(string name, int age, string branch){
        this->name = name;
        this->age = age;
        this->branch = branch;
    }

    void setInfo(string name, int age)  {
        // Default branch if not provided
        setInfo(name, age, "Physics");
    }

    // Implementing displayInfo for Science
    void displayInfo() const {
        cout << "Science Student\n";
        cout << "Name: " << name << ", Age: " << age << ", Branch: " << branch << endl;
    }
};


// Derived Class: Art
class Art : public Student {
private:
    string field;

public:
    // Implementing setInfo for Art
    void setInfo(string name, int age, string field) {
        this->name = name;
        this->age = age;
        this->field = field;
    }

    // Overridden setInfo (matching base class signature)
    void setInfo(string name, int age) {
        // Default field if not provided
        setInfo(name, age, "Painting");
    }

    // Implementing displayInfo for Art
    void displayInfo() const {
        cout << "Art Student\n";
        cout << "Name: " << name << ", Age: " << age << ", Field: " << field << endl;
    }
};

// Derived Class: Commerce
class Commerce : public Student {
private:
    string specialization;

public:
    // Implementing setInfo for Commerce
    void setInfo(string name, int age, string specialization) {
        this->name = name;
        this->age = age;
        this->specialization = specialization;
    }

    // Overridden setInfo (matching base class signature)
    void setInfo(string name, int age) {
        // Default specialization if not provided
        setInfo(name, age, "Accountancy");
    }

    // Implementing displayInfo for Commerce
    void displayInfo() const {
        cout << "Commerce Student\n";
        cout << "Name: " << name << ", Age: " << age << ", Specialization: " << specialization << endl;
    }
};


int main(){
    Science sci;
    Art art;
    Commerce comm;

    Student* students[3];

    /*
    // Array of Student pointers
    Student* students[3];

    // Dynamically allocating derived class objects
    students[0] = new Science();
    students[1] = new Art();
    students[2] = new Commerce();
    */


   
    students[0] = &sci;
    students[1] = &art;
    students[2] = &comm;

    sci.setInfo("Alice", 20, "Biology");
    art.setInfo("Bob", 22, "Sculpture");
    comm.setInfo("Charlie", 19, "Finance");

    for(int i = 0; i < 3; ++i){
        students[i]->displayInfo();
        cout << "--------------------------" << endl;
    }

    return 0;
}