#include <stdio.h>
#include <stdlib.h>

// Shared variables
int mutex = 1, full = 0, empty = 3, item = 0;

void producer() {
    mutex--; // Lock the critical section
    full++;
    empty--;
    printf("Producer produces item %d\n", ++item);
    mutex++; // Unlock the critical section
}

void consumer() {
    mutex--; // Lock the critical section
    printf("Consumer consumes item %d\n", item--);
    full--;
    empty++;
    mutex++; // Unlock the critical section
}

int main() {
    int choice;

    printf("\n1. PRODUCER\n2. CONSUMER\n3. EXIT\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (empty > 0)
                    producer();
                else
                    printf("Buffer is FULL!\n");
                break;
            case 2:
                if (full > 0)
                    consumer();
                else
                    printf("Buffer is EMPTY!\n");
                break;
            case 3:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}