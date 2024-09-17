#include<iostream>
using namespace std;

//Base Class
class base{
    protected:
    int i;

    public:
    base(int x){
        i = x;
        cout<<"Constructng Base\n";
    }

    ~base(){
        cout<<"Destructing base\n";
    }
};


class derived: public base{
    int j;

    public:
    derived(int x, int y): base(y){
        j = x;
        cout<<"Constructing derived\n";
    }

    ~derived(){
        cout<<"Destructing derived\n";
    }

    void show(){
        cout<<i<<" "<<j<<endl;
    }
};

int main(){
    derived obj(3, 4);
    obj.show();
    return 0;
}