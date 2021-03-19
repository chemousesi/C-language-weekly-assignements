#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *pt;
    pt = malloc(5 * sizeof(int));
    *pt = 10;
    *(pt + 1) = 20;
    *(pt + 12) = 30;

    return 0;
}