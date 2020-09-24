
//================================================
// Description: Write a program which accept file name and on mode and that program
// check whether our process can access that file in accepted mode or not .
// Input: ExicutableFile FileNameToOpen
// Output: Print FD
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
    int fd = 0, mode = -1, checkVal;

    if (args < 2)
    {
        printf("Error: Invalid number of arguments.\n");
        return -1;
    }
    if ((strcmp(argv[1], "h") == 0) ||
        (strcmp(argv[1], "H") == 0))
    {
        printf("Usage: ExicutableFile FileToOpen ModeOfFile\n");
        printf("ModesOfFile: O_RDONLY, O_WRONLY, O_RDWR");
        return 0;
    }
    if (args < 3)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }
    checkVal = access(argv[1], F_OK);
    if (checkVal != 0)
    {
        if (errno == ENOENT)
            printf("%s No such file or directory.\n", argv[1]);
        else if (errno == EACCES)
            printf("%s Permission denied.\n", argv[1]);
        return -1;
    }
    if (strcmp(argv[2], "O_RDONLY") == 0)
    {
        mode = R_OK;
    }
    else if (strcmp(argv[2], "O_WRONLY") == 0 || strcmp(argv[2], "O_RDWR") == 0)
    {
        mode = W_OK;
    }
    if (mode == -1)
    {
        printf("Error: Invalid file opening mode.\n");
        return -1;
    }

    checkVal = access(argv[1], mode);
    if (checkVal != 0)
    {
        if (errno == ENOENT)
            printf("%s No such file or directory.\n", argv[1]);
        else if (errno == EACCES)
            printf("%s Permission denied.\n", argv[1]);
        return -1;
    }

    printf("File %s can be access using %s mode.", argv[1], argv[2]);

    return 0;
}
