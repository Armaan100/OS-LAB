#include<iostream>
using namespace std;


class CoffeeOrder{
    private:
    static float price_coffee;
    static int total_orders;

    bool cream_flag, milk_flag, sugar_flag, artifical_flag;

    public:
    void receiveOrder(bool, bool, bool, bool);

    void displayOrder();

    static float getTotalPrice();
    static int getTotalOrders();
};

int CoffeeOrder::getTotalOrders(){
    return total_orders;
}

float CoffeeOrder::getTotalPrice(){
    return price_coffee;
}

float CoffeeOrder::price_coffee;
int CoffeeOrder::total_orders;

void CoffeeOrder::receiveOrder(bool setCream, bool setMilk, bool setSugar, bool setArtifical){
    //milk+cream => milk off, cream only yes
    //sugar+artificial => artifical off, only sugar
    if(setMilk and setCream){
        milk_flag = 0;
        cream_flag = sugar_flag = artifical_flag = 1;
    }else if(setSugar && setArtifical){
        artifical_flag = 0;
        sugar_flag = cream_flag = milk_flag = 1;
    }else{
        cream_flag = milk_flag = artifical_flag = sugar_flag = 1;
    }

    price_coffee+=1.25;
    total_orders+=1;
}

void CoffeeOrder::displayOrder(){
    cout<<"Cream: "<<cream_flag<<endl;
    cout<<"Milk: "<<milk_flag<<endl;
    cout<<"Sugar: "<<sugar_flag<<endl;
    cout<<"Artificial: "<<artifical_flag<<endl;
}

int main(){
    int total_orders = 0;
    CoffeeOrder *ptr = new CoffeeOrder[10];

    bool cream, artificial, sugar, milk;

    for(int i=0; i<10; i++){
        cout<<"If order nhi krna 0 dabaye nhi toh 1: "<<endl;
        bool choice;
        cin>>choice;
        if(choice){
            cout<<"Enter cream, milk, sugar, artificial: ";
            cin>>cream>>milk>>sugar>>artificial;
            ptr[i].receiveOrder(cream, milk, sugar, artificial);
            total_orders++;
        }else{
            break;
        }
    }

    for(int i=0; i<total_orders; i++){
        ptr[i].displayOrder();
    }

    cout<<"\nTotal price: "<<CoffeeOrder::getTotalPrice()<<endl;
    cout<<"Total Orders: "<<CoffeeOrder::getTotalOrders()<<endl;
}