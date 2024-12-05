#include<iostream>
using namespace std;

class Vehicle{
    public:
    virtual void type() = 0;
};

class LandVehicle: public Vehicle
{
private:
    /* data */
public:
    void type(){
        cout<<"LandVehicle yo"<<endl;
    }

    virtual void land(){
        cout<<"Milk"<<endl;
    }
};

class ElectricCar: public LandVehicle{
    public:
    void type(){
        cout<<"Electrubuzz"<<endl;
    }

    void land(){
        cout<<"land yes"<<endl;
    }

    void charge(){
        cout<<"True"<<endl;
    }
};

int main(){
     ElectricCar myElectricCar;

    // Call methods through a Vehicle* pointer
    Vehicle* vPtr = &myElectricCar;
    vPtr->type();
    vPtr->land(); // Error: Vehicle class does not have land() method
    // vPtr->charge(); // Error: Vehicle class does not have charge() method

    // Call methods through a LandVehicle* pointer
    LandVehicle* lPtr = &myElectricCar;
    lPtr->type();
    lPtr->land();
    // lPtr->charge(); // Error: LandVehicle class does not have charge() method

    // Call methods through an ElectricCar* pointer
    ElectricCar* ePtr = &myElectricCar;
    ePtr->type();
    ePtr->land();
    ePtr->charge();

    return 0;
}
