
//================================================
// Description: Write a program which accept file name and number of bytes from user and read that number of bytes from file.
// Input: ExicutableFile FileNameToOpen NoOfBytesToRead
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

    if (args < 2)
    {
        printf("Error: Invalid number of arguments.\n");
        return -1;
    }
    if ((strcmp(argv[1], "h") == 0) ||
        (strcmp(argv[1], "H") == 0))
    {
        printf("Usage: ExicutableFile FileToOpen NoOfBytesToRead\n");
        return 0;
    }

    if (args < 3)
    {
        printf("Error: Invalid number of arguments.\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        printf("File doesn't exist\n");
        return -1;
    }

    char *buffer = (char *)calloc(atoi(argv[2]), sizeof(char));

    int readByte = read(fd, buffer, atoi(argv[2]));

    printf("Bytes read: %d", readByte);

    printf("Data read from file: %s", buffer);

    close(fd);

    return 0;
}
