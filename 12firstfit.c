#include<stdio.h>

int main() {
    int bsize[10], psize[10], bno, pno, allocation[10], i, j;

    // Initialize allocation array (-1 means no process allocated)
    for (i = 0; i < 10; i++) {
        allocation[i] = -1;
    }

    // Input block sizes
    printf("Enter the number of blocks: ");
    scanf("%d", &bno);
    printf("Enter the size of each block:\n");
    for (i = 0; i < bno; i++) {
        scanf("%d", &bsize[i]);
    }

    // Input process sizes
    printf("Enter the number of processes: ");
    scanf("%d", &pno);
    printf("Enter the size of each process:\n");
    for (i = 0; i < pno; i++) {
        scanf("%d", &psize[i]);
    }

    // First-fit allocation
    for (i = 0; i < pno; i++) { // For each process
        for (j = 0; j < bno; j++) { // Check each block
            if (bsize[j] >= psize[i]) { // If block can fit the process
                allocation[i] = j; // Assign block to process
                bsize[j] -= psize[i]; // Reduce block size
                break;
            }
        }
    }

    // Display allocation results
    printf("\nProcess\t\tSize\t\tBlock\n");
    for (i = 0; i < pno; i++) {
        if (allocation[i] != -1) {
            printf("P%d\t\t%d\t\tB%d\n", i + 1, psize[i], allocation[i] + 1);
        } else {
            printf("P%d\t\t%d\t\tNot Allocated\n", i + 1, psize[i]);
        }
    }

    return 0;
}