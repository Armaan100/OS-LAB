#include<iostream>
using namespace std;

class RestaurantMeal{
    string name;
    int price;

    public:
    RestaurantMeal(){}
    
    RestaurantMeal(string name, int price){
        this->name = name;
        this->price = price;
    }
};


class HotelService{
    string service;
    int fee;
    int room_number;

    public:
    HotelService(string service, int fee, int room_number){
        this->service = service;
        this->fee = fee;
        this->room_number = room_number;
    }
};


class RoomServiceMeal: public RestaurantMeal, public HotelService{
    RoomServiceMeal(): RestaurantMeal(), HotelService("Hotel Service", 40, 9){
        
    }
};