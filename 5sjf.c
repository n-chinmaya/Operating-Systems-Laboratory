#include <stdio.h>

int main() {
    int n, pid[15], bt[15], wt[15], tat[15];
    float total_wt = 0, total_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter process IDs and burst times (ID BT):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pid[i], &bt[i]);
    }

    // Sort processes by burst time (SJF logic)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                // Swap burst times and process IDs
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }

    // Calculate waiting and turnaround times
    wt[0] = 0; // First process has no waiting time
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        total_wt += wt[i];
    }

    printf("\nProcess ID  Burst Time  Waiting Time  Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        total_tat += tat[i];
        printf("%d           %d            %d              %d\n", pid[i], bt[i], wt[i], tat[i]);
    }

    // Print average waiting and turnaround times
    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}