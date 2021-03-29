#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    int s = 0;
    for (int i = 0; i < argc; i++)
    {
        s += atoi(argv[i]);
    }
    printf("la somme calculee est : %d", s);

    return 0;
}
