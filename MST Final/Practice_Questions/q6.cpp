#include<iostream>
using namespace std;

class Vehicle{
    protected:
    static int totalVehicles;
    string make, model;
    int year;

    public:
    Vehicle(string make, string model, int year){
        this->make = make;
        this->model = model;
        this->year = year;
        totalVehicles++;
    }

    static int getTotalVehicles();

    void showDetails();
};

int Vehicle::totalVehicles = 0;

int Vehicle::getTotalVehicles(){
    return totalVehicles;
}

void Vehicle::showDetails(){
    cout<<"Make: "<<make<<endl;
    cout<<"Model: "<<model<<endl;
    cout<<"Year: "<<year<<endl;
}

class Car: public Vehicle{
    private:
    int numberOfDoors;

    public:
    Car(string make, string model, int year, int numD)
    : Vehicle(make, model, year), numberOfDoors(numD){}
    void showDetails();
};

void Car::showDetails(){
    Vehicle::showDetails();
    cout<<"Number of doors: "<<numberOfDoors<<endl;
}

class Bike: public Vehicle{
    private:
    string type;

    public:
    Bike(string make, string model, int year, string type)
    : Vehicle(make, model, year), type(type){}
    void showDetails();
};


void Bike::showDetails(){
    Vehicle::showDetails();
    cout<<"Type: "<<type<<endl;
}


class Truck: public Vehicle{
    private:
    double loadCapacity;

    public:
    Truck(string make, string model, int year, double loadCapacity)
    : Vehicle(make, model, year), loadCapacity(loadCapacity){}

    void showDetails();
};


void Truck::showDetails(){
    Vehicle::showDetails();
    cout<<"Load Capacity: "<<loadCapacity<<endl;
}

int main(){
    Car car1("Toyota", "Camry", 2022, 4);
    Bike bike1("Yamaha", "YZF-R3", 2021, "Sports");
    Truck truck1("Volvo", "FH16", 2020, 18.5);

    cout << "Car Details:" << endl;
    car1.showDetails();
    cout << endl;

    cout << "Bike Details:" << endl;
    bike1.showDetails();
    cout << endl;

    cout << "Truck Details:" << endl;
    truck1.showDetails();
    cout << endl;

    cout << "Total Vehicles: " << Vehicle::getTotalVehicles() << endl;

    return 0;
}