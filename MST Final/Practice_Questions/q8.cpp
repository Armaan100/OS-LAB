#include<iostream>
using namespace std;

class Faculty{
    int facultyID;
    string name;
    string desgination;

    public:
    Faculty(int id, string name, string designation)
    : facultyID(id), name(name), desgination(desgination) {}

    int getFacultyID() const {
        return facultyID;
    }

    string getName() const {
        return name;
    }

    string getDesignation() const {
        return desgination;
    }

    void displayFacultyDetails(){
        cout<<"ID: "<<facultyID<<" "<<"Name: "<<name<<" "<<"Designation: "<<desgination<<endl;
    }
};

class Department{
    string departmentName;
    int numberOfFaculty;
    int capacity;
    Faculty** facultyArray;

    public:
    Department(string name, int initialCapacity)
    : departmentName(name), numberOfFaculty(0), capacity(initialCapacity) {
        facultyArray = new Faculty*[capacity];  //Alow dynamic memoery for the faculty array
    }

    ~Department(){
        for(int i=0; i<numberOfFaculty; i++){
            delete facultyArray[i];
        }
        delete[] facultyArray;
    }

    void addFaculty(Faculty &newFaculty){
        if(numberOfFaculty >= capacity){
            //Increase capacity
            capacity *= 2; //Double the capacity

            Faculty** newArray = new Faculty*[capacity];

            for(int i=0; i<numberOfFaculty; i++){
                newArray[i] = facultyArray[i];  //copy existing faculty
            }
            delete[] facultyArray;  //delete old array
            facultyArray = newArray; //point to newaRRAY
        }
        facultyArray[numberOfFaculty++] = new Faculty(newFaculty);
    }

    void removeFaculty(int facultyID){
        for(int i=0; i<numberOfFaculty; i++){
            if(facultyArray[i]->getFacultyID() == facultyID){
                delete facultyArray[i]; //free memory for the faculty being removed
                //shift remaining
                for(int j=i; j<numberOfFaculty-1; j++){
                    facultyArray[j] = facultyArray[j+1];
                }
                numberOfFaculty--;
                return;
            }
        }
        cout<<"Faculty with ID "<<facultyID<<" not found"<<endl;
    }

    void displayDepartmentDetails() const {
        cout<<"Department: "<<departmentName<<endl;
        cout<<"Faculty Members: "<<endl;
        for(int i=0; i<numberOfFaculty; i++){
            facultyArray[i]->displayFacultyDetails();   //display each faculty
        }
    }

    //Grant Access of this class to University Class
    friend class University;
};

class University{
    public:
    void changeDepartmentName(Department &department, string newName){
        department.departmentName = newName;
    }

    void listFacultyMembers(Department &department){
        cout<<"Faculty members from department: "<<department.departmentName<<endl;

        for(int i=0; i<department.numberOfFaculty; i++){
            department.facultyArray[i]->displayFacultyDetails();
        }
    }
};


int main(){
    Department csDepartment("Computer Science", 2);  // Initial capacity of 2

    // Adding faculty members
    csDepartment.addFaculty(Faculty(101, "Alice Smith", "Professor"));
    csDepartment.addFaculty(Faculty(102, "Bob Johnson", "Associate Professor"));
    csDepartment.addFaculty(Faculty(103, "Carol Williams", "Assistant Professor"));  // Triggers capacity increase

    // Display department details
    csDepartment.displayDepartmentDetails();

    // Remove a faculty member
    csDepartment.removeFaculty(102);  // Remove Bob Johnson
    cout << "After removing a faculty member:" << endl;
    csDepartment.displayDepartmentDetails();

    // Use University class to manage department details
    University::changeDepartmentName(csDepartment, "Software Engineering");
    cout << "After changing department name:" << endl;
    csDepartment.displayDepartmentDetails();

    University::listFacultyMembers(csDepartment);
}