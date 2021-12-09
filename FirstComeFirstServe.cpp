// you can use this link to run the code
// https://onlinegdb.com/gUce_1Ujs
#include<iostream>
using namespace std;

// Function to find the waiting time for all
// processes
void findWaitingTime(int processes[], int n, int bt[], int wt[], int at[]){
    int service_time[n];
    service_time[0] = at[0];
    wt[0] = 0;

    // calculating waiting time
    for (int i = 1; i < n ; i++){
        // Add burst time of previous processes
        service_time[i] = service_time[i-1] + bt[i-1];

        // Find waiting time for current process =
        // sum - at[i]
        wt[i] = service_time[i] - at[i];

        // If waiting time for a process is in negative
        // that means it is already in the ready queue
        // before CPU becomes idle so its waiting time is 0
        if (wt[i] < 0)
            wt[i] = 0;
    }
}
 
// Function to calculate turn around time
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]){
// Calculating turnaround time by adding bt[i] + wt[i]
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate average waiting and turn-around times.
void findavgTime(int processes[], int n, int bt[], int at[]){
    int wt[n], tat[n];
 
    // Function to find waiting time of all processes
    findWaitingTime(processes, n, bt, wt, at);
 
    // Function to find turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);
 
    // Display processes along with all details
    cout << "Processes " << " Burst Time " << " Arrival Time " << " Waiting Time " << " Turn-Around Time " << " Completion Time \n";
    int total_wt = 0, total_tat = 0;
    for (int i = 0 ; i < n ; i++){
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        int compl_time = tat[i] + at[i];
        cout << " " << i+1 << "\t\t" << bt[i] << "\t\t"
             << at[i] << "\t\t" << wt[i] << "\t\t "
             << tat[i]  <<  "\t\t " << compl_time << endl;
    }
 
    cout << "Average waiting time = " << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}
 
// Driver code
int main(){
    // Process id's
    int processes[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
        61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 87, 79, 80,
        81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100,
    };
    int n = sizeof processes / sizeof processes[0];

    // Burst time of all processes
    int burst_time[] = {9, 1, 2, 9, 7, 0, 3, 8, 8, 3, 8, 3, 3, 0, 8, 4, 1, 9, 7, 4, 8, 
        0, 8, 3, 3, 6, 8, 6, 9, 0, 6, 4, 6, 6, 9, 0, 4, 5, 9, 0, 7, 3, 8, 2, 0, 5, 8, 0,
        1, 4, 7, 1, 1, 1, 9, 9, 0, 2, 8, 1, 2, 4, 7, 5, 6, 1, 4, 4, 8, 2, 7, 5, 6, 4, 2,
        1, 6, 5, 4, 0, 6, 3, 5, 2, 5, 8, 1, 5, 9, 5, 2, 9, 3, 3, 0, 7, 2, 6, 1, 8};

    // Arrival time of all processes
    int arrival_time[] = {5, 17, 20, 10, 14, 4, 10, 9, 6, 9, 16, 1, 19, 13, 3, 11, 19, 
        14, 11, 8, 8, 1, 13, 10, 20, 0, 6, 12, 11, 1, 19, 4, 13, 18, 2, 2, 20, 10, 19,
        12, 1, 16, 5, 19, 17, 0, 4, 19, 18, 13, 5, 20, 5, 8, 14, 7, 13, 6, 17, 10, 14,
        2, 12, 18, 6, 17, 3, 3, 14, 2, 14, 15, 2, 13, 16, 14, 18, 17, 6, 19, 5, 3, 14,
        14, 9, 7, 5, 16, 20, 14, 17, 20, 17, 0, 11, 17, 8, 5, 2, 15};

    findavgTime(processes, n, burst_time, arrival_time);

    return 0;
}
/////Output//////////Output//////////Output//////////Output//////////Output//////////Output//////////Output//////////Output/////
// Processes  Burst Time  Arrival Time  Waiting Time  Turn-Around Time  Completion Time 
//  1              9               5               0                9               14
//  2              1               17              0                1               18
//  3              2               20              0                2               22
//  4              9               10              7                16              26
//  5              7               14              12               19              33
// ........
// ........
// Average waiting time = 222.96
// Average turn around time = 227.43
