#include<iostream>
using namespace std;
#include<vector>

class Car{
    public:
    static int totalCars;

    string model;
    int carId;
    float price;
    string type;

    public:
    Car(){
    }
    Car(string model, float price){
        carId = totalCars+1;
        this->model = model;
        this->price = price;
        totalCars+=1;
        categorizeCar();
    }

    void show(){
        cout<<"Mode: "<<model<<" "<<"Price: "<<price<<" "<<"CarId: "<<carId<<" "<<"Type: "<<type<<endl;
    }

    void categorizeCar(){
        if(price>50000){
            type = "Luxury";
        }else if(price<50000 && price>20000){
            type="Standard";
        }else if(price<20000){
            type="Economy";
        }
    }

    ~Car(){
        cout<<"In destructor, Car model: "<<model<<endl;
    }

};

int Car::totalCars = 0;

int main(){
    // vector<Car> car_obj;
    Car *ptr = new Car[3];
    
    /*
    Car* ptr[3];
    for(int i=0; i<3; i++){
        ptr[i] = new Car(model, price);
    }
    */

    string model;
    float price;
    for(int i=0; i<3; i++){
        cout<<"Enter model and price of the car: ";
        cin>>model>>price;
        ptr[i] = Car(model, price);
        ptr[i].show();
    }

    Car C2();

    delete[] ptr;

    cout<<Car::totalCars<<endl;
}

