#include<iostream>
using namespace std;

class Speedometer{
    protected:
    int speed;

    public:
    Speedometer(int speed){
        this->speed = speed;
    }
};


class FuelGauge{
    protected:
    int fuel;

    public:
    FuelGauge(int fuel){
        this->fuel = fuel;
    }
};

class Thermometer{
    protected:
    int temperature;

    public:
    Thermometer(int temperature){
        this->temperature = temperature;
    }
};

class CarDashBoard: public Speedometer, public FuelGauge, public Thermometer{
    public:
    CarDashBoard(int speed, int fuel, int temperature): Speedometer(speed), FuelGauge(fuel), Thermometer(temperature){
    }

    void display(){
        cout<<"Speed: "<<speed<<endl;
        cout<<"Fuel: "<<fuel<<endl;
        cout<<"Temperature: "<<temperature<<endl;
    }
};


int main(){
    CarDashBoard C1(20, 10, 50);
    C1.display();
}

//The above is an example of multiple inheritance