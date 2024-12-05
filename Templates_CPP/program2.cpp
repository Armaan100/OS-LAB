#include<iostream>

//templates are compiled at compile time
template<typename T, int N>
class Array{
    private:
    T my_arr[N];

    public:
    int getSize(){
        return N;
    }
};

//templates can be thought of as -> compiler wrting code for me based on the set of rules given to it

int main(){
    Array<std::string, 5> A;
    std::cout<<A.getSize();
}