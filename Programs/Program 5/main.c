
//================================================
// Description: Write a program which accept file name and read first 5 characters from it.
// Input: ExicutableFile FileNameToRead
// Output: Print Characters
// Author: Ganesh Narayan Jaiwal
// Date: 10 Sept 2020
//================================================

#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int args, char *argv[])
{
    int fd = 0;
    int noOfBytesRead = 0;

    char buffer[200];

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

    fd = open(argv[1], O_RDONLY);

    if (fd == -1)
    {
        printf("Error: Can not open file.");
        return -1;
    }

    noOfBytesRead = read(fd, buffer, 5);
    // READ => fileDiscriptor, emptyBuffertoReadData, NoOfBytesToRead

    if (noOfBytesRead != 5)
    {
        printf("Error: File read error.");
        close(fd);
        return -1;
    }
    else
    {
        printf("Read data is: %s", buffer);
    }
    close(fd);
    return 0;
}
