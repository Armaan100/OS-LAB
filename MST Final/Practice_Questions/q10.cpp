#include<iostream>
using namespace std;

class Contractor;

class ConstructionProject {
    int totalCost;
    string projectName;
    double budget;
    Contractor* contractor;  // Array to hold contractors
    int noOfContractor;

    // Friend function to calculate the total cost
    friend int calculateTotalCost(const ConstructionProject &project);

public:
    ConstructionProject(string name, double budget) : projectName(name) {
        if (budget < 0) {
            cout << "Budget cannot be negative" << endl;
            this->budget = 0;
        } else {
            this->budget = budget;
        }
        contractor = new Contractor[10];  // Dynamically allocate for 10 contractors
        noOfContractor = 0;
        totalCost = 0;
    }

    ~ConstructionProject() {
        delete[] contractor;  // Clean up dynamically allocated memory
    }

    void assignConstructor(const Contractor& C);

    void displayProjectDetails() const;
};

// Contractor class definition
class Contractor {
    int contractorID;
    string name;
    double projectCost;

public:
    Contractor() : Contractor(0, "", 0.0) {}
    Contractor(int id, string name, double cost) : contractorID(id), name(name), projectCost(cost) {}

    double getProjectCost() const {
        return projectCost;
    }

    void displayContractorDetails() const {
        cout << "Contractor ID: " << contractorID << ", Name: " << name << ", Project Cost: $" << projectCost << endl;
    }
};

// Method to assign a contractor to the project
void ConstructionProject::assignConstructor(const Contractor& C) {
    if (totalCost + C.getProjectCost() > budget) {
        cout << "Cannot assign contractor. Exceeds budget." << endl;
        return;
    }

    contractor[noOfContractor++] = C;  // Assign contractor to the array
    totalCost += C.getProjectCost();  // Update the total cost
}

// Friend function to calculate total cost of all assigned contractors
int calculateTotalCost(const ConstructionProject &project) {
    int total = 0;
    for (int i = 0; i < project.noOfContractor; i++) {
        total += project.contractor[i].getProjectCost();  // Sum up the costs
    }
    return total;
}

// Main function
int main() {
    // Create a project with a budget of $50,000
    ConstructionProject project("Bridge Construction", 50000);

    // Create contractors
    Contractor contractor1(101, "John Builders", 15000);
    Contractor contractor2(102, "Smith Construction", 20000);
    Contractor contractor3(103, "Elite Contractors", 18000);

    // Assign contractors to the project
    project.assignConstructor(contractor1);
    project.assignConstructor(contractor2);
    project.assignConstructor(contractor3);

    // Calculate and display the total cost
    int totalCost = calculateTotalCost(project);
    cout << "Total cost of assigned contractors: $" << totalCost << endl;

    return 0;
}
