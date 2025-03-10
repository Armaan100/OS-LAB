#include<iostream>
using namespace std;

void displayPartitions(int partitions[], int numPartitions){
    for(int i=0; i<numPartitions; i++){
        cout<<"Space available for block "<<i+1<<" "<<partitions[i]<<endl;
    }
}

//first fit
void firstFit(int partitions[], int process[], int numPartitions, int numProcess){
    bool allocated_arr[numPartitions] = {0};

    for(int i=0; i<numProcess; i++){
        bool isAllocated = 0;
        for(int j=0; j<numPartitions; j++){
            if(process[i]<=partitions[j] && !allocated_arr[j]){
                cout << "Process " << i + 1 << " allocated to block no. " << j + 1 << " with size " << partitions[j] << endl;
                allocated_arr[j] = 1;
                partitions[j] -= process[i];
                isAllocated = 1;
                break;
            }
        }

        if(!isAllocated){
            cout<<"No space for process"<<i+1<<endl;
        }
    }

    displayPartitions(partitions, numPartitions);
}

void bestFit(int partitions[], int process[], int numPartitions, int numProcess){
    bool allocated_arr[numPartitions] = {0};

    for(int i=0; i<numProcess; i++){
        int bestIndex = -1;
        int minDiff = INT8_MAX;

        bool isAllocated = 0;

        for(int j=0; j<numPartitions; j++){
            if(process[i]<=partitions[j] && (partitions[j] - process[j])<minDiff && !allocated_arr[j]){
                bestIndex = j;
                minDiff = partitions[j] - process[i];
                isAllocated = 1;
            }
        }

        if(!isAllocated){
            cout<<"No space"<<endl;
        }else{
            cout << "Process " << i + 1 << " allocated to block no. " << bestIndex + 1 << " with size " << partitions[bestIndex] <<endl;
            partitions[bestIndex] -= process[i];
            allocated_arr[bestIndex] = 1;
        }
    }

    displayPartitions(partitions, numPartitions);
}

int main(){
    int numPartitions; int numProcess;

    cout<<"Enter number of partitions";
    cin>>numPartitions;

    int partitions[numPartitions];
    int originalPartitions[numPartitions];

    for(int i=0; i<numPartitions; i++){
        cout<<"Enter space for partition "<<i+1<<" : ";
        cin>>partitions[i];
        originalPartitions[i] = partitions[i];
    }


    cout<<"Enter number of processes: ";
    cin>>numProcess;

    int process[numProcess];

    for(int  i=0; i<numProcess; i++){
        cout<<"Enter space for process "<<i+1<<" : ";
        cin>>process[i];
    }

    int choice = 0;

    do{
        cout<<"First fit->1, best fit->2, worst fit->3, quit -> 4"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        if(choice == 1){
            //copy the partitions into the original
            for(int i=0; i<numPartitions; i++){
                partitions[i] = originalPartitions[i];
            }
            firstFit(partitions, process, numPartitions, numProcess);
        }else if(choice == 2){
            for(int i=0; i<numPartitions; i++){
                partitions[i] = originalPartitions[i];
            }
            bestFit(partitions, process, numPartitions, numProcess);
        }else if(choice == 3){
            for(int i=0; i<numPartitions; i++){
                partitions[i] = originalPartitions[i];
            }
        }
    }while(choice != 4);

}