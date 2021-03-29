#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf("argc vaur : %d\n", argc);
    if (argc != 2)
    {
        printf("%s code\n", argv[0]);
        exit(0);
    }
    int a = atoi(argv[1]);
    exit(a);
}
