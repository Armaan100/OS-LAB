#include<iostream>
using namespace std;

class Faculty {
    int facultyID;
    string name;
    string designation;

    public:
    Faculty(){}
    Faculty(int id, string name, string designation)
    : facultyID(id), name(name), designation(designation) {}

    int getFacultyID() const {
        return facultyID;
    }

    string getName() const {
        return name;
    }

    string getDesignation() const {
        return designation;
    }

    void displayFacultyDetails() {
        cout << "ID: " << facultyID << " Name: " << name << " Designation: " << designation << endl;
    }
};

class Department {
    string departmentName;
    int numberOfFaculty;
    int capacity;
    Faculty* facultyArray;  // Single pointer for dynamic array

    public:
    Department(string name, int initialCapacity)
    : departmentName(name), numberOfFaculty(0), capacity(initialCapacity) {
        facultyArray = new Faculty[capacity];  // Allocate memory for faculty array
    }

    ~Department() {
        delete[] facultyArray;  // Clean up memory for the entire array
    }

    void addFaculty(const Faculty &newFaculty) {
        if (numberOfFaculty >= capacity) {
            // Increase capacity
            capacity *= 2;  // Double the capacity
            Faculty* newArray = new Faculty[capacity];  // Create new array

            for (int i = 0; i < numberOfFaculty; i++) {
                newArray[i] = facultyArray[i];  // Copy existing faculty data
            }
            delete[] facultyArray;  // Delete old array
            facultyArray = newArray;  // Point to the new array
        }
        facultyArray[numberOfFaculty++] = newFaculty;  // Add new faculty
    }//✅

    void removeFaculty(int facultyID) {
        for (int i = 0; i < numberOfFaculty; i++) {
            if (facultyArray[i].getFacultyID() == facultyID) {
                // Shift remaining faculty members
                for (int j = i; j < numberOfFaculty - 1; j++) {
                    facultyArray[j] = facultyArray[j + 1];
                }
                numberOfFaculty--;
                return;
            }
        }
        cout << "Faculty with ID " << facultyID << " not found" << endl;
    }//✅

    void displayDepartmentDetails() const {
        cout << "Department: " << departmentName << endl;
        cout << "Faculty Members: " << endl;
        for (int i = 0; i < numberOfFaculty; i++) {
            facultyArray[i].displayFacultyDetails();  // Display each faculty member
        }
    } //✅

    // Grant access of this class to University class
    friend class University;
};

class University {
    public:
    static void changeDepartmentName(Department &department, string newName) {
        department.departmentName = newName;
    }//✅

    static void listFacultyMembers(Department &department) {
        cout << "Faculty members from department: " << department.departmentName << endl;
        for (int i = 0; i < department.numberOfFaculty; i++) {
            department.facultyArray[i].displayFacultyDetails();
        }
    }//✅
};

int main() {
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

    return 0;
}
