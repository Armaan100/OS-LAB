#include<iostream>
using namespace std;

class Account{
    private:
    string name;
    int account_number;
    string account_type;
    int balance;

    public:
    Account(string name, int account_number, string account_type, int balance){
        this->name = name;
        this->account_number = account_number;
        this->account_type = account_type;
        this->balance = balance;
    }

    void deposit(int amount){
        if(amount<0){
            cout<<"Entered amount is not valid"<<endl;
            return;
        }

        balance+=amount;
    }

    void withdraw(int);

    void display();
};

void Account::withdraw(int amount){
    if(balance<=0){
        cout<<'Insufficient balance'<<endl;
        return;
    }

    balance-=amount;
}

void Account::display(){
    cout<<"Name: "<<name<<" "<<"Balance: "<<balance<<endl;
}

int main(){

}