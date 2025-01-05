#include <stdio.h>

int main() {
    int n, bt[20], pri[20], wt[20], tat[20], p[20];
    float total_wt = 0, total_tat = 0;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst times and priorities
    printf("\nEnter Burst Time and Priority for each process (BT Priority):\n");
    for (int i = 0; i < n; i++) {
        printf("Process p%d: ", i + 1);
        scanf("%d %d", &bt[i], &pri[i]);
        p[i] = i + 1; // Assign process ID
    }

    // Sort by priority (ascending order)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pri[j] < pri[i]) {
                // Swap priorities
                int temp = pri[i];
                pri[i] = pri[j];
                pri[j] = temp;
                // Swap burst times
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                // Swap process IDs
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculate waiting and turnaround times
    wt[0] = 0; // First process has no waiting time
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1]; // Waiting time = sum of previous burst times
        total_wt += wt[i];
    }

    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i]; // Turnaround time = Burst Time + Waiting Time
        total_tat += tat[i];
        printf("p%d\t%d\t%d\t\t%d\t%d\n", p[i], bt[i], pri[i], wt[i], tat[i]);
    }

    // Calculate and print averages
    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}