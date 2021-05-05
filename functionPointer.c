#include <stdio.h>
#include <stdlib.h>

int add(int, int);
int mult(int, int);

int main(int argc, char const *argv[])
{
    /* code */

    int (*pf)(int, int);

    pf = add;
    int res1 = pf(2, 3); // addition de 2 et 3

    pf = mult;
    int res2 = pf(2, 3);

    printf("addition %d multiplicatin %d \n", res1, res2);

    return 0;
}

int add(int a, int b)
{
    return a + b;
}
int mult(int a, int b)
{
    return a * b;
}
