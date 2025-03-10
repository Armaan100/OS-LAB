#include<iostream>
#include<queue>
using namespace std;

class Process{
    public:
    int pid;
    int bt;
    int at;
    int tat;
    int wt;
    int ct;
    int rt;

    Process(){
        pid = bt = at = tat = rt = wt = ct = 0;
    }

    Process(int pid, int bt, int at){
        this->pid = pid; 
        this->bt = bt;
        this->at = at;
        tat = wt = ct = 0;
    }
};

void calculateTAT(Process processes[], int n){
    for(int i=0; i<n; i++){
        processes[i].tat = processes[i].ct - processes[i].at;
    }
}


void calculateWT(Process processes[], int n){
    for(int i=0; i<n; i++){
        processes[i].wt = processes[i].tat - processes[i].bt;
    }
}

void sortProcesses(Process processes[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(processes[j].at > processes[j+1].at || (processes[j].at == processes[j+1].at && processes[j].pid>processes[j+1].pid)){
                swap(processes[j], processes[j+1]);
            }
        }
    }
}

void displayProcesses(Process processes[], int n){
    cout << "\nPID\tAT\tBT\tCT\tWT\tTAT\n";
    cout << "-----------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].pid << "\t"
                << processes[i].at << "\t"
                << processes[i].bt << "\t"
                << processes[i].bt << "\t"
                << processes[i].ct << "\t"
                << processes[i].tat << endl;
    }
}

void roundRobin(Process processes[], int n, int tq){
    sortProcesses(processes, n);

    int time = 0;
    int complete = 0;

    queue<int> q; //index

    // Initialize remaining time
    for(int i = 0; i < n; i++) {
        processes[i].rt = processes[i].bt;
    }

    //intitalize the ready queue
    q.push(0);
    time = processes[0].at;

    int index = 1;

    while(complete<n){
        if(q.empty()){
            // Advance time to the next process arrival
            if (index < n) {
                time = processes[index].at;
                q.push(index);
                index++;
            }
        }

        int i = q.front();
        q.pop();

        if(processes[i].rt > tq){
            time+=tq;
            processes[i].rt -= tq;
        }else{
            time += processes[i].rt;
            processes[i].rt = 0;
            processes[i].ct = time;
            complete++;
        }

        //checl for new arrivals at this current time
        while(index<n && processes[index].at <= time){
            q.push(index);
            index++;
        }

        //if poppped out process not complete then
        if(processes[i].rt > 0){
            q.push(i);
        }
    }

    calculateTAT(processes, n);
    calculateWT(processes, n);
    

    displayProcesses(processes, n);
}

int main(){
    int n;
    cout<<"Enter the total number of processes: ";
    cin>>n;

    Process processes[n];

    int tq = 2;
    int pid, at, bt;


    for(int i=0; i<n; i++){
        cin>>processes[i].pid>>processes[i].at>>processes[i].bt;
    }

    roundRobin(processes, n, tq);
}