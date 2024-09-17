#include<iostream>
using namespace std;

//Base Class
class member{
    string gender;
    int age;

    public:
    void get(){
        cout<<"Age: ";
        cin>>age;

        cout<<"Gender: ";
        cin>>gender;
    }

    void display(){
        cout<<"Age: "<<" "<<age<<" & "<<"Gender: "<<gender<<endl;
    }
};


//derived from member class
class stud: public member{
    string level;

    public:
    void getData(){
        get();
        cout<<"Class: ";
        cin>>level;
    }

    void display2(){
        display();
        cout<<"Level: "<<level<<endl;
    }
};


//staff classs derived from member
class staff: public member{
    float salary;

    public:
    void getData(){
        get();
        cout<<"Enter Salary: ";
        cin>>salary;
    }

    void display3(){
        display();
        cout<<"Salaray: "<<salary<<endl;
    }
};

int main(){
    staff s;
    stud std;
    s.getData();
    s.display3();

    std.getData();
    std.display2();
}
