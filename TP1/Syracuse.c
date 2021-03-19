#include <stdio.h>
#include <stdlib.h>

void syracuse(int m);
int syracuse1_N(int n);

int main()
{
    //syracuse(27);
    syracuse1_N(8);
}

void syracuse(int m)
{
    int s = m;
    int vol = 0;
    //printf("Syracuse de %d\n", m);
    while (s != 1)
    {
        if (s % 2 == 0)
            s /= 2;
        else
            s = 3 * s + 1;
        //printf("%d\n", s);
        vol++;
    }

    printf("%d : %d\n", m, vol);
}

int syracuse1_N(int n)
{

    if (n < 1)
        return -1;
    for (int i = 1; i <= n; i++)
    {
        syracuse(i);
    }

    return 0;
}
