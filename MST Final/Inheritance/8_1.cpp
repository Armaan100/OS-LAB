//Bank Algorithm
#include<iostream>
using namespace std;

//Savings Account -> Compound Interest, Withdrawal Facilities, No ChequeBook Facility
//Current Account -> Chequebook Facility but no interest, (current acccount holder should also maintain a minimum balance and if the balance falls below this level, a service is imposed)


//So, line of thinking: 
//Account: deposit and withdraw must✅, plus balance
class Account {
protected:
    string customer_name;
    int account_number;
    string account_type;
    double balance;

public:
    Account(string name, int acc_no, string type) {
        customer_name = name;
        account_number = acc_no;
        account_type = type;
        balance = 0;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful! Current balance: " << balance << endl;
    }

    void display_balance() {
        cout << "Account balance: " << balance << endl;
    }
};

class sav_acc : public Account {
private:
    double interest_rate;  // In percentage

public:
    sav_acc(string name, int acc_no) : Account(name, acc_no, "Savings"), interest_rate(4.0) {}

    void compute_interest() {
        double interest = (balance * interest_rate) / 100;
        balance += interest;
        cout << "Interest computed and added. New balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful! New balance: " << balance << endl;
        }
    }
};


class cur_acc : public Account {
private:
    double minimum_balance;
    double service_charge;

public:
    cur_acc(string name, int acc_no) : Account(name, acc_no, "Current"), minimum_balance(1000), service_charge(50) {}

    void check_minimum_balance() {
        if (balance < minimum_balance) {
            cout << "Balance below minimum! Imposing service charge of " << service_charge << endl;
            balance -= service_charge;
            if (balance < 0) {
                balance = 0;  // Avoid negative balance
            }
            cout << "New balance after service charge: " << balance << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful! New balance: " << balance << endl;
            check_minimum_balance();
        }
    }

    // Method to check if chequebook facility is available
    void cheque_book_facility() {
        cout << "Cheque book facility is available for this current account." << endl;
    }
};