
//================================================
// Description: Write a program which accept filename and string from user and write that string into file.
// Input: ExicutableFile FileToOpen StringToWriteIntoFile
// Output: Success
// Author: Ganesh Narayan Jaiwal
// Date: 11 Sept 2020
//================================================

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int main(int args, char *argv[])
{
    FILE *fd;

    if (args != 3)
    {
        printf("Error: Invalid number of argument.");
        return -1;
    }

    if ((strcmp(argv[1], "h") == 0) ||
        (strcmp(argv[1], "H") == 0))
    {
        printf("Use: ExicutableFileName NameOfFileToOpen StringToWriteIntoFile");
        return 0;
    }

    fd = fopen(argv[1], "a");

    if (fd == NULL)
    {
        printf("Error: Can not open file.");
        return -1;
    }

    fseek(fd, 0, SEEK_END);
    long fsize = ftell(fd);

    fwrite(argv[2], 1, strlen(argv[2]), fd);

    fclose(fd);
    return 0;
}