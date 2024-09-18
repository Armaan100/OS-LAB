#include<iostream>
using namespace std;

class Base{
    protected:
    static int count;

    public:
    Base(){
        count++;
    }

    virtual ~Base(){
        count--;
    }

    static void showCount(){
        cout<<"Count: "<<count<<endl;
    }
};

int Base::count = 0;

class Derived: public Base{
    public:
    Derived(){
        count++;
    }

    ~Derived(){
        count--;
    }
};


int main(){
    Base *b1 = new Base();
    Base *b2 = new Derived();
    Derived *d1 = new Derived();

    Base::showCount();

    delete b1;
    Base::showCount();

    delete b2;
    Base::showCount();

    delete d1;
    Base::showCount();
}