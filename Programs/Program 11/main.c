
//================================================
// Description: Write a program which accept file name from user and print all information about that file.
// Input: ExicutableFile FileNameToOpen
// Output: Print Stat of file
// Author: Ganesh Narayan Jaiwal
// Date: 13 Sept 2020
//================================================

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int args, char *argv[])
{
    int fd = 0;
    struct stat fileStat;

    if (args < 2)
    {
        printf("Error: Invalid number of arguments.\n");
        return -1;
    }
    if ((strcmp(argv[1], "h") == 0) ||
        (strcmp(argv[1], "H") == 0))
    {
        printf("Usage: ExicutableFile FileToOpen\n");
        return 0;
    }

    int s = open(argv[1], O_RDONLY);
    if (s == -1)
    {
        printf("File doesn't exist\n");
        return -1;
    }
    else
    {
        if (stat(argv[1], &fileStat) == -1)
        {
            printf("Error Occurred\n");
        }
        else
        {
            printf("\nFile iNode %d \n", fileStat.st_ino);
            printf("\nFile block size %ld \n", fileStat.st_blksize);
            printf("\nFile file size %ld \n", fileStat.st_size);
            printf("\nFile soft links %u \n", (unsigned int)fileStat.st_nlink);
            printf("\nFile Permissions User: ");
            printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
            printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
            printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
            printf("\n");
            printf("\nFile Permissions Group: ");
            printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
            printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
            printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
            printf("\n");
            printf("\nFile Permissions Other: ");
            printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
            printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
            printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
            printf("\n");
        }
    }

    return 0;
}
