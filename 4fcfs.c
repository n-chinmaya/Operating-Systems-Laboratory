#include <stdio.h>

int main() {
    int n, pid[15], bt[15], wt[15];
    float total_wt = 0, total_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter process IDs and burst times (ID BT):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pid[i], &bt[i]);
    }

    wt[0] = 0; // First process has no waiting time

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1]; // Calculate waiting time
        total_wt += wt[i];            // Accumulate total waiting time
    }

    printf("\nProcess ID  Burst Time  Waiting Time  Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        int tat = wt[i] + bt[i];      // Calculate turnaround time
        total_tat += tat;            // Accumulate total turnaround time
        printf("%d           %d            %d              %d\n", pid[i], bt[i], wt[i], tat);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}