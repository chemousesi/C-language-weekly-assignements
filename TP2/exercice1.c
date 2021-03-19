#include <stdio.h>

int f(int);
int g(int);

int main()
{
    printf("Value of  f(20): \t %d \n", f(20));
    return 0;
}

int g(int n)
{
    if (n == 1)
        return 1;
    else
        return 3 * f(n / 2);
}

int f(int n)
{
    if (n == 1)
        return 2;
    else
        return 2 * g(n - 1);
}
