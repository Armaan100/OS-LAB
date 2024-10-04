#include<iostream>
using namespace std;

class Order{
    protected:
    static int globalOrderID;  // Static member to track global order ID
    int orderID;  // Unique order ID for each order

    string customerName;
    string *itemList;
    int size;
    double totalAmount;

    public:
    Order(string customerName, string itemList[], int size){
        this->orderID = ++globalOrderID;
        this->customerName = customerName;
        this->size = size;
        totalAmount = 0.0;

        this->itemList = new string[size];
        for(int i=0; i<size; i++){
            this->itemList[i] = itemList[i];
            totalAmount+=10;
        }
    }

    friend void applyDiscount(Order &, double);

    void displayOrderDetails();

    static int getNextOrderId(){
        return globalOrderID+1;
    }

    // Destructor to deallocate memory
    ~Order() {
        delete[] itemList;
    }
};


void Order::displayOrderDetails(){
    cout<<"ORDER ID: "<<orderID<<endl;
    cout<<"NAME: "<<customerName<<endl;
    cout<<"ITEM LISt: ";
    for(int i=0; i<size; i++){
        cout<<itemList[i]<<" ";
    }
    cout<<endl;

    cout<<"TOTAL AMOUNT: "<<totalAmount<<endl;
}


//friend function
void applyDiscount(Order &obj, double discountPercentage){
    obj.totalAmount -= obj.totalAmount*(discountPercentage/100);
}

int Order::globalOrderID = 0;

int main(){
    string items[] = {"Coffee", "Tea", "Sandwich"};
    int size = sizeof(items) / sizeof(items[0]);

    Order order1("John Doe", items, size);
    order1.displayOrderDetails();

    // Apply a discount
    applyDiscount(order1, 10);
    cout << "After applying discount:" << endl;
    order1.displayOrderDetails();

    cout << "Next Order ID will be: " << Order::getNextOrderId() << endl;

    return 0;
}