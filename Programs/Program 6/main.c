
//================================================
// Description: Write a program which accept file name from user and read whole file.
// Input: ExicutableFile FileToReadData
// Output: PrintSuccessOn Read Success
// Author: Ganesh Narayan Jaiwal
// Date: 10 Sept 2020
//================================================

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int args, char *argv[])
{
    FILE *fd;

    if (args != 2)
    {
        printf("Error: Invalid number of argument.");
        return -1;
    }

    if ((strcmp(argv[1], "h") == 0) ||
        (strcmp(argv[1], "H") == 0))
    {
        printf("Use: ExicutableFileName NameOfFileToOpen");
        return 0;
    }

    fd = fopen(argv[1], "rb");

    if (fd == NULL)
    {
        printf("Error: Can not open file.");
        return -1;
    }

    fseek(fd, 0, SEEK_END);
    long fsize = ftell(fd);
    fseek(fd, 0, SEEK_SET);

    char *string = malloc(fsize + 1);
    fread(string, 1, fsize, fd);

    string[fsize] = '\0';

    printf("%s: ", string);

    fclose(fd);
    return 0;
}
