#include <stdio.h>

int main() {
    int bsize[10], psize[10], bno, pno, allocation[10], fragment[10], i, j;

    // Initialize allocation array
    for (i = 0; i < 10; i++) {
        allocation[i] = -1; // -1 means no process allocated to this block
    }

    // Input number of blocks and their sizes
    printf("Enter number of blocks: ");
    scanf("%d", &bno);
    printf("Enter size of each block: ");
    for (i = 0; i < bno; i++) {
        scanf("%d", &bsize[i]);
    }

    // Input number of processes and their sizes
    printf("Enter number of processes: ");
    scanf("%d", &pno);
    printf("Enter size of each process: ");
    for (i = 0; i < pno; i++) {
        scanf("%d", &psize[i]);
    }

    // Best Fit Allocation Algorithm
    for (i = 0; i < pno; i++) {
        int bestIndex = -1; // No suitable block yet
        for (j = 0; j < bno; j++) {
            if (bsize[j] >= psize[i]) { // Block can fit the process
                if (bestIndex == -1 || bsize[j] < bsize[bestIndex]) {
                    bestIndex = j; // Update the best fit block index
                }
            }
        }

        if (bestIndex != -1) { // Allocate the process
            allocation[bestIndex] = i; // Assign process to block
            fragment[bestIndex] = bsize[bestIndex] - psize[i]; // Calculate fragment
            bsize[bestIndex] = 0; // Mark block as used
        }
    }

    // Display allocation results
    printf("\nBlock no.\tSize\t\tProcess no.\t\tProcess size\t\tFragment");
    for (i = 0; i < bno; i++) {
        printf("\n%d\t\t%d\t\t", i + 1, bsize[i] + (allocation[i] != -1 ? psize[allocation[i]] : 0));
        if (allocation[i] != -1) {
            printf("%d\t\t\t%d\t\t\t%d", allocation[i] + 1, psize[allocation[i]], fragment[i]);
        } else {
            printf("Not Allocated\t\t-\t\t\t-");
        }
    }
    return 0;
}