#include <stdio.h>
#include <dirent.h>

int main() {
    char dirName[100];
    DIR *dir;
    struct dirent *entry;

    printf("Enter directory name: ");
    scanf("%s", dirName);

    dir = opendir(dirName);
    if (!dir) {
        printf("Cannot open directory.\n");
        return 1;
    }

    while ((entry = readdir(dir)))
        printf("%s\n", entry->d_name);

    closedir(dir);
    return 0;
}