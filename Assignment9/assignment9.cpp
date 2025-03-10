#include <iostream>
using namespace std;

void displayPartitions(int ptr[], int size){
    cout<<"Memory partitions: ";
    for(int i=0; i<size; i++){
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
}

//FIRST FIT
void FirstFit(int prs[], int prt[], int prsSize, int prtSize){
    cout<<"---------First Fit Allocation--------"<<endl;

    bool allocated_prt[prtSize] = {0};

    for(int i=0; i<prsSize; i++){
        bool allocated = false;

        for(int j=0; j<prtSize; j++){
            if(prs[i] <= prt[j] && !allocated_prt[j]){
                cout << "Process " << i + 1 << " allocated to block no. " << j + 1 << " with size " << prt[j] << endl;
                prt[j] -= prs[i];
                allocated = true;
                allocated_prt[j] = 1;
                break;
            }
        }

        if(!allocated){
            cout << "No space for process " << i + 1 << endl;
        }
    }

    displayPartitions(prt, prtSize);
}


//BEST FIT
void BestFit(int prs[], int prt[], int prsSize, int prtSize){
    cout<<"--------Best Fit Allocation--------"<<endl;

    bool allocated_prt[prtSize] = {0};

    for(int i=0; i<prsSize; i++){
        int bestIndex = -1;
        int minDiff = INT8_MAX;

        for(int j=0; j<prtSize; j++){
            if(prs[i]<=prt[j] && (prt[j]-prs[i])<minDiff && !allocated_prt[j]){
                minDiff = prt[j]-prs[i];
                bestIndex = j;
            }
        }

        if(bestIndex != -1){    //milgaya location
            cout << "Process " << i + 1 << " allocated to block no. " << bestIndex + 1 << " with size " << prt[bestIndex] << endl;
            allocated_prt[bestIndex] = 1;
            prt[bestIndex] -= prs[i];        
        }else {
            cout << "No space for process " << i + 1 << endl;
        }
    }
    displayPartitions(prt, prtSize);
}


//WORST FIT
void WorstFit(int prs[], int prt[], int prsSize, int prtSize){
    cout<<"--------Best Fit Allocation--------"<<endl;

    bool allocated_prt[prtSize] = {0};

    for(int i=0; i<prsSize; i++){
        int worstIndex = -1;
        int maxDiff = -1;

        for(int j=0; j<prtSize; j++){
            if(prs[i]<=prt[j] && (prt[j]-prs[i])>maxDiff && !allocated_prt[j]){
                maxDiff = prt[j]-prs[i];
                worstIndex = j;
            }
        }

        if(worstIndex != -1){    //milgaya location
            cout << "Process " << i + 1 << " allocated to block no. " << worstIndex + 1 << " with size " << prt[worstIndex] << endl;
            allocated_prt[worstIndex] = 1;
            prt[worstIndex] -= prs[i];        
        }else {
            cout << "No space for process " << i + 1 << endl;
        }
    }
    displayPartitions(prt, prtSize);
}


int main()
{
    int numPartitions, numProcesses;

    cout << "Enter the number of memoery partitions: ";
    cin >> numPartitions;

    int Partitions[numPartitions];
    int originalPartitions[numPartitions];

    for (int i = 0; i < numPartitions; i++)
    {
        cout << "Enter the size of memory partition " << i + 1 << " : ";
        cin >> Partitions[i];
        originalPartitions[i] = Partitions[i];
    }

    cout << "Enter the number of processes: ";
    cin >> numProcesses;
    int Process[numProcesses];

    for (int i = 0; i < numProcesses; i++)
    {
        cout << "Enter the size required for process " << i + 1 << " : ";
        cin >> Process[i];
    }

    cout << endl << endl;

    int choice = 0;

    do
    {
        cout << "1. First Fit \n2. Best Fit \n3. Worst Fit \n4. Exit \n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Reset Partitions to original state
            for (int i = 0; i < numPartitions; i++)
            {
                Partitions[i] = originalPartitions[i];
            }
            FirstFit(Process, Partitions, numProcesses, numPartitions);
            break;
        case 2:
            // Reset Partitions to original state
            for (int i = 0; i < numPartitions; i++)
            {
                Partitions[i] = originalPartitions[i];
            }
            BestFit(Process, Partitions, numProcesses, numPartitions);
            break;
        case 3:
            // Reset Partitions to original state
            for (int i = 0; i < numPartitions; i++)
            {
                Partitions[i] = originalPartitions[i];
            }
            WorstFit(Process, Partitions, numProcesses, numPartitions);
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }while(choice!=4);
}

