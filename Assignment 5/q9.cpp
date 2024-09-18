#include<iostream>
using namespace std;

//Below is an example of Multilevel Inheritance

//Base Class
class Vehicle{
    protected:
    string make;
    string model;
    int year;

    public:
    Vehicle(){
        make="";
        model="";
        year=0;
    }

    Vehicle(string make, string model, int year){
        this->make = make;
        this->model = model;
        this->year = year;
    }
};

//Truck class
class Truck: public Vehicle{
    protected:
    int load_capacity;

    public:
    Truck(string make, string model, int year, int load_capacity): Vehicle(make, model, year){
        this->load_capacity = load_capacity;
    }
};


//Refrigerated Truck
class RefrigeratedTruck: public Truck{
    protected:
    int temp;

    public:
    RefrigeratedTruck(string make, string model, int year, int load_capacity, int temp): Truck(make, model, year, load_capacity){
        this->temp = temp;
    }

    void show(){
        cout<<make<<" "<<model<<" "<<year<<" "<<load_capacity<<" "<<temp<<endl;
    }
};


int main(){
    RefrigeratedTruck T1 = RefrigeratedTruck("xyz", "23k3", 2023, 60, 22);
    T1.show();
}