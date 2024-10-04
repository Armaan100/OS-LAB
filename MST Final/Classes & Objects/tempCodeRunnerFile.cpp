#include<iostream>
using namespace std;

class DB; //forward declaration

//Class DM(stores distance in metres and centimetres)
class DM{
    private:
    float x, y;

    public:
    DM(float x, float y){
        this->x= x;
        this->y = y;
    }

    friend void addDistance(DB, DM);
    void display() {
        cout << "Distance in meters: " << x << " meters, " << y << " centimeters" << endl;
    }
};

//class DB(stores distance in feet and inches)
class DB{
    private:
    float x, y;

    public:
    DB(float x, float y){
        this->x = x;
        this->y = y;
    }

    friend void addDistance(DB, DM);
};

//friend function
void addDistance(DB &obj1, DM &obj2){
    obj2.x = obj2.x + (obj1.x * 0.3048);
    obj2.y = obj2.y + (obj1.y * 2.54);
}

int main(){
    float meters, centimeters, feet, inches;

    cout << "Enter distance in meters and centimeters (separated by space): ";
    cin >> meters >> centimeters;
    DM dm(meters, centimeters);

    cout << "Enter distance in feet and inches (separated by space): ";
    cin >> feet >> inches;
    DB db(feet, inches);

    addDistance(db, dm);
    dm.display();

    return 0;
}