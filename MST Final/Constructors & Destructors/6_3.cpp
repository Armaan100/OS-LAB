/*
A book shop maintains the inventory of books that are being sold at the shop. The
list includes details such as author, title, price, publisher and stock position.
Whenever a customer wants a book, the sales person inputs the title and author
and the system searches the list and displays whether it is available or not. If it is
not, an appropriate message is displayed. If it is, then the system displays the
book details and requests for the number of copies required. If the requested copies
are available, the total cost of the requested copies is displayed; otherwise the
message "Required copies not in stock" is displayed.
Design a system using a class called books with suitable member functions and
constructors. Use new operator in constructors to allocate memory space required.
*/
#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
    char* title;
    char* author;
    float price;
    char* publisher;
    int stock;

public:
    // Default constructor
    Book() {
        title = nullptr;
        author = nullptr;
        publisher = nullptr;
        price = 0.0;
        stock = 0;
    }

    // Parameterized constructor
    Book(const char* title, const char* author, float price, const char* publisher, int stock) {
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
        
        this->author = new char[strlen(author) + 1];
        strcpy(this->author, author);
        
        this->price = price;

        this->publisher = new char[strlen(publisher) + 1];
        strcpy(this->publisher, publisher);

        this->stock = stock;
    }

    // Destructor
    ~Book() {
        delete[] title;
        delete[] author;
        delete[] publisher;
    }

    // Function to display book details
    void displayDetails() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Stock: " << stock << endl;
    }

    // Function to check availability
    bool isAvailable(int requiredCopies) const {
        return stock >= requiredCopies;
    }

    // Function to update stock after sale
    void sellCopies(int copies) {
        stock -= copies;
    }

    // Getter for title and author
    const char* getTitle() const {
        return title;
    }

    const char* getAuthor() const {
        return author;
    }

    float getPrice() const {
        return price;
    }
};

class BookShop {
private:
    Book* inventory;
    int size;
    int count;

public:
    // Constructor
    BookShop(int size) {
        this->size = size;
        count = 0;
        inventory = new Book[size];
    }

    // Destructor
    ~BookShop() {
        delete[] inventory;
    }

    // Function to add a book to the inventory
    void addBook(const char* title, const char* author, float price, const char* publisher, int stock) {
        if (count < size) {
            inventory[count] = Book(title, author, price, publisher, stock);
            count++;
        } else {
            cout << "Inventory full! Cannot add more books." << endl;
        }
    }

    // Function to search for a book
    void searchBook(const char* title, const char* author) {
        for (int i = 0; i < count; i++) {
            if (strcmp(inventory[i].getTitle(), title) == 0 && strcmp(inventory[i].getAuthor(), author) == 0) {
                cout << "Book found!" << endl;
                inventory[i].displayDetails();

                int requiredCopies;
                cout << "Enter number of copies required: ";
                cin >> requiredCopies;

                if (inventory[i].isAvailable(requiredCopies)) {
                    float totalCost = requiredCopies * inventory[i].getPrice();
                    cout << "Total cost: " << totalCost << endl;
                    inventory[i].sellCopies(requiredCopies);
                    cout << "Copies sold. Updated stock: " << inventory[i].isAvailable(requiredCopies) << endl;
                } else {
                    cout << "Required copies not in stock." << endl;
                }
                return;
            }
        }
        cout << "Book not available." << endl;
    }
};

int main() {
    BookShop shop(5);  // Create a shop with space for 5 books

    // Add some books to the shop
    shop.addBook("The Great Gatsby", "F. Scott Fitzgerald", 10.99, "Scribner", 5);
    shop.addBook("1984", "George Orwell", 8.99, "Secker & Warburg", 3);
    shop.addBook("To Kill a Mockingbird", "Harper Lee", 7.99, "J.B. Lippincott & Co.", 2);

    // Search for a book
    char title[50], author[50];
    cout << "Enter the title of the book: ";
    cin.ignore();
    cin.getline(title, 50);
    cout << "Enter the author of the book: ";
    cin.getline(author, 50);

    shop.searchBook(title, author);

    return 0;
}
