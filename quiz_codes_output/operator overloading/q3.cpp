#include<iostream>
using namespace std; 
 
void func(int* ptr) { 
    cout << "Pointer version" << endl; 
} 

void func(int arr[], int size) { 
    cout << "Array version" << endl; 
}

int main() { 
    int arr[] = {1, 2, 3}; 
    func(arr, 3); 
    return 0; 
} 