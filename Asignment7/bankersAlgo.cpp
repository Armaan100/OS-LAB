#include<iostream>
using namespace std;
/*
Write a program in C/C++/Java to simulate the Banker’s algorithm for 
deadlock avoidance. Consider at least 3 processes in the system, with 4 
resource  classes  having  at  least  one  resource  instance  for  each  class. 
Assume the values for Available, Allocation, MAX, and request from 
a  particular  process  from  your  side.  Program  must  reflect  two  cases, 
where a safe sequence exists for one and safe sequence does not exist 
for another.
*/

void calculateNeed(int need[3][4], int max[3][4], int allocation [3][4], int n, int r){
    for(int i=0; i<n; i++)
        for(int j=0; j<r; j++)
            need[i][j] = max[i][j] - allocation[i][j];
}

void displaySafeSeq(int safeSeq[], int n){
    cout<<"The safe sequence is: ";

    for(int i=0; i<n; i++){
        cout<<"P"<<safeSeq[i]<<" ";
    }
    cout<<endl;
}

void bankersAlgo(int need[3][4], int max[3][4], int allocation[3][4], int available[4], int n, int r){
    bool canExecute;
    int finish[n], safeSeq[n];

    int k=0;
    //at first set finsih of all the processes as false <-> 0
    for(int i=0; i<n; i++){
        finish[i] = 0;
    }

    for(int i=0; i<n; i++){
        canExecute = 1;
        //execute the incomplete process
        if(finish[i]==0){
            for(int j=0; j<r; j++){
                if(need[i][j]>available[j]){
                    canExecute=0;
                    break;
                }
            }
            
            //if need is less than available then can execute and will do the following
            if(canExecute){
                //update the finish status of that process and make insert in the safe swquence
                finish[i] = 1;
                safeSeq[k++] = i;

                //add allocated resources of finished process in available array
                for(int l=0; l<r; l++){
                    available[l]+=allocation[i][l];
                }
            }

            //again start cheking from the first process again
            i=-1;
        }
    }

    //Exiting from the loop, now to check if all the finish[i] are true or not
    //If true -> then safe sequence✅... if not then safe sequence DNE 
    bool isSafeSeq = 1;

    for(int i=0; i<n; i++){
        if(finish[i] == 0){
            isSafeSeq = 0;
            break;
        }
    }

    if (isSafeSeq) {
        displaySafeSeq(safeSeq, n);
    } else {
        cout << "Safe sequence does not exist" << endl;
    }
}



int main(){
    int n=3;
    int r=4;

    int allocation[3][4] = {
        {0, 0, 1, 2}, //P0
        {2, 0, 0, 0}, //P1
        {1, 0, 1, 1}  //P2
    };

    int max[3][4] = {
        {3, 2, 2, 4},  //P0
        {4, 0, 2, 0},  //P1
        {5, 2, 3, 3}   //P2
    };

    int total[4] = {8, 7, 6, 9};  //R0, R1, R2, R3

    int available[4];

    for(int i=0; i<r; i++){
        int total_allocated = 0;
        for(int j=0; j<n; j++){
            total_allocated+=allocation[j][i];
        }

        available[i] = total[i] - total_allocated;
    }

    int need[3][4];

    //calculate need
    calculateNeed(need, max, allocation, n, r);

    bankersAlgo(need, max, allocation, available, n, r);
}

