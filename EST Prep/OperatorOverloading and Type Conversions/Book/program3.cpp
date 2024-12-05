#include<iostream>
using namespace std;

const int size = 3;

class vector{
    int v[size];

    public:
    vector();                                  //constructs null vector
    vector(int *);                             //constructs vector form array
    friend vector operator *(int, vector);     //friend 1
    friend vector operator *(vector, int);     //friend 2
    friend istream & operator >>(istream &, vector &);
    friend ostream & operator <<(ostream &, vector &);
};


//function definitions
vector :: vector(){
    for(int i=0; i<size; i++){
        v[i] = 0;
    }
}

vector :: vector(int *x){
    for(int i=0; i<size; i++){
        v[i] = x[i];
    }
}

//friend function
vector operator *(int a, vector b){
    vector c;
    for(int i=0; i<size; i++){
        c.v[i] = a * b.v[i];
    }

    return c;
}

vector operator *(vector b, int a){
    vector c;
    for(int i=0; i<size; i++){
        c.v[i] = a * b.v[i];
    }

    return c;
}


istream & operator >>(istream &din, vector &b){
    for(int i=0; i<size; i++)
        din >> b.v[i];
    return(din);
}

ostream & operator <<(ostream &dout, vector &b){
    dout<<"("<<b.v[0];
    for(int i=1; i<size; i++)
        dout<<", "<<b.v[i];
    dout<<")";

    return dout;
}



int main(){
    int x[size] {2, 4, 10};

    vector m;       //invokes constrructor 1
    vector n = x;   //invokes constructor 2

    cout<<"Enterelements of vector m "<<"\n";
    cin>>m;         //invokes operator>>() function    [as te argument is a vector]

    cout<<"\n";
    cout<<"m ="<<m<<"\n";   //invokes operator<<()     [as the argument is a vector]

    vector p, q;

    p = 2*m;        //invokes friend 1
    q = n*2;        //invokes friend 2

    cout<<"\n";
    cout<<"p = "<<p<<"\n";      //invokes operator<<()
    cout<<"p = "<<p<<"\n";      //same as above

    return 0;
}

//istream and  ostream are classes defined in the iostream header file which have been included in the program