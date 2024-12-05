#include<iostream>
#include<vector>
#include<string>

using namespace std;


class Media{
    protected:
    string title;
    float price;

    public:
    Media(string title, float price){
        this->title = title;
        this->price  = price;
    }

    //empty virtual function
    virtual void display(){}
};


class Book: public Media{
    private:
    int pages;

    public:
    Book(string title, float price, int pages): Media(title, price){
        this->pages = pages;
    }

    void display(){
        cout<<"Title: "<<title<<" "<<"Price: "<<price<<"Pages: "<<pages<<endl;
    }
};


class Tape: public Media{
    private:
    int playTime;

    public:
    Tape(string title, float price, int playTime): Media(title, price){
        this->playTime = playTime;
    }

    void display(){
        cout<<"Title: "<<title<<" "<<"Price: "<<price<<"Play Time: "<<playTime<<endl;
    }
};


int main(){
    string title = "Building it Up";
    float price = 300, playTime = 4.5;
    int pages = 256;

    //Book Details
    Book B1(title, price, pages);
    Tape T1(title, price, playTime);

    Media* list[2];

    list[0] = &B1;  list[1] = &T1;

    cout<<"Book Details: ";
    list[0]->display();

    cout<<"Tape Display: ";
    list[1]->display();
}