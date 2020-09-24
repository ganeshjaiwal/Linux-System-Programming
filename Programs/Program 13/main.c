
//================================================
// Description: Write a program which accept file name from user and read whole file.
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
#include <stdlib.h>

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

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        printf("File doesn't exist\n");
        return -1;
    }

        close(fd);

    return 0;
}
