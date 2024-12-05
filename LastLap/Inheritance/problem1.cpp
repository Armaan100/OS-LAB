#include<iostream>
using namespace std;

/*
Develop a payment processing system with a base class "Payment" and derived classes
"CreditCardPayment", "PayPalPayment", and "CashPayment". The base class should have
the common attributes of all payments, i.e., "amount", and each derived class should include
specific attributes related to that type of payment. Implement the following functionalities:
1. Create "Payment" class as abstract class and "processPayment()" as the member function
of class "payment".
2. Create derived class "CreditCardPayment" with data member "cardNumber".
3. Create derived class "PayPalPayment" with data member "email".
4. Create derived class "CashPayment".
5. All the derived class of "Payment" class should override the "processPayment()" member
function.
6. Create parameterized constructor in each class to initialize the data members.
7. Write a main function to create objects of each type and call the member function to handle
the specific payment processing.
*/

// Abstract base class
class Payment {
public:
    int amount;

    // Pure virtual function
    virtual void processPayment(int amount) = 0;

    // Virtual destructor
    virtual ~Payment() {}
};

// Derived class: CreditCardPayment
class CreditCardPayment : public Payment {
private:
    int cardNumber;

public:
    // Parameterized constructor
    CreditCardPayment(int cardNumber) {
        this->cardNumber = cardNumber;
    }

    // Override processPayment
    void processPayment(int amount) override {
        this->amount = amount;
        cout << "Credit Card Payment of " << amount << " processed using card number " << cardNumber << "." << endl;
    }
};

// Derived class: PayPalPayment
class PayPalPayment : public Payment {
private:
    string email;

public:
    // Parameterized constructor
    PayPalPayment(string email) {
        this->email = email;
    }

    // Override processPayment
    void processPayment(int amount) override {
        this->amount = amount;
        cout << "PayPal Payment of " << amount << " processed using email " << email << "." << endl;
    }
};


// Derived class: CashPayment
class CashPayment : public Payment {
public:
    // Override processPayment
    void processPayment(int amount) override {
        this->amount = amount;
        cout << "Cash Payment of " << amount << " processed." << endl;
    }
};

int main() {
    // Create objects of each derived class
    Payment* payment1 = new CreditCardPayment(123456789);
    Payment* payment2 = new PayPalPayment("user@example.com");
    Payment* payment3 = new CashPayment();

    // Process payments
    payment1->processPayment(100);
    payment2->processPayment(200);
    payment3->processPayment(300);

    // Clean up
    delete payment1;
    delete payment2;
    delete payment3;

    return 0;
}
