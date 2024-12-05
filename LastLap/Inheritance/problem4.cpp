#include<iostream>
using namespace std;

class Order{
    static int orderId;
    string customerName;
    string* itemList;
    double totalAmout;

    public:
    Order(string name, string items[], int itemCount, double prices[]) {
        orderId++;
        customerName = name;
        itemList = new string[itemCount];
        totalAmout = 0.0;
        for (int i = 0; i < itemCount; i++) {
            itemList[i] = items[i];
            totalAmout += prices[i];
        }
    }

    void displayOrderDetails();

    static int getNextOrderId(){
        return orderId+1;
    }

    friend void applyDiscount(Order &, double);
};

void Order::displayOrderDetails(){
    cout << "Order ID: " << orderId << endl;
    cout << "Customer Name: " << customerName << endl;
    cout << "Items: ";
    for (int i = 0; itemList[i] != ""; i++) {
        cout << itemList[i] << " ";
    }
    cout << endl;
    cout << "Total Amount: $" << totalAmout << endl;
}

int Order::orderId = 0;

void applyDiscount(Order &order, double discountPercentage){
    order.totalAmout -= (discountPercentage)/100*order.totalAmout; 
}

int main(){
    string items1[] = {"item1", "item2", "item3"};
    double prices1[] = {10.0, 20.0, 30.0};
    Order order1("Customer1", items1, 3, prices1);
    order1.displayOrderDetails();
    cout << "Next Order ID: " << Order::getNextOrderId() << endl;

    string items2[] = {"item4", "item5"};
    double prices2[] = {15.0, 25.0};
    Order order2("Customer2", items2, 2, prices2);
    order2.displayOrderDetails();
    cout << "Next Order ID: " << Order::getNextOrderId() << endl;

    applyDiscount(order1, 10);
    cout << "Order 1 after discount:" << endl;
    order1.displayOrderDetails();

    applyDiscount(order2, 5);
    cout << "Order 2 after discount:" << endl;
    order2.displayOrderDetails();
}