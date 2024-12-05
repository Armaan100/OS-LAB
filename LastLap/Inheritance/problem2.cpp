#include<iostream>
using namespace std;

/*
Create a media management system with a base class “Media” and derived classes
"Book", "CD", and "DVD". Additionally, there should be another base class Publisher with
attributes common to all media items. Implement the following functionalities:
1. The "Media" class should have the attribute "title". Create a parameterized constructor to
initialize the attribute. Create a pure virtual member function "displayInfo()" to display the
details of the media item.
2. The "Publisher" class should have the attributes "publisherName" and "price". Create a
parameterized constructor to initialize these attributes.
3. Create a derived class "Book" that inherits from both “Media” and “Publisher”. It should have
the attribute "author" and a parameterized constructor to initialize the data members. Override
the "displayInfo()" method to display the details of the book.
21 | Page Copyright © [2024] Author(s): Dr. Suresh Chandra Raikwar and Dr. Lokendra Vishwakarma
4. Create another derived class "CD" that inherits from both "Media" and "Publisher". It should
have the attribute "artist" and a parameterized constructor. Override the "displayInfo()" method
to display the details of
the "CD".
5. Create another derived class "DVD" that inherits from both "Media" and "Publisher". It
should have the attribute "director" and a parameterized constructor. Override the
"displayInfo()" method to display the details of the "DVD".
6. Write a main function to create objects of each class and call the member functions to
display the details.
*/

// Base class: Media
class Media {
protected:
    string title;

public:
    // Parameterized constructor
    Media(const string& title) : title(title) {}

    // Pure virtual function
    virtual void displayInfo() const = 0;

    // Virtual destructor
    virtual ~Media() {}
};

// Base class: Publisher
class Publisher {
protected:
    string publisherName;
    double price;

public:
    // Parameterized constructor
    Publisher(const string& publisherName, double price) : publisherName(publisherName), price(price) {}

    // Virtual destructor
    virtual ~Publisher() {}
};

// Derived class: Book
class Book : public Media, public Publisher {
private:
    string author;

public:
    // Parameterized constructor
    Book(const string& title, const string& publisherName, double price, const string& author)
        : Media(title), Publisher(publisherName, price), author(author) {}

    // Override displayInfo
    void displayInfo() const override {
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisherName << endl;
        cout << "Price: $" << price << endl;
    }
};

class CD: public Media, public Publisher{
    private:
    string artist;

    public:
    CD(const string& title, const string& publisherName, double price, const string& artist)
    :Media(title), Publisher(publisherName, price), artist(artist){}

    void displayInfo() const {
        cout << "CD Title: " << title << endl;
        cout << "Artist: " << artist << endl;
        cout << "Publisher: " << publisherName << endl;
        cout << "Price: $" << price << endl;
    }
};


class DVD : public Media, public Publisher {
private:
    string director;

public:
    // Parameterized constructor
    DVD(const string& title, const string& publisherName, double price, const string& director)
        : Media(title), Publisher(publisherName, price), director(director) {}

    // Override displayInfo
    void displayInfo() const override {
        cout << "DVD Title: " << title << endl;
        cout << "Director: " << director << endl;
        cout << "Publisher: " << publisherName << endl;
        cout << "Price: $" << price << endl;
    }
};


int main(){
    // Create objects of each derived class
    Book book("The Great Gatsby", "Scribner", 10.99, "F. Scott Fitzgerald");
    CD cd("Thriller", "Epic Records", 9.99, "Michael Jackson");
    DVD dvd("Inception", "Warner Bros.", 14.99, "Christopher Nolan");

    // Display details of each media item
    book.displayInfo();
    cout << "--------------------------" << endl;
    cd.displayInfo();
    cout << "--------------------------" << endl;
    dvd.displayInfo();
    cout << "--------------------------" << endl;

    return 0;
}