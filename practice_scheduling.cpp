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

class Scheduler{
    Process processes[100];
    int size;
    int n;

    public:
    Scheduler(int size): size(size) {
        n=0;
    }

    void addProcess(int pid, int bt, int at){
        processes[n++] = Process(pid, bt, at);
    }


    //sort processes according to their arrival time
    void sortProcesses(){
        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-i-1; j++){
                if(processes[j].at > processes[j+1].at || (processes[j].at == processes[j+1].at && processes[j].pid > processes[j + 1].pid)){
                    Process temp = processes[j];
                    processes[j] = processes[j+1];
                    processes[j+1] = temp;
                }
            }
        }
    }

    //Round Robin
    // void roundRobin() {
    //     queue<Process*> readyQueue;
    //     int time = 0;
    //     int index = 0;
    //     int timeQuantum = 2;
    //     int complete = 0;

    //     // Initialize remaining time
    //     for(int i = 0; i < n; i++) {
    //         processes[i].rt = processes[i].bt;
    //     }

    //     time = processes[index].at; 

    //     //initialize the queue
    //     while(index<n && processes[index].at == time){
    //         readyQueue.push(&processes[index]);
    //         index++;
    //     }


    //     while(complete < n) {
    //         if(readyQueue.empty()) {
    //             time = processes[index].at;
    //             continue;
    //         }

    //         Process* p = readyQueue.front();
    //         readyQueue.pop();

    //         // Check if processes has arrived
    //         if(time < p->at) {
    //             time = p->at;
    //         }

    //         if(p->rt > timeQuantum) {
    //             time += timeQuantum;
    //             p->rt -= timeQuantum;
    //         } else {
    //             time += p->rt;
    //             p->ct = time;
    //             p->rt = 0;
    //             complete++;
    //         }

    //         // Add new processes that have arrived
    //         while(index < n && processes[index].at <= time) {
    //             readyQueue.push(&processes[index++]);
    //         }

    //         // Re-queue if processes not finished
    //         if(p->rt > 0) {
    //             readyQueue.push(p);
    //         }
    //     }

    //     calculateTurnAroundTime(processes, n);
    //     calculateWaitingTime(processes, n);

    //     float totalWaitingTime = calculateTotalWaitingTime(processes, n);
    //     float totalTurnAroundTime = calculateTotalTurnAroundTime(processes, n);

    //     displayResults(totalWaitingTime, totalTurnAroundTime);
    // }

    //SJF
    void SJF(){
        int complete = 0;
        int time = 0;

        bool executed[n] = {0};

        while(complete<n){
            int minJob = INT16_MAX;
            int minIndex = -1;

            for(int i=0; i<n; i++){
                if(!executed[i] && processes[i].rt>0 && processes[i].bt>minJob){
                    minJob = processes[i].bt;
                    minIndex = i;
                }
            }

            if(minIndex == -1){
                time++;
                continue;
            }

            time += processes[minIndex].bt;
            processes[minIndex].rt = 0;
            processes[minIndex].ct = time;
            executed[minIndex] = 1;
            complete++;
        }

        calculateTAT(processes, n);
        calculateWT(processes, n);

        display(processes, n);
    }

    //utility functions
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
};