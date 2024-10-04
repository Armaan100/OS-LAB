#include<iostream>
using namespace std;

class Staff{
    protected:
    string code, name;

    public:
    Staff(string code, string name){
        this->code = code;
        this->name = name;
    }
};

class Education{
    protected:
    string general_highest_q, professional_highest_q;

    public:
    Education(string a, string b){
        general_highest_q= a;
        professional_highest_q = b;
    }
};


class Officer:public Staff, public Education{
    protected:
    string grade;

    public:
    Officer(string grade, string code, string name, string general, string professional): Staff(code, name), Education(general, professional){
        this->grade = grade;
    }
};

class Teacher: public Staff, public Education{
    protected:
    string subject, publication;

    public:
    Teacher(string subject, string publication, string code, string name, string general, string professional): Staff(code, name), Education(general, professional){
        this->subject = subject;
        this->publication = publication;
    }    
};

class Typist: public Staff{
    protected:
    int speed;

    public:
    Typist(int speed, string code, string name): Staff(code, name){
        this->speed = speed;
    }
};

class Regular: public Typist{
    protected:

};

class Casual: public Typist{
    protected:
    int daily_wages;

    public:
    Casual(int daily_wages, int speed, string code, string name): Typist(speed, code, name){
        this->daily_wages = daily_wages;
    }
};



int main(){

}