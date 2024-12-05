#include<iostream>
using namespace std;

class Course{
    protected:
    int courseId;
    string courseName;
    int credits;
    static int totalCourses;

    public:
    Course(int courseId, string courseName, int credits){
        this->courseId = courseId;
        this->courseName = courseName;

        if(credits>=0)
            this->credits = credits;
        else 
            this->credits = 0;
        totalCourses++;
    }

    // Member function to display course details
    virtual void displayCourseDetails() const {
        cout << "Course ID: " << courseId << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
    }

    //Static function to get total number of courses
    static int getTotalCourses() {
        return totalCourses;
    }

    friend Course* compareCredits(Course&, Course&);

        // Virtual destructor
    virtual ~Course() {
        totalCourses--;
    }
};

int Course::totalCourses = 0;

class UndergraduateCourse: public Course{
    string level;

    public:
    UndergraduateCourse(int courseId, string courseName, int credits, string level):
    Course(courseId, courseName, credits), level(level) {} 
    
    void displayCourseDetails() const override{
        cout << "Course ID: " << courseId << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
        cout << "Level: " << level << endl;
    }
};


class GraduateCourse: public Course{
    bool researchComponent;

    public:
    GraduateCourse(int courseId, string courseName, int credits, bool researchComponent):
    Course(courseId, courseName, credits), researchComponent(researchComponent) {}

    void displayCourseDetails() const{
        cout << "Course ID: " << courseId << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
        // cout << "Level: " << level << endl;
        cout << "Research Component: " << (researchComponent ? "Yes" : "No") << endl;
    }

};

/*
Implement a friend function compareCredits(Course& c1, Course& c2) that compares the
credits of two courses and returns the course with more credits. If the credits are equal, return
either course
*/
// Friend function to compare credits
Course* compareCredits(Course& c1, Course& c2) {
    if (c1.credits >= c2.credits) {
        return &c1;
    } else {
        return &c2;
    }
}

int main(){
    UndergraduateCourse UGC1 = UndergraduateCourse(101, "Operating System", 4, "Intermediate");
    GraduateCourse GC1 = GraduateCourse(1401, "Deep Learning", 5, 1);
    Course* C1 = &UGC1;
    Course* C2 = &GC1;
    C1->displayCourseDetails();

    Course* C3 = compareCredits(UGC1, GC1);
    C3->displayCourseDetails();
}