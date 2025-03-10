#include<iostream>
#include<queue>

using namespace std;


/*
INPUT: n processes with respective CPU burst time and arrival time.

System will ask the user to select the type of algorithm from the list mentioned above

System should display the waiting time for each process, average waiting time for the whole system, and final execution sequence.
*/

class Process{
    public:
    int pid;                //process id
    float arrivalTime;      //arrival time
    float burstTime;        //burst time
    float remainingTime;    //remaining time
    float turnAroundTime;   //turn around time
    float completionTime;   //completion time
    float waitingTime;      //waiting time

    //constructor
    Process(){
        pid = arrivalTime = burstTime = remainingTime = turnAroundTime = waitingTime = completionTime =  0;
    }

    Process(int pid, float arrivalTime, float burstTime){
        this->pid = pid;
        this->arrivalTime = arrivalTime;
        this->burstTime = burstTime;
        remainingTime = turnAroundTime = waitingTime = 0;
    }
    
};


class Scheduler{
    Process process[100];
    int n;

    public:
    Scheduler(): n(0) {}
    void addProcess(int pid, float arrivalTime, float burstTime){
        process[n++] = Process(pid, arrivalTime, burstTime);
    }

    void sortProcesses() {
        // Manual sorting using bubble sort
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (process[j].arrivalTime > process[j + 1].arrivalTime || (process[j].arrivalTime == process[j + 1].arrivalTime && process[j].pid > process[j + 1].pid)) {
                    // Swap process[j] and process[j + 1]
                    Process temp = process[j];
                    process[j] = process[j + 1];
                    process[j + 1] = temp;
                }
            }
        }
    }

    //Non Premptive Algos
    void fcfsAlgo(){
        float time = 0;
        //initialization
        sortProcesses();
        
        //fcfs
        for(int i=0; i<n; i++){
            if (process[i].arrivalTime > time) {
                time = process[i].arrivalTime; // Wait for the process to arrive
            }
            process[i].completionTime = time + process[i].burstTime; // Calculate completion time
            time = process[i].completionTime; // Update time to current process's completion
        }

        calculateTurnAroundTime(process, n);
        calculateWaitingTime(process, n);

        float totalWaitingTime = calculateTotalWaitingTime(process, n);
        float totalTurnAroundTime =calculateTotalTurnAroundTime(process, n);

        displayResults(totalWaitingTime, totalTurnAroundTime);
    }


    void fsfcPremp(){   //Round Robin
        float time = 0;
        int tq = 2;
        sortProcesses();

        // float remainingTime[n];

        //initialize remaining time arr
        for(int i=0; i<n; i++){
            process[i].remainingTime = process[i].burstTime;
        }

        //sets each one's completion time
        // bool allDone = false;

        queue<Process*> readyQueue;

        //initialize the ready queue
        // Wait for the first process to arrive
        int index = 0;
        while (index < n && process[index].arrivalTime > time) {
            time++;
        }

        // Initialize the ready queue with the first process
        if (index < n) {
            readyQueue.push(&process[index]);
            index++;
        }

        while(!readyQueue.empty()){
            Process* p = readyQueue.front();
            readyQueue.pop();

            if(time<p->arrivalTime){
                time=p->arrivalTime;
            }

            if(p->remainingTime>tq){
                time+=tq;
                p->remainingTime-=tq;
            }else{
                time+=p->remainingTime;
                p->completionTime = time;
                p->remainingTime = 0;
            }

            // Add new processes to the ready queue that have arrived
            while (index < n && process[index].arrivalTime <= time) {
                readyQueue.push(&process[index]);
                index++;
            }

            if(p->remainingTime != 0){
                readyQueue.push(p);
            }
        }

        //calulate turn around time
        calculateTurnAroundTime(process, n);

        //calucate waiting time
        calculateWaitingTime(process, n);

        float totalWaitingTime = calculateTotalWaitingTime(process, n);
        float totalTurnAroundTime = calculateTotalTurnAroundTime(process, n);

        displayResults(totalWaitingTime, totalTurnAroundTime);
    }



    //SJF
    void SJF(){
        float time  = 0;
        
        for(int i=0; i<n; i++){
            process[i].
            
            remainingTime = process[i].burstTime;
        }

        int shortest = 0;  
        int complete = 0; 
        int minBurst = INT16_MAX;

        while(complete<n){
            minBurst = INT16_MAX;
            shortest = -1;

            for(int i=0; i<n; i++){
                if(process[i].arrivalTime<=time && process[i].remainingTime>0 && process[i].remainingTime<minBurst){
                    minBurst = process[i].remainingTime;
                    shortest=i;
                }
            }

            if(shortest==-1){
                time++;
                continue;
            }

            time+=process[shortest].remainingTime;
            process[shortest].completionTime = time;
            process[shortest].remainingTime = 0;
            complete++;
        }

        // calculate turn around time
        calculateTurnAroundTime(process, n);

        // calculate waiting time
        calculateWaitingTime(process, n);

        float totalWaitingTime = calculateTotalWaitingTime(process, n);
        float totalTurnAroundTime = calculateTotalTurnAroundTime(process, n);

        displayResults(totalWaitingTime, totalTurnAroundTime);
    }


    
    //SRTF <-> Preempticve version of SJF
    void SRTF() {
        float time = 0;
        int complete = 0;
        int minBurst = INT16_MAX;
        int shortest = -1;
        bool found = false;

        for (int i = 0; i < n; i++) {
            process[i].remainingTime = process[i].burstTime;
        }

        while (complete < n) {
            for (int i = 0; i < n; i++) {
                if (process[i].arrivalTime <= time && process[i].remainingTime > 0 && process[i].remainingTime < minBurst) {
                    minBurst = process[i].remainingTime;
                    shortest = i;
                    found = true;
                }
            }

            if (!found) {
                time++;
                continue;
            }

            process[shortest].remainingTime--;
            minBurst = process[shortest].remainingTime;
            if (minBurst == 0) {
                minBurst = INT16_MAX;
            }

            if (process[shortest].remainingTime == 0) {
                complete++;
                found = false;
                process[shortest].completionTime = time + 1;
            }

            time++;
        }

        // Calculate turn around time
        calculateTurnAroundTime(process, n);

        // Calculate waiting time
        calculateWaitingTime(process, n);

        float totalWaitingTime = calculateTotalWaitingTime(process, n);
        float totalTurnAroundTime = calculateTotalTurnAroundTime(process, n);

        displayResults(totalWaitingTime, totalTurnAroundTime);
    }


    //UTILITY FUNCTIONS
    
    //calcuation of each Pi's turn around time
    void calculateTurnAroundTime(Process process[], int n){
        for(int i=0; i<n; i++){
            process[i].turnAroundTime = process[i].completionTime - process[i].arrivalTime;
        }
    }
     //calcuation of each Pi's waiting time
    void calculateWaitingTime(Process process[], int n){
        for(int i=0; i<n; i++){
            process[i].waitingTime = process[i].turnAroundTime - process[i].burstTime;
        }
    }

    int calculateTotalWaitingTime(Process process[], int n){
        float total = 0;
        for(int i=0; i<n; i++){
            total+=process[i].waitingTime;
        }

        return total;
    }

    float calculateTotalTurnAroundTime(Process process[], int n){
        float total = 0;
        for(int i=0; i<n; i++){
            total+=process[i].turnAroundTime;
        }

        return total;
    }


    //utility functions
     void displayResults(float totalWaitingTime, float totalTurnAroundTime) const {
        cout << "\nPID\tAT\tBT\tCT\tWT\tTAT\n";
        cout << "-----------------------------------------\n";
        for (int i = 0; i < n; i++) {
            cout << process[i].pid << "\t"
                    << process[i].arrivalTime << "\t"
                    << process[i].burstTime << "\t"
                    << process[i].completionTime << "\t"
                    << process[i].waitingTime << "\t"
                    << process[i].turnAroundTime << endl;
        }

        float averageWaitingTime = totalWaitingTime / n;
        cout << "\nAverage Waiting Time: " << averageWaitingTime << " ms";

        float averageTurnAroundTime = totalTurnAroundTime / n;
        cout << "\nAverage Turn Around Time: " << averageTurnAroundTime << " ms";
    }
};



int main(){
    bool con = true;

    while(con){
        int n;
        cout<<"\nEnter the number of processes: ";
        cin>>n;

        Scheduler S;

        int pid, priority;
        float arrivalTime, burstTime;

        for(int i=0; i<n; i++){
            cout<<"Enter pid, arrival time, priority(0 if not priority scheduling) and burst time in this sequence: ";
            cin>>pid>>arrivalTime>>burstTime;

            S.addProcess(pid, arrivalTime, burstTime);
        }

        int choice;
        cout<<"\nChoose Scheduling Algorithm:\n";
        cout<<"1. First-Come, First-Served (FCFS)\n";
        cout<<"2. First-Come, First-Served (Preemptive FCFS)\n";
        cout<<"3. Shortest Job First (Non-Preemptive)\n";
        cout<<"4. Shortest Job First (Preemptive)\n";
        cout<<"0. To exit\n";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch (choice) {
            case 1:
                S.fcfsAlgo();
                break;
            case 2:
                S.fsfcPremp();
                break;
            case 3:
                S.SJF();
                break;
            case 4:
                S.SRTF();
                break;
            case 0:
                con=false;
                break;
            default:
                cout << "Invalid choice!" << endl;
                con=false;
        }
    }

    return 0;
}