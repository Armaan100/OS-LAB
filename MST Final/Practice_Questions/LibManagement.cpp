#include<iostream>
using namespace std;

class Book{
    public:
    int id;
    string title;
    string author;
    int quantity;

    Book(): id(0), title(""), author(""), quantity(0) {}

    Book(int id, string title, string author, int quantity)
    :id(id), title(title), author(author), quantity(quantity) {}
};

class Member{
    public:
    int id;
    string name;
    int borrowedBooks[10];
    int borrowedCount;

    Member(): id(0), name(""), borrowedCount(0){
        for(int i=0; i<10; i++){
            borrowedBooks[i] = 0;
        }
    }

    Member(int id, string name): id(id), name(name), borrowedCount(0){
        for(int i=0; i<10; i++){
            borrowedBooks[i] = 0;
        }
    }

    void borrowBook(int bookId){
        borrowedBooks[borrowedCount++] = bookId;
    }

    void returnBook(int bookId){
        for(int i=0; i<borrowedCount; i++){
            if(borrowedBooks[i] == bookId){
                borrowedBooks[i] = borrowedBooks[--borrowedCount];
                return;
            }
        }
    }
};


class Library{
    private:
    Book* books;
    int bookCount;

    Member* members;
    int memberCount;

    public:
    Library(int maxBooks, int maxMembers){
        bookCount = 0; memberCount = 0;
        books = new Book[maxBooks];
        members = new Member[maxMembers];
    }

    //Add a new book
    void addBook(int id, string title, string author, int quantity){
        books[bookCount++] = Book(id, title, author, quantity);
    }

    //Delete a book by bookId
    void deleteBook(int id){
        for(int i=0; i<bookCount; i++){
            if(books[i].id == id){
                books[i] = books[--bookCount];  //Replace with the last book
                cout<<"Successfully deleted"<<endl;
                return;
            }
        }
        cout<<"Not found"<<endl;
    }

    // Update book information
    void updateBook(int id, string title, string author, int quantity) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == id) {
                books[i].title = title;
                books[i].author = author;
                books[i].quantity = quantity;
                cout << "Book updated.\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }


    // Search for a book by title
    void searchBook(string title) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].title == title) {
                cout << "Book found: " << books[i].title << " by " << books[i].author
                     << ", Quantity: " << books[i].quantity << endl;
                return;
            }
        }
        cout << "Book not found.\n";
    }

    // Add a new member
    void addMember(int id, string name) {
        members[memberCount++] = Member(id, name);
    }


    // Delete a member by ID
    void deleteMember(int id) {
        for (int i = 0; i < memberCount; i++) {
            if (members[i].id == id) {
                members[i] = members[--memberCount];  // Replace with last member
                cout << "Member deleted.\n";
                return;
            }
        }
        cout << "Member not found.\n";
    }

    // Search for a member by name
    void searchMember(string name) {
        for (int i = 0; i < memberCount; i++) {
            if (members[i].name == name) {
                cout << "Member found: " << members[i].name << ", ID: " << members[i].id << endl;
                return;
            }
        }
        cout << "Member not found.\n";
    }


    // Borrow a book
    void borrowBook(int memberId, int bookId) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == bookId) {
                if (books[i].quantity > 0) {
                    for (int j = 0; j < memberCount; j++) {
                        if (members[j].id == memberId) {
                            members[j].borrowBook(bookId);
                            books[i].quantity--;
                            cout << "Book borrowed successfully.\n";
                            return;
                        }
                    }
                    cout << "Member not found.\n";
                    return;
                } else {
                    cout << "Book is currently unavailable.\n";
                    return;
                }
            }
        }
        cout << "Book not found.\n";
    }


    // Return a book
    void returnBook(int memberId, int bookId) {
        for (int i = 0; i < memberCount; i++) {
            if (members[i].id == memberId) {
                members[i].returnBook(bookId);
                for (int j = 0; j < bookCount; j++) {
                    if (books[j].id == bookId) {
                        books[j].quantity++;
                        cout << "Book returned successfully.\n";
                        return;
                    }
                }
            }
        }
        cout << "Member or book not found.\n";
    }


    ~Library(){
        delete[] books;
        delete[] members;
    }
};


int main(){
    Library library(100, 50); // Max 100 books and 50 members

    // Add books
    library.addBook(1, "The Great Gatsby", "F. Scott Fitzgerald", 5);
    library.addBook(2, "1984", "George Orwell", 3);

    // Add members
    library.addMember(101, "John Doe");
    library.addMember(102, "Jane Smith");

    // Search for a book
    library.searchBook("1984");

    // Borrow a book
    library.borrowBook(101, 1);

    // Return a book
    library.returnBook(101, 1);

    // Update a book
    library.updateBook(1, "The Great Gatsby", "F. Scott Fitzgerald", 10);

    // Delete a book
    library.deleteBook(2);

    // Search for a member
    library.searchMember("John Doe");

    // Delete a member
    library.deleteMember(101);

    return 0;
}