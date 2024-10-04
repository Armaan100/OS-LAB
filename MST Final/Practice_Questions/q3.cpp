#include<iostream>
using namespace std;

class Course{
    protected:
    int courseID;
    string courseName;
    int credits;

    static int totalCourses;

    public:
    Course(int courseID, string courseName, int credits){
        this->courseID = courseID;
        this->courseName = courseName;
        this->credits = credits;
    }

    void displayCourseDetails() {
        cout << "Course ID: " << courseID << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
    }

    static int getTotalCourse(){
        return totalCourses;
    }

    friend Course compareCredits(Course&, Course&);
};

int Course::totalCourses;

class UndergraduateCourse: public Course{
    protected:
    string level;

    public:
    UndergraduateCourse(int id, const string& name, int credits, const string level)
    : Course(id, name, credits), level(level) {}

    void displayCourseDetails();
};

void UndergraduateCourse::displayCourseDetails(){
    Course::displayCourseDetails();
    cout<<"Level: "<<level<<endl;
}


class GraduateCourse: public Course{
    protected:
    bool researchComponent;

    public:
     GraduateCourse(int id, const string name, int credits, bool researchComponent)
    : Course(id, name, credits), researchComponent(researchComponent) {}

    void displayCourseDetails();
};

void GraduateCourse::displayCourseDetails(){
    cout<<"Course ID: "<<courseID<<endl;
    cout<<"Course Name: "<<courseName<<endl;
    cout<<"Credits: "<<credits<<endl;
    cout<<"Research Component: "<<researchComponent<<endl;
}

//friend function
Course compareCredits(Course &c1, Course &c2) {
    if (c1.credits > c2.credits) {
        return c1; // This returns a copy of c1
    } else {
        return c2; // This returns a copy of c2
    }
}

int main(){

}

//OPPPPP man