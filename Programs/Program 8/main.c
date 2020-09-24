
//================================================
// Description: Program which accept file name from user and open that file.
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
    int fd = 0;
    if (args != 2)
    {
        printf("Error: Invalid number of arguments.");
        return -1;
    }
    if ((strcmp(argv[1], "h") == 0) ||
        (strcmp(argv[1], "H") == 0))
    {
        printf("Usage: ExicutableFile FileToOpen");
        return 0;
    }

    fd = open(argv[1], O_RDONLY);

    if (fd == -1)
    {
        printf("Error: Unable to open file.");
        return -1;
    }

    printf("File opened with FD: %d\n", fd);

    return 0;
}
