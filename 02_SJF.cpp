#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

struct process {
    string pname;
    int art;
    int bt;
};

bool allComp(int arr[], int n) {
    for (int i=0; i<n; i++) {
        if (arr[i]==0) return true;
    }
    return false;
}

int main() {

    int n = 4;
    // cout << "Enter no. of processes : ";
    // cin >> n;
    process proc[n] = {{"1",1,3},{"2",2,4},{"3",1,2},{"4",4,4}};
    // for (int i=0;i<n;i++) {
    //     cout << "Enter Process Name : ";
    //     cin >> proc[i].pname;
    //     cout << "Enter Arrival Time : ";
    //     cin >> proc[i].art;
    //     cout << "Enter Burst Time : ";
    //     cin >> proc[i].bt;
    // }

    int check[n] = {0};

    int compileTime[n];
    int totalTime = 0;
    while (allComp(check, n)) {

        int min_time = INT_MAX;
        int k = n;
        for (int i=0; i<n; i++) {
            if (check[i] == 0 && proc[i].art <= totalTime && proc[i].bt < min_time) {
                min_time = proc[i].bt;
                k = i;
            }
        }

        if (k == n) {
            totalTime += 1;
            continue;
        }
        compileTime[k] = totalTime + proc[k].bt;
        totalTime += proc[k].bt;
        check[k] = 1;
    }

    int turnaroundTime[n] , waitingTime[n] , responseTime[n];
    for (int i=0;i<n;i++) {
        turnaroundTime[i]=compileTime[i]-proc[i].art;
        waitingTime[i]=turnaroundTime[i]-proc[i].bt;
        responseTime[i]=waitingTime[i];   //Only in case of this algo
    }

    for (int i = 0; i < n; i++) {
        cout << " " << proc[i].pname << "\t\t"
            << proc[i].bt << "\t\t " << waitingTime[i] 
            << "\t\t " << turnaroundTime[i] << "\t\t" << responseTime[i] << endl; 
    }

    int sumTAT=0 , sumWT=0 , sumRT=0;
    for (int i=0;i<n;i++) {
        sumTAT+=turnaroundTime[i];
        sumWT+=waitingTime[i];
        sumRT+=responseTime[i];
    }
    cout << "Average TurnAround Time = " << (float)sumTAT/n << endl;
    cout << "Average Waiting Time = " << (float)sumWT/n << endl;
    cout << "Average Response Time = " << (float)sumRT/n << endl;
    return 0;
}



// The way it is done in file

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// struct Process {
//     int id;
//     int arrivalTime;
//     int burstTime;
//     int completionTime;
//     int turnaroundTime;
//     int waitingTime;
// };
// bool compareArrival(const Process& a, const Process& b) {
//     return a.arrivalTime < b.arrivalTime;
// }
// bool compareBurst(const Process& a, const Process& b) {
//     return a.burstTime < b.burstTime;
// }
// int main() {
//     int n;
//     float avgTurnaroundTime = 0, avgWaitingTime = 0;
//     cout << "Enter the number of processes: ";
//     cin >> n;
//     vector<Process> processes(n);
//     cout << "Enter Arrival Time and Burst Time for each process:" << endl;
//     for (int i = 0; i < n; i++) {
//         processes[i].id = i + 1;
//         cout << "Process P" << processes[i].id << " Arrival Time: ";
//         cin >> processes[i].arrivalTime;
//         cout << "Process P" << processes[i].id << " Burst Time: ";
//         cin >> processes[i].burstTime;
//     }
//     sort(processes.begin(), processes.end(), compareArrival);
//     int currentTime = 0;
//     for (int i = 0; i < n; i++) {
//         currentTime = max(currentTime, processes[i].arrivalTime);
//         sort(processes.begin() + i, processes.end(), compareBurst);
//         processes[i].completionTime = currentTime + processes[i].burstTime;
//         processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
//         processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
//         avgTurnaroundTime += processes[i].turnaroundTime;
//         avgWaitingTime += processes[i].waitingTime;
//         currentTime = processes[i].completionTime;
//     }
//     avgTurnaroundTime /= n;
//     avgWaitingTime /= n;
//     cout << "Average Turnaround Time = " << avgTurnaroundTime << endl;
//     cout << "Average Waiting Time = " << avgWaitingTime << endl;
//     cout << "Average Response Time = " << avgWaitingTime << endl;
//     return 0;
// }