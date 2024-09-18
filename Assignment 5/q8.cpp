#include<iostream>
using namespace std;

// track different types of users
// two types of users: Student & Teacher

//this is going to be an example of Hierarchial Inheritance

//Base Class
class LibraryUser{
    protected:
    string name;
    string id;
    int contact_number;
};


//Derived Class Student
class Student: public LibraryUser{
    protected:
    string grade;

    public:
    //Construtor to initialize the Student Class yo
    Student(string name, string id, int contact_number, string grade){
        this->name = name;
        this->id = id;
        this->contact_number = contact_number;
        this->grade = grade;
    }

    void show(){
        cout<<name<<id<<contact_number<<grade<<endl;
    }
};


//Teacher Classs
class Teacher: public LibraryUser{
    protected:
    string department;

    public:
    //Constructor function to initialize the Teacher Class yo
    Teacher(string name, string id, int contact_number, string department){
        this->name = name;
        this->id = id;
        this->contact_number = contact_number;
        this->department = department;
    }

    void show(){
        cout<<name<<id<<contact_number<<department<<endl;
    }
};


int main(){
    Teacher T1 = Teacher("Badd de", "1011", 1234, "CS");
    Student S1 = Student("AG", "1211", 1920, "A+");

    T1.show();
    S1.show();
}