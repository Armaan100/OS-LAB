#include<vector>
#include<iostream>
using namespace std;

class Order {
private:
     // Static counter for order IDs
    static int orderID;            // Unique order ID
    string customerName;     // Customer's name
    vector<string> itemList; // List of items ordered
    double totalAmount;      // Total order amount

    // Helper method to calculate total amount based on itemList
    double calculateTotalAmount() {
        // Simple assumption: each item has a fixed price of $10 for illustration
        return itemList.size() * 10.0;
    }

public:
    // Constructor
    Order(string name, vector<string> items){
        customerName = name;
        itemList = items;
        orderID = orderID+1; // Assign order ID and increment static counter
        totalAmount = calculateTotalAmount(); // Calculate total amount
    }

    // Friend function to apply discount
    friend void applyDiscount(Order &order, double discountPercentage);

    // Method to display order details
    void displayOrderDetails() const {
        cout << "Order ID: " << orderID << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Items: ";
        for (const auto &item : itemList) {
            cout << item << " ";
        }
        cout << endl;
        cout << "Total Amount: $" << totalAmount << endl;
    }

    // Static member function to get the next order ID
    static int getNextOrderID() {
        return orderID+1;
    }
};

// Initialize static member
int Order::orderID = 0;

// Friend function definition
void applyDiscount(Order &order, double discountPercentage) {
    order.totalAmount -= (order.totalAmount * (discountPercentage / 100.0));
}

int main() {
    // Creating orders
    vector<string> items1 = {"Laptop", "Mouse"};
    vector<string> items2 = {"Phone", "Charger", "Earphones"};

    Order order1("John Doe", items1);
    Order order2("Jane Smith", items2);

    // Displaying order details
    order1.displayOrderDetails();
    cout << endl;
    order2.displayOrderDetails();

    // Applying a discount of 10% on order1
    applyDiscount(order1, 10);

    cout << "\nAfter applying discount on order1:\n";
    order1.displayOrderDetails();

    // Displaying the next available order ID
    cout << "\nNext available order ID: " << Order::getNextOrderID() << endl;

    return 0;
}