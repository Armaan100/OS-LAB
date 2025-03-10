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
        this->pid = bt;
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


int calcuateAvgTAT(Process processes[], int n){
    int avgTAT = 0;
    for(int i=0; i<n; i++){
        avgTAT += processes[i].tat;
    }

    return avgTAT/n;
}

int calculateAvgWT(Process processes[], int n){
    int avgWT = 0;
    for(int i=0; i<n; i++){
        avgWT += processes[i].wt;
    }

    return avgWT/n;
}

void display(Process processes[], int n){
    cout << "\nPID\tAT\tBT\tCT\tWT\tTAT\n";
    cout << "-----------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].pid << "\t"
                << processes[i].at << "\t"
                << processes[i].bt << "\t"
                << processes[i].ct << "\t"
                << processes[i].ct << "\t"
                << processes[i].tat << endl;
    }
}


void sortByArrival(Process processes[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(processes[j].at > processes[j+1].at || 
               (processes[j].at == processes[j+1].at && processes[j].pid > processes[j+1].pid)) {
                Process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
}


void roundRobin(Process processes[], int n, int tq) {
    // Sort by arrival time first
    sortByArrival(processes, n);
    
    // Initialize remaining time
    for(int i = 0; i < n; i++) {
        processes[i].rt = processes[i].bt;
    }

    queue<int> readyQueue;
    int time = 0;
    int complete = 0;
    
    // Add first process
    readyQueue.push(0);
    int index = 1;  // Next process to check for arrival

    while(complete < n) {
        if(readyQueue.empty()) {
            time++;
            continue;
        }

        int i = readyQueue.front();
        readyQueue.pop();

        if(processes[i].rt > tq) {
            time += tq;
            processes[i].rt -= tq;
        } else {
            time += processes[i].rt;
            processes[i].rt = 0;
            processes[i].ct = time;
            complete++;
        }

        // Check for new arrivals up to current time
        while(index < n && processes[index].at <= time) {
            readyQueue.push(index);
            index++;
        }

        // Re-queue current process if not finished
        if(processes[i].rt > 0) {
            readyQueue.push(i);
        }
    }
}

int main(){
    int n, tq;
    cout<<"Enter the number of processes: ";
    cin>>n;

    cout<<"Enter the time quantum: ";
    cin>>tq;

    Process processes[n];
    cout<<"Enter process details (id, at, bt)"<<endl;
    int pid, at, bt;

    for(int i=0; i<n; i++){
        cout<<"Process "<<i+1<<" : ";
        cin>>processes[i].pid>>processes[i].at>>processes[i].bt;
    }

    roundRobin(processes, n, tq);

    calculateTAT(processes, n);
    calculateWT(processes, n);

    float avgTAT = calcuateAvgTAT(processes, n);
    float avgWT = calculateAvgWT(processes, n);

    display(processes, n);
}