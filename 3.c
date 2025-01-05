#include <stdio.h>
#include <unistd.h>

int main() {
    if (fork() == 0) {
        printf("Child process ID: %d\n", getpid());
    } else {
        printf("Parent process ID: %d\n", getpid());
    }
    return 0;
}