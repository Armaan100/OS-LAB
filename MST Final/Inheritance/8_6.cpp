#include<iostream>
using namespace std;

class Staff{
    string name, code;

    public:
    Staff(string name, string code){
        this->name = name;
        this->code = code;
    }
};


class Teacher{
    protected:
    string subject, publication;
    Staff S1;

    public:
    Teacher(string name, string code, string subject, string publication): S1(name, code){
        this->subject = subject;
        this->publication = publication;
    }
};

class Officer{
    protected:
    string grade;
    Staff S1;

    public:
    Officer(string name, string code, string grade): S1(name, code){
        this->grade = grade;
    }
};


class Typist{
    protected:
    int speed;
    Staff S1;

    public:
    Typist(string name, string code, int speed): S1(name, code){
        this->speed = speed;
    }
};


int main(){

}