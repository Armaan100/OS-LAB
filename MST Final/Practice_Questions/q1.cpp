#include<iostream>
using namespace std;

class Student{
    protected:
    string name;
    int roll_num;
    float marks[5];

    public:
    Student(){
        name = "Unknown";
        roll_num = 0;
        for (int i = 0; i < 5; i++) {
            marks[i] = 0.0; // Initialize marks to 0.0
        }
    }

    Student(string name, int roll_num, float m[5]){
        bool valid_marks = 1;
        for(int i=0; i<5; i++){
            if(m[i]<0 || m[i]>100){
                cout<<"Enter marks in range of 0-100"<<endl;
                valid_marks = 0;
                break;
            }
        }
        this->name = name;
        this->roll_num = roll_num;
        if(valid_marks){
            for(int i=0; i<5; i++){
                marks[i] = m[i];
            }
        }else{
            for (int i = 0; i < 5; i++) {
                marks[i] = 0.0;
            }
        }
    }

    friend float calculateTotalMarks(Student);

    void displayDetails();
};


float calculateTotalMarks(Student S){
    float total_marks = 0;

    for(int i=0; i<5; i++){
        total_marks+=S.marks[i];
    }

    return total_marks;
}

void Student::displayDetails(){
    cout<<"NAME: "<<name<<endl;
    cout<<"ROLL NO: "<<roll_num<<endl;
    cout<<"MARKS: ";
    for(int i=0; i<5; i++){
        cout<<" "<<marks[i]<<" ";
    }
    cout<<endl;
}

int main(){
    Student *ptr[3];
    string name;
    int roll_num;
    float marks[5];

    for(int i=0; i<3; i++){
        cout<<"Enter name, roll_num, s1, s2, s3, s4, s5: ";
        cin>>name>>roll_num>>marks[0]>>marks[1]>>marks[2]>>marks[3]>>marks[4];
        ptr[i] = new Student(name, roll_num, marks);
    }

    for(int i=0; i<3; i++){
        cout<<"Total Marks "<<i+1<<calculateTotalMarks(*ptr[i])<<endl;
    }

    cout<<endl;

    for(int i=0; i<3; i++){
        cout << "Details of Student " << (i + 1) << ":" << endl;
        (*ptr[i]).displayDetails();
    }

     // Cleanup: delete dynamically allocated memory
    for (int i = 0; i < 3; i++) {
        delete ptr[i]; // Free memory for each Student object
    }
}