
//================================================
// Description: This Program is to get number form user as cmd argument and add them
// Input: exicutableFile No1 No2
// Output: additionOfNos
// Author: Ganesh Narayan Jaiwal
// Date: 10 Sept 2020
//================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int args, char *argv[])
{
    int no1 = 0, no2 = 0, addition = 0;

    if (args < 2)
    {
        printf("Use exicutableName 'h' for details.");
        return -1;
    }

    if ((strcmp(argv[1], "h") == 0) ||
        (strcmp(argv[1], "H") == 0))
    {
        printf("Use: ExicutableFileName No1 No2");
        return 0;
    }

    if (args != 3)
    {
        printf("Invalid number of arguments.");
        return -1;
    }

    no1 = atoi(argv[1]);
    no2 = atoi(argv[2]);

    addition = no1 + no2;

    printf("Addition of %d and %d is %d.", no1, no2, addition);

    return 0;
}
