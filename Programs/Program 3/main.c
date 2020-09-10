
//================================================
// Description: Write a program which accept name from command line argument and display it on screen.
// Input: ExicutableFile AnyString
// Output: Print given string
// Author: Ganesh Narayan Jaiwal
// Date: 10 Sept 2020
//================================================

#include <stdio.h>
#include <string.h>

int main(int args, char *argv[])
{
    if (args < 2)
    {
        printf("Use exicutableName 'h' for details.");
        return -1;
    }

    if ((strcmp(argv[1], "h") == 0) ||
        (strcmp(argv[1], "H") == 0))
    {
        printf("Use: ExicutableFileName \"AnyString\"");
        return 0;
    }

    printf("Given String is: '%s'", argv[1]);
    return 0;
}
