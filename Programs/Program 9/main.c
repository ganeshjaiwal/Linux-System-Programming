
//================================================
// Description: Write a program which accept file name and mode from user
// and then open that file in specified mode.
// Input: ExicutableFile FileNameToOpen
// Output: Print FD
// Author: Ganesh Narayan Jaiwal
// Date: 13 Sept 2020
//================================================

#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int args, char *argv[])
{
    int fd = 0, mode = -1;
    if (args < 2)
    {
        printf("Error: Invalid number of arguments.\n");
        return -1;
    }
    if ((strcmp(argv[1], "h") == 0) ||
        (strcmp(argv[1], "H") == 0))
    {
        printf("Usage: ExicutableFile FileToOpen ModeOfFile\n");
        printf("ModesOfFile: O_RDONLY, O_WRONLY, O_RDWR, O_CREAT, O_TRUNC, O_APPEND");
    }
    if (args < 3)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }
    if (strcmp(argv[2], "O_RDONLY") == 0)
    {
        mode = O_RDONLY;
    }
    else if (strcmp(argv[2], "O_WRONLY") == 0)
    {
        mode = O_WRONLY;
    }
    else if (strcmp(argv[2], "O_RDWR") == 0)
    {
        mode = O_RDWR;
    }
    else if (strcmp(argv[2], "O_CREAT") == 0)
    {
        mode = O_CREAT;
    }
    else if (strcmp(argv[2], "O_TRUNC") == 0)
    {
        mode = O_TRUNC;
    }
    else if (strcmp(argv[2], "O_APPEND") == 0)
    {
        mode = O_APPEND;
    }
    if (mode == -1)
    {
        printf("Error: Invalid file opening mode.\n");
        return -1;
    }

    fd = open(argv[1], mode);

    if (fd == -1)
    {
        printf("Error: Unable to open file.");
    }

    printf("File opened with FD: %d\n", fd);

    return 0;
}
