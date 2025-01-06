#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SEGSIZE 100 // Size of the shared memory segment

int main() {
    key_t key;
    int shmid;
    char *segptr;
    char buff[] = "poooda";

    // Generate a unique key for shared memory
    key = ftok(".", 's');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Create or get the shared memory segment
    shmid = shmget(key, SEGSIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    printf("Shared memory ID: %d\n", shmid);

    // Attach the shared memory segment
    segptr = (char *)shmat(shmid, NULL, 0);
    if (segptr == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // Write data to shared memory
    printf("Writing data to shared memory...\n");
    strcpy(segptr, buff);
    printf("Data written: %s\n", buff);

    // Read data from shared memory
    printf("Reading data from shared memory...\n");
    printf("Data read: %s\n", segptr);

    // Detach and remove the shared memory segment
    if (shmdt(segptr) == -1) {
        perror("shmdt");
        exit(1);
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    printf("Shared memory segment removed successfully.\n");
    return 0;
}