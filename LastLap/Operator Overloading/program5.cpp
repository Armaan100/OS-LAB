#include <iostream>
#include <string>
using namespace std;

// Base class: store_items
class store_items {
protected:
    string book_name;

public:
    // Constructor
    store_items(string name) : book_name(name) {}

    // Pure virtual function
    virtual void describe() = 0;

    // Virtual destructor
    virtual ~store_items() {}
};

// Derived class: Physics
class Physics : public store_items {
private:
    string author_name;
    int* book_numbers;
    int num_books;

public:
    // Constructor
    Physics(string name, string author, int num_books)
        : store_items(name), author_name(author), num_books(num_books) {
        book_numbers = new int[num_books];
        for (int i = 0; i < num_books; ++i) {
            book_numbers[i] = i + 1; // Example book numbers
        }
    }

    // Override describe
    void describe() {
        cout << "Physics Book: " << book_name << endl;
        cout << "Author: " << author_name << endl;
        cout << "Book Numbers: ";
        for (int i = 0; i < num_books; ++i) {
            cout << book_numbers[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~Physics() {
        delete[] book_numbers;
    }
};

// Derived class: Maths
class Maths : public store_items {
private:
    string author_name;
    int* book_numbers;
    int num_books;

public:
    // Constructor
    Maths(string name, string author, int num_books)
        : store_items(name), author_name(author), num_books(num_books) {
        book_numbers = new int[num_books];
        for (int i = 0; i < num_books; ++i) {
            book_numbers[i] = i + 1; // Example book numbers
        }
    }

    // Override describe
    void describe() {
        cout << "Maths Book: " << book_name << endl;
        cout << "Author: " << author_name << endl;
        cout << "Book Numbers: ";
        for (int i = 0; i < num_books; ++i) {
            cout << book_numbers[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~Maths() {
        delete[] book_numbers;
    }
};

// Derived class: Chemistry
class Chemistry : public store_items {
private:
    string author_name;
    int* book_numbers;
    int num_books;

public:
    // Constructor
    Chemistry(string name, string author, int num_books)
        : store_items(name), author_name(author), num_books(num_books) {
        book_numbers = new int[num_books];
        for (int i = 0; i < num_books; ++i) {
            book_numbers[i] = i + 1; // Example book numbers
        }
    }

    // Override describe
    void describe() {
        cout << "Chemistry Book: " << book_name << endl;
        cout << "Author: " << author_name << endl;
        cout << "Book Numbers: ";
        for (int i = 0; i < num_books; ++i) {
            cout << book_numbers[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~Chemistry() {
        delete[] book_numbers;
    }
};

// Derived class: Biology
class Biology : public store_items {
private:
    string author_name;
    int* book_numbers;
    int num_books;

public:
    // Constructor
    Biology(const string& name, const string& author, int num_books)
        : store_items(name), author_name(author), num_books(num_books) {
        book_numbers = new int[num_books];
        for (int i = 0; i < num_books; ++i) {
            book_numbers[i] = i + 1; // Example book numbers
        }
    }

    // Override describe
    void describe(){
        cout << "Biology Book: " << book_name << endl;
        cout << "Author: " << author_name << endl;
        cout << "Book Numbers: ";
        for (int i = 0; i < num_books; ++i) {
            cout << book_numbers[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~Biology(){
        delete[] book_numbers;
    }
};

int main() {
    store_items* books[4];

    // Adding books to the store
    books[0] = new Physics("Physics Fundamentals", "Isaac Newton", 5);
    books[1] = new Maths("Advanced Mathematics", "Carl Gauss", 4);
    books[2] = new Chemistry("Organic Chemistry", "Marie Curie", 3);
    books[3] = new Biology("Biology Basics", "Charles Darwin", 6);

    // Displaying book details
    for (int i = 0; i < 4; ++i) {
        books[i]->describe();
        cout << "--------------------------" << endl;
    }

    // Deleting books (simulate purchase)
    for (int i = 0; i < 4; ++i) {
        delete books[i];
    }

    return 0;
}