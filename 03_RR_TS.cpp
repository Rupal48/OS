#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

struct process {
    string pname;
    int art;
    int bt;
    int rtFlag = 0;
};

bool allComp(int arr[], int n) {
    for (int i=0; i<n; i++) {
        if (arr[i]==0) return true;
    }
    return false;
}

int main() {

    int n = 3;
    // cout << "Enter no. of processes : ";
    // cin >> n;
    process proc[n] = {{"P1",0,10},{"P2",0,5},{"P3",0,8}};
    // for (int i=0;i<n;i++) {
    //     cout << "Enter Process Name : ";
    //     cin >> proc[i].pname;
    //     cout << "Enter Arrival Time : ";
    //     cin >> proc[i].art;
    //     cout << "Enter Burst Time : ";
    //     cin >> proc[i].bt;
    // }

    int tq = 2;
    // cout << "Enter time quantum  : ";
    // cin >> tq;

    int check[n] = {0};

    int compileTime[n];
    int totalTime = 0;
    int copybt[n];
    int responseTime[n];
    for (int i=0; i<n;i++) {
        copybt[i] = proc[i].bt;
    }
    while (allComp(check, n)) {

        for (int k =0;k<n;k++) {
            if (proc[k].art <= totalTime && check[k] == 0) {
                if (proc[k].rtFlag == 0) {
                    responseTime[k] = totalTime - proc[k].art;
                    proc[k].rtFlag = 1;
                }
                if (copybt[k] <= tq) {
                    compileTime[k] = totalTime + copybt[k];
                    totalTime += copybt[k];
                    copybt[k] = 0;
                }
                else {
                    compileTime[k] = totalTime + tq;
                    totalTime += tq;
                    copybt[k] -= tq;
                }
                
                if (copybt[k] == 0) {
                    check[k] = 1;
                }
            }
        }
        // int min_time = INT_MAX;
        // int k = n;
        // for (int i=0; i<n; i++) {
        //     if (check[i] == 0 && proc[i].art <= totalTime && copybt[i] < min_time) {
        //         min_time = copybt[i];
        //         k = i;
        //     }
        // }

        // if (k == n) {
        //     totalTime += 1;
        //     continue;
        // }
        
        
    }

    int turnaroundTime[n] , waitingTime[n];
    for (int i=0;i<n;i++) {
        turnaroundTime[i]=compileTime[i]-proc[i].art;
        waitingTime[i]=turnaroundTime[i]-proc[i].bt;
    }

    cout << "Process Name" << "\t" << "AT" << "\t\t" << "BT" << "\t\t" << "WT" << "\t\t" << "TAT" << "\t\t" << "RT" << endl;

    for (int i = 0; i < n; i++) {
        cout << " " << proc[i].pname << "\t\t" << proc[i].art << "\t\t"
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

// #include <iostream>
// using namespace std;
// void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum) {
//     int rem_bt[n];
//     for (int i = 0 ; i < n ; i++)
//         rem_bt[i] = bt[i];
//     int t = 0;
//     while (1) {
//         bool done = true;
//         for (int i = 0 ; i < n; i++) {
//             if (rem_bt[i] > 0) {
//                 done = false;
//                 if (rem_bt[i] > quantum) {
//                     t += quantum;
//                     rem_bt[i] -= quantum;
//                 }
//                 else {
//                     t = t + rem_bt[i];
//                     wt[i] = t - bt[i];
//                     rem_bt[i] = 0;
//                 }
//             }
//         }
//         if (done == true)
//             break;
//     }
// }
// void respTime(int bt[] ,int n , int quantum , int rt[]) {
//     int a = 0;
//     for(int i=0 ; i<n ;i++) {
//         if(bt[i]>quantum){
//             rt[i] = a;
//         }
//         a+= 2;
//     }
// }
// void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[], int ct[]) {
//     for (int i = 0; i < n ; i++) {
//         tat[i] = bt[i] + wt[i];
//         ct[i] = tat[i];
//     }
// }
// void findavgTime(int processes[], int n, int bt[], int quantum , int at[]) {
//     int wt[n], tat[n], ct[n], total_wt = 0, total_tat = 0 , rt[n];
//     findWaitingTime(processes, n, bt, wt, quantum);
//     findTurnAroundTime(processes, n, bt, wt, tat, ct);
//     respTime(bt , n , quantum , rt);
//     cout << "PN\t "<< " \tBT\t " << "\tAT\t" << " \tWT\t " << " \tTAT\t " << " \tCT\t " << " \tRT\n";
//     for (int i=0; i<n; i++) {
//         total_wt = total_wt + wt[i];
//         total_tat = total_tat + tat[i];
//         cout << " " << i+1 << "\t\t" << bt[i] <<"\t\t " <<at[i] <<"\t\t "<< wt[i] <<"\t\t " << tat[i] <<"\t\t " << ct[i] <<"\t\t " << rt[i] <<endl;
//     }
//     cout << "Average waiting time = " << (float)total_wt / (float)n;
//     cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
// }
// int main() {
//     int n;
//     cout << "Enter the number of processes: ";
//     cin >> n;
//     int processes[n], burst_time[n], at[n], quantum;
//     cout << "Enter burst times:\n";
//     for (int i = 0; i < n; i++) {
//         processes[i] = i + 1;
//         cout << "Burst time for process " << i + 1 << ": ";
//         cin >> burst_time[i];
//     }
//     cout << "Enter arrival times:\n";
//     for (int i = 0; i < n; i++) {
//         cout << "Arrival time for process " << i + 1 << ": ";
//         cin >> at[i];
//     }
//     cout << "Enter the time quantum: ";
//     cin >> quantum;
//     findavgTime(processes, n, burst_time, quantum , at);
//     return 0;
// }