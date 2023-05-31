#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename or directory>\n", argv[0]);
        return 1;
    }
    char *name = argv[1];
    struct stat fileStat;
    if (stat(name, &fileStat) == -1) {
        printf("File or directory does not exist.\n");
        return 1;
    }
    if (S_ISREG(fileStat.st_mode))
        printf("It is a file.\n");
    else if (S_ISDIR(fileStat.st_mode))
        printf("It is a directory.\n");
    printf("Permissions:\n");
    printf("Read permission: %s\n", (fileStat.st_mode & S_IRUSR) ? "Yes" : "No");
    printf("Write permission: %s\n", (fileStat.st_mode & S_IWUSR) ? "Yes" : "No");
    printf("Execute permission: %s\n", (fileStat.st_mode & S_IXUSR) ? "Yes" : "No");
    return 0;
}





#input-------
[21691a3245@GDLC ~]$ vi 10a.c
[21691a3245@GDLC ~]$ cc 10a.c
[21691a3245@GDLC ~]$ ./a.out perm.sh
#output------
It is a file.
Permissions:
Read permission: Yes
Write permission: Yes
Execute permission: No
