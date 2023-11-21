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

    int n = 5;
    // cout << "Enter no. of processes : ";
    // cin >> n;
    process proc[n] = {{"P1",2,6},{"P2",5,2},{"P3",1,8},{"P4",0,3},{"P5",4,4}};
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
    int copybt[n];
    int responseTime[n];
    for (int i=0; i<n;i++) {
        copybt[i] = proc[i].bt;
    }
    while (allComp(check, n)) {

        int min_time = INT_MAX;
        int k = n;
        for (int i=0; i<n; i++) {
            if (check[i] == 0 && proc[i].art <= totalTime && copybt[i] < min_time) {
                min_time = copybt[i];
                k = i;
            }
        }

        if (k == n) {
            totalTime += 1;
            continue;
        }

        if (proc[k].rtFlag == 0) {
            responseTime[k] = totalTime - proc[k].art;
            proc[k].rtFlag = 1;
        }
        compileTime[k] = totalTime + 1;
        totalTime += 1;
        copybt[k] -= 1;
        if (copybt[k] == 0) {
            check[k] = 1;
        }
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