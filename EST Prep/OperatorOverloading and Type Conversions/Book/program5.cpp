#include<iostream>
using namespace std;


class invent2;      //destination class declared

class invent1{      //source class definition
    int code, items;
    float price;

    public:
    invent1(int a, int b, float c){
        code = a;
        items = b;
        price = c;
    }
    
    void putData(){
        cout<<"Code: "<<code<<"\n";
        cout<<"Items: "<<items<<"\n";
        cout<<"Value: "<<price<<"\n";
    }

    int getCode(){
        return code;
    }

    int getItems(){
        return items;
    }

    float getPrice(){
        price;
    }

    //conversion function
    operator float(){
        return items*price;
    }

    //invent1 to invent2
    operator invent2(){
        invent2 temp;
        temp.code = code;
        temp.value = price*items;
        return temp;
    }
};



//destination class definition
class invent2{
    int code;
    float value;

    public:
    invent2(){
        code = 0;
        value = 0;
    }

    invent2(int x, float y){  //initialization constructor
        code = x;
        value = y;
    }

    void putData(){
        cout<<"Code: "<<code<<"\n";
        cout<<"Value: "<<value<<"\n";
    }

    invent2(invent1 p){
        code = p.getCode();
        value = p.getItems()*p.getPrice();
    }

    friend class invent1;
};


int main(){

}
