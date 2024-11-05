#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Process{
    public:
    int pid;                //process id
    int priority;           //process priority
    float arrivalTime;      //arrival time
    float burstTime;        //burst time
    float remainingTime;    //remaining time
    float turnAroundTime;   //turn around time
    float completionTime;   //completion time
    float waitingTime;      //waiting time

    //constructor
    Process(){
        pid = arrivalTime = burstTime = remainingTime = turnAroundTime = waitingTime = completionTime = priority =  0;
    }
    Process(int pid, float arrivalTime, float burstTime, int priority){
        this->pid = pid;
        this->arrivalTime = arrivalTime;
        this->burstTime = burstTime;
        this->priority = priority;
        remainingTime = turnAroundTime = waitingTime = 0;
    }
    
};



class Scheduler{
    Process process[100];
    int n;

    public:
    Scheduler(): n(0) {}
    void addProcess(int pid, float arrivalTime, float burstTime, int priority){
        process[n++] = Process(pid, arrivalTime, burstTime, priority);
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


    void roundRobin(){   //Round Robin
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
    

     void prioritySchedulingNP() {
        float time = 0;
        sortProcesses();    //according to the arrival time and in case of tie -> by pid

        for (int i = 0; i < n; i++) {
            process[i].remainingTime = process[i].burstTime;
        }

        for (int i = 0; i < n; i++) {
            int highestPriority = -1;
            for (int j = 0; j < n; j++) {
                if (process[j].arrivalTime <= time && process[j].remainingTime > 0) {
                    if (highestPriority == -1 || process[j].priority < process[highestPriority].priority) {
                        highestPriority = j;
                    }
                }
            }

            if (highestPriority == -1) {
                time++;
                i--;
                continue;
            }

            time += process[highestPriority].burstTime;
            process[highestPriority].completionTime = time;
            process[highestPriority].remainingTime = 0;
        }

        // Calculate turn around time
        calculateTurnAroundTime(process, n);

        // Calculate waiting time
        calculateWaitingTime(process, n);

        float totalWaitingTime = calculateTotalWaitingTime(process, n);
        float totalTurnAroundTime = calculateTotalTurnAroundTime(process, n);

        displayResults(totalWaitingTime, totalTurnAroundTime);
    }


    void prioritySchedulingP() {
        float time = 0;
        int complete = 0;
        int highestPriority = -1;
        bool found = false;

        for (int i = 0; i < n; i++) {
            process[i].remainingTime = process[i].burstTime;
        }

        while (complete < n) {
            highestPriority = -1;
            found = false;

            for (int i = 0; i < n; i++) {
                if (process[i].arrivalTime <= time && process[i].remainingTime > 0) {
                    if (highestPriority == -1 || process[i].priority < process[highestPriority].priority) {
                        highestPriority = i;
                        found = true;
                    }
                }
            }

            if (!found) {
                time++;
                continue;
            }

            process[highestPriority].remainingTime--;
            if (process[highestPriority].remainingTime == 0) {
                complete++;
                process[highestPriority].completionTime = time + 1;
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

    //calculate waiting time
    int calculateTotalWaitingTime(Process process[], int n){
        float total = 0;
        for(int i=0; i<n; i++){
            total+=process[i].waitingTime;
        }

        return total;
    }

    //calculate turn around time
    float calculateTotalTurnAroundTime(Process process[], int n){
        float total = 0;
        for(int i=0; i<n; i++){
            total+=process[i].turnAroundTime;
        }

        return total;
    }

    //display results
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
    Scheduler S;
    int choice;

    bool con = true;

    while(con){
        cout << "\nScheduling Algorithms Menu";
        cout << "\n1. Add Process";
        cout << "\n2. Round Robin Scheduling";
        cout << "\n3. Non-Preemptive Priority Scheduling";
        cout << "\n4. Preemptive Priority Scheduling";
        cout << "\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 0: {
                con=false;
                cout<<"Terminated"<<endl;
            }
            case 1: {
                int pid, priority;
                float arrivalTime, burstTime;
                cout << "Enter Process ID: ";
                cin >> pid;
                cout << "Enter Arrival Time: ";
                cin >> arrivalTime;
                cout << "Enter Burst Time: ";
                cin >> burstTime;
                cout << "Enter Priority: ";
                cin >> priority;
                S.addProcess(pid, arrivalTime, burstTime, priority);
                break;
            }
            case 2:
                S.roundRobin();
                break;
            case 3:
                S.prioritySchedulingNP();
                break;
            case 4:
                S.prioritySchedulingP();
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}