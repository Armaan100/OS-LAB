#include<iostream>
using namespace std;

void displaySafeSeq(int safeSeq[], int n){
    for(int i=0; i<n; i++){
        cout<<safeSeq[i]<<" ";
    }
}

void bankersAlgo(int max[][4], int allocation[][4], int need[][4], int available[], int n, int r){
    bool finish[n] = {0};   //intitlaize all to false
    int safeSeq[n];

    int k = 0;

    for(int i=0; i<n; i++){
        if(!finish[i]){
            bool canExecute = true;

            for(int j=0; j<r; j++){
                if(need[i][j] > available[j]){
                    canExecute = false; //ith process can't execute as for now
                    break;
                }
            }

            //if can execute
            if(canExecute){
                for(int j=0; j<r; j++){
                    available[j] += need[i][j];
                    need[i][j] = 0;
                }
                finish[i] = true;
                safeSeq[k++] = i+1;
                //start checking from the beginning
                i=-1;
            }
        }
    }

    bool isSafe = true;
    for(int i =0; i<n; i++){
        if(!finish[i])
            isSafe = false;
    }

    if(isSafe){
        displaySafeSeq(safeSeq, n);
    }else{
        cout<<"No safe seq"<<endl;
    }
}
int main(){
    int n = 3, r = 4;

    int allocation[3][4] = {
        {1, 3, 4, 2},
        {3, 2, 1, 1},
        {3, 4, 5, 6}
    };

    int max[3][4] = {
        {4, 5, 6, 7},
        {6, 6, 6, 6},
        {7, 7, 7, 7},
    };

    int total[4] = {100, 100, 100, 100};

    int available[4];

    //calculate available
    for(int i=0; i<r; i++){
        int total_allocated = 0;
        for(int j=0; j<n; j++){
            total_allocated+=allocation[j][i];
        }
        available[i] = total[i] - total_allocated;
    }

    int need[3][4];

    //calculate need
    for(int i=0; i<n; i++){
        for(int j = 0; j<r; j++){
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    bankersAlgo(max, allocation, need, available, n, r);
}