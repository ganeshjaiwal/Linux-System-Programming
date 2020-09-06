#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int args, char *argv[])
{
    int fd = 0;
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
    }
    else
    {
        printf("File opened successfully.");
    }
    close(fd);
    return 0;
}