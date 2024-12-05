#include<iostream>
using namespace std;

class alpha{
    private:
    int x;

    public:
    alpha(){
        cout<<"Constructor aplha"<<endl;
    }

    alpha(int x){
       this->x = x;
       cout<<"Constructor aplha"<<endl;
    }

    ~alpha(){
        cout<<"Destructor alpha"<<endl;
    }
};

class beta{
    private:
    int y;

    public:
    beta(){
        cout<<"Constructor beta"<<endl;
    }

    beta(int y){
       this->y = y;
       cout<<"Constructor beta"<<endl;
    }

    ~beta(){
        cout<<"Destructor beta"<<endl;
    }
};

class gamma: public beta, public alpha{
    int g;

    public:
    gamma(int g){
        this->g = g;
        cout<<"Constructor gamma"<<endl;
    }

    ~gamma(){
        cout<<"Destructor gamma"<<endl;
    }
};

int main(){
    gamma g(10);
}