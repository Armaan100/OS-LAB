#include<iostream>
#include<algorithm>
using namespace std;

class Product{
    protected:
    int productID;
    string name;
    int quantity;
    double price;

    public:
    Product(int id=0, string n="", int qty=0, double prc=0.0)
    : productID(id), name(n), quantity(qty), price(prc){}

    //Display product details
    void displayProductDetails() const;

    //GetProductId
    int getProductId();

    //GetProductPrice
    double getProductPrice(){
        return price;
    }
};

void Product::displayProductDetails() const{
    if(productID != 0){
        cout << "ProductID: " << productID << ", Name: " << name << ", Quantity: " << quantity << ", Price: $" << price << endl;
    }
}

int Product::getProductId(){
    return productID;
}

class Inventory{
    private:
    Product* products;
    int capacity;
    int totalProducts;

    public:
    //Initialize the inventory with the given capacity
    Inventory(int initialCapacity)
    : capacity(initialCapacity), totalProducts(0){
        //Dynamic allocation of product array
        products = new Product[capacity];
    }

    //Clean up memory using Destructor
    ~Inventory(){
        delete[] products;
    }

    //Add Product to the inventory
    void addProduct(const Product &);

    //Remove product form the inventory
    void removeProduct(int productID);

    void displayInventory();

    friend Product* findMostExpensiveProduct(const Inventory&);
};

void Inventory::displayInventory(){
    for(int i=0; i<totalProducts; i++){
        products[i].displayProductDetails();
    }
}

void Inventory::addProduct(const Product &newProduct){
    if(totalProducts >= capacity){
        cout<<"Capacity of the inventory is full"<<endl;
        return;
    }
    products[totalProducts++] = newProduct;
    cout<<"Successfully added product to the inventory"<<endl;
}


void Inventory::removeProduct(int productID){
    for(int i=0; i<totalProducts; i++){
        if(products[i].getProductId() == productID){
            cout<<"Product with ID "<<productID<<" successfully removed"<<endl;
            products[i] = Product();
            return;
        }
    }

    cout<<"No such product found"<<endl;
}


Product* findMostExpensiveProduct(const Inventory& inventory){
    if (inventory.totalProducts == 0) {
        cout << "No products in inventory." << endl;
        return NULL;  // Return nullptr if inventory is empty
    }


    double max_price = inventory.products[0].getProductPrice();
    for(int i=1; i<inventory.totalProducts; i++){
        max_price = (max_price, inventory.products[i].getProductPrice());
    }

    for(int i=0; i<inventory.totalProducts; i++){
        if(inventory.products[i].getProductPrice() == max_price){
            return (inventory.products+i); //or, &inventory.products[i];
        }
    }
}

int main(){
    // Create an inventory with a capacity of 5 products
    Inventory storeInventory(5);

    // Add some products to the inventory
    storeInventory.addProduct(Product(101, "Laptop", 10, 999.99));
    storeInventory.addProduct(Product(102, "Smartphone", 25, 799.99));
    storeInventory.addProduct(Product(103, "Tablet", 15, 499.99));

    // Display the current inventory
    cout << "\nCurrent Inventory:\n";
    storeInventory.displayInventory();

    // Remove a product by ID
    storeInventory.removeProduct(102);

    // Display inventory after removal
    cout << "\nAfter removing product 102:\n";
    storeInventory.displayInventory();

    // Find and display the most expensive product
    Product* mostExpensive = findMostExpensiveProduct(storeInventory);
    if (mostExpensive) {
        cout << "\nThe most expensive product is:\n";
        mostExpensive->displayProductDetails();
    }

    return 0;
}