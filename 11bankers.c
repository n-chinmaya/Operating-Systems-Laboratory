#include <stdio.h>

int main() {
    int p, r, i, j, k, allocated[5][3], max[5][3], need[5][3], available[3];
    int done[5] = {0}, safeSequence[5], count = 0;

    // Input the number of processes and resources
    printf("Enter the number of processes and resources: ");
    scanf("%d %d", &p, &r);

    // Input Allocation and Max matrices
    printf("Enter the Allocation matrix (%dx%d):\n", p, r);
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &allocated[i][j]);

    printf("Enter the Max matrix (%dx%d):\n", p, r);
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    // Input Available resources
    printf("Enter the Available resources (%d values): ", r);
    for (i = 0; i < r; i++)
        scanf("%d", &available[i]);

    // Calculate Need matrix
    printf("\nNeed matrix:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            need[i][j] = max[i][j] - allocated[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    // Find the Safe Sequence
    while (count < p) {
        int found = 0;
        for (i = 0; i < p; i++) {
            if (!done[i]) {
                for (j = 0; j < r; j++)
                    if (need[i][j] > available[j])
                        break;

                if (j == r) { // All resources can be allocated
                    for (k = 0; k < r; k++)
                        available[k] += allocated[i][k];

                    safeSequence[count++] = i;
                    done[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) { // No process could be executed
            printf("\nNo safe sequence exists.\n");
            return 1;
        }
    }

    // Print Safe Sequence
    printf("\nSafe sequence: ");
    for (i = 0; i < count; i++)
        printf("P%d ", safeSequence[i]);
    printf("\n");

    return 0;
}