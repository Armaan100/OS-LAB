#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    int productID;
    string name;
    int quantity;
    double price;

    Product() : productID(0), name(""), quantity(0), price(0.0) {}

    Product(int productID, string name, int quantity, double price) 
        : productID(productID), name(name), quantity(quantity), price(price) {}
};

class Inventory {
    Product* products; // Dynamic array of products
    int capacity;      // Maximum number of products
    int size;          // Current number of products

    public:
    Inventory(int capacity) : capacity(capacity), size(0) {
        products = new Product[capacity];
    }

    void addProduct(const Product &newProduct){
        if(size == capacity){
            cout<<"Inventory is full"<<endl;
            return;
        }

        products[size] = newProduct;
        size++;
    }

    void removeProduct(int productId){
        bool found = false;
        for (int i = 0; i < size; ++i) {
            if (products[i].productID == productId) {
                products[i] = Product(); // Replace with a "default" product
                found = true;
                cout << "Product with ID " << productId << " has been removed.\n";
                break;
            }
        }

        if(!found){
            cout << "Product with ID " << productId << " not found.\n";
        }
    }

    // Method to display all products
    void displayInventory() const {
        if (size == 0) {
            cout << "The inventory is empty.\n";
            return;
        }
        cout << "Current Inventory:\n";
        cout << "ID\tName\t\tQuantity\tPrice\n";
        cout << "---------------------------------------------\n";
        for (int i = 0; i < size; ++i) {
            if (products[i].productID != 0) { // Ignore removed products
                cout << products[i].productID << "\t" << products[i].name << "\t\t"
                     << products[i].quantity << "\t\t" << products[i].price << endl;
            }
        }
    }

    friend Product* findTheMostExpensive(const Inventory &);

    ~Inventory(){
        // Properly deallocate dynamic memory
        delete[] products;
    }
};

Product* findTheMostExpensive(const Inventory &inventory){
    if(inventory.size == 0)
        return NULL;
    
    Product* mostExpensive = &inventory.products[0];

    for(int i=0; i<inventory.size; i++){
        if(inventory.products[i].price > mostExpensive->price){
            mostExpensive = &inventory.products[i];
        }
    }

    return mostExpensive;
}


int main(){
    Inventory inventory(5);

    // Adding products
    inventory.addProduct(Product(1, "Laptop", 10, 999.99));
    inventory.addProduct(Product(2, "Smartphone", 20, 499.99));
    inventory.addProduct(Product(3, "Tablet", 15, 299.99));
    inventory.addProduct(Product(4, "Headphones", 50, 199.99));
    inventory.addProduct(Product(5, "Smartwatch", 25, 149.99));

    // Displaying inventory
    inventory.displayInventory();

    // Removing a product
    inventory.removeProduct(3);

    // Displaying inventory after removal
    inventory.displayInventory();

    // Finding the most expensive product
    Product* mostExpensive = findTheMostExpensive(inventory);
    if (mostExpensive != NULL) {
        cout << "The most expensive product is:\n";
        cout << "ID: " << mostExpensive->productID << "\n";
        cout << "Name: " << mostExpensive->name << "\n";
        cout << "Quantity: " << mostExpensive->quantity << "\n";
        cout << "Price: " << mostExpensive->price << "\n";
    } else {
        cout << "The inventory is empty.\n";
    }

    

    return 0;
}