// overloading of pre and post increment
#include <iostream>
using namespace std;

class Integer
{
    int a;

public:
    Integer(int a) : a(a) {}

    // overloading pre increment
    Integer operator++();

    // post-increment
    Integer operator++(int);

    int getValue()
    {
        return a;
    }
};

Integer Integer::operator++()
{
    ++a;
    return a;
}

Integer Integer::operator++(int)
{
    Integer old(*this);
    ++a;
    return old;
}

int main()
{
    Integer i = 6;

    cout << "Post Increment Operator" << endl;
    cout << "Integer++ : " << (i++).getValue() << endl;
    cout << "Pre Increment Operator" << endl;
    cout << "++Integer : " << (++i).getValue() << endl;
}