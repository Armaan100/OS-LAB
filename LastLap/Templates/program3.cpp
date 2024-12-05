#include<iostream>
using namespace std;

template<typename T>
void bubbleSort(T arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(){
    char arr[] = {'z', 'b', 'c'};
    bubbleSort(arr, 3);
    for(int i=0; i<3; i++){
        cout<<arr[i];
    }
}