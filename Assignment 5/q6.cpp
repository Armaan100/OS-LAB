#include<iostream>
using namespace std;

class Book{
    public:
    string title, author;
    int price;
};


class TextBook: public Book{
    public:
    string subject;
};

int main(){
    TextBook T1;
    T1.subject = "Maths";
    T1.title = "Fun With Numbers";
    T1.author = "Gogoi A";
    T1.price=100;

    cout<<T1.subject<<" "<<T1.author<<endl;
}