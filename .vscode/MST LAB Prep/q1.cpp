#include<iostream>
#include<vector>
using namespace std;

class CoffeeOrder{
    private:
    static int price;

    int cream_flag;
    int milk_flag;
    int sugar_flag;
    int artificial_flag;

    public:
    CoffeeOrder(int cream_flag, int milk_flag, int sugar_flag, int artificial_flag){
        if(cream_flag == 1 && milk_flag == 1){
            milk_flag = 0;
        }

        if(sugar_flag == 1 && artificial_flag == 1){
            artificial_flag = 0;
        }

        this->cream_flag = cream_flag;
        this->milk_flag = milk_flag;
        this->sugar_flag = sugar_flag;
        this->artificial_flag = artificial_flag;

        price+=10;
    }

    //if the user indicates both milk and cream -> turn off milk and allow only cream
    //if the user indicates both sugar and artificial -> turn off artificial and allow only sugar

    static int getPrice(){
        return price;
    }

    void displayOrder(){
        if(cream_flag == 1){
            cout<<"Cream ordered\n";
        }
        if(milk_flag == 1){
            cout<<"Milk ordered\n";
        }
        if(sugar_flag == 1){
            cout<<"Sugar ordered\n";
        }
        if(artificial_flag == 1){
            cout<<"Artificial Sweetner ordered\n";
        }
    }
};

int CoffeeOrder::price = 10;

int main(){
    int max=3;
    vector<CoffeeOrder> obj_arr;

    int i=0;
    while(max--){
        printf("If you want to have more orders press 1 else 0");

        int choice;
        cout<<"Enter choice: ";
        cin>>choice;

        int c, m, s, a;
        if(choice == 1){
            cout<<"Enter c, m, s, a: ";
            cin>>c>>m>>s>>a;
            obj_arr.push_back(CoffeeOrder(c, m, s, a));
            i++;
        }else{
            break;
        }
    }

    //Okay Now Printing Time
    cout<<"-------Order History------\n";
    for(int i=0; i<obj_arr.size(); i++){
        obj_arr[i].displayOrder();
    }

    cout<<"Total price: "<<CoffeeOrder::getPrice()<<endl;
}