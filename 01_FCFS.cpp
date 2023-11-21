// GFG Approach using struct also useful when not given in order

#include <iostream>
#include <string>
using namespace std;

struct process {
    string pname;
    int art;
    int bt;
};

void bubbleSort(process arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].art > arr[j+1].art) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
 
        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}

int main() {

    int n = 4;
    // cout << "Enter no. of processes : ";
    // cin >> n;
    process proc[n] = {{"1",1,3},{"2",2,4},{"3",1,2},{"4",4,4}};
    // process proc[n];
    // for (int i=0;i<n;i++) {
    //     cout << "Enter Process Name : ";
    //     cin >> proc[i].pname;
    //     cout << "Enter Arrival Time : ";
    //     cin >> proc[i].art;
    //     cout << "Enter Burst Time : ";
    //     cin >> proc[i].bt;
    // }

    bubbleSort(proc, n);

    int compileTime[n];
    compileTime[0]=proc[0].art+proc[0].bt;
    for (int i=1;i<n;i++) {
        if (proc[i].art<=compileTime[i-1]) {
            compileTime[i]=compileTime[i-1]+proc[i].bt;
        }
        else {
            compileTime[i]=proc[i].art+proc[i].bt;
        }
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

// My Approach
// Not useful when given not in order

// int main() {
//     int n;
//     cout << "Enter no. of processes : ";
//     cin >> n;
//     char name[n][10];
//     int arrivalTime[n] , burstTime[n];
//     for (int i=0;i<n;i++) {
//         cout << "Enter Process Name : ";
//         cin >> name[i];
//         cout << "Enter Arrival Time : ";
//         cin >> proc[i].art;
//         cout << "Enter Burst Time : ";
//         cin >> burstTime[i];
//     }
//     int compileTime[n];
//     compileTime[0]=arrivalTime[0]+burstTime[0];
//     for (int i=1;i<n;i++) {
//         if (arrivalTime[i]<=compileTime[i-1]) {
//             compileTime[i]=compileTime[i-1]+burstTime[i];
//         }
//         else {
//             compileTime[i]=arrivalTime[i]+burstTime[i];
//         }
//     }
//     int turnaroundTime[n] , waitingTime[n] , responseTime[n];
//     for (int i=0;i<n;i++) {
//         turnaroundTime[i]=compileTime[i]-arrivalTime[i];
//         waitingTime[i]=turnaroundTime[i]-burstTime[i];
//         responseTime[i]=waitingTime[i];   //Only in case of this algo
//     }
//     int sumTAT=0 , sumWT=0 , sumRT=0;
//     for (int i=0;i<n;i++) {
//         sumTAT+=turnaroundTime[i];
//         sumWT+=waitingTime[i];
//         sumRT+=responseTime[i];
//     }
//     cout << "Average TurnAround Time = " << (float)sumTAT/n << endl;
//     cout << "Average Waiting Time = " << (float)sumWT/n << endl;
//     cout << "Average Response Time = " << (float)sumRT/n << endl;
//     return 0;
// }