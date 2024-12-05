#include<iostream>
using namespace std;

/*
Create a class Patient and its derived classes Inpatient and Outpatient. The Patient class 
should have attributes patientID (int), name (string), age (int), and disease (string). Implement 
the following: 
a. Implement a constructor in the Patient class that initializes the patientID, name, age, and 
disease. Ensure that age is non-negative. 
b. Implement an Inpatient class that adds attributes roomNumber (int) and daysAdmitted (int). 
Implement a displayPatientDetails() function that displays all patient details, including the 
room number and days admitted. 
room number and days admitted. 
c. Implement an Outpatient class that adds an attribute visitDate (string). Implement a 
displayPatientDetails() function that displays all patient details, including the visit date. 
*/

class Patient {
protected:
    int patientID;
    string name;
    int age;
    string disease;

public:
    Patient(int id, string n, int a, string d) : patientID(id), name(n), age(a), disease(d) {
        if (age < 0) {
            throw invalid_argument("Age cannot be negative");
        }
    }

    void display() {
        cout << "Patient ID: " << patientID << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Disease: " << disease << endl;
    }
};

class Inpatient : public Patient {
    int roomNumber, daysAdmitted;
public:
    Inpatient(int id, string n, int a, string d, int roomNum, int days) : Patient(id, n, a, d), roomNumber(roomNum), daysAdmitted(days) {}

    
    void displayPatientDetails() {
        display();
        cout << "Room Number: " << roomNumber << endl;
        cout << "Days Admitted: " << daysAdmitted << endl;
    }
    
};

class Outpatient : public Patient {
    string visitDate;
public:
    Outpatient(int id, string n, int a, string d) : Patient(id, n, a, d) {}
};


int main(){

}
//same type of question as the problem3
