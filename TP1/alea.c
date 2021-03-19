#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand();
void srand(unsigned seed);
int stat(int, int);
int main()
{
    srand(time(NULL));
    int r = rand();

    if (r % 2 == 0)
        printf("%d est pair\n", r);
    else
        printf("%d est impair\n", r);

    stat(50, 200);
}

int stat(int m, int n)
{

    if (m > n)
    {
        printf(" valeurs non acceptées \n");
        return -1;
    }
    srand(time(NULL));

    int k = n + m / 2;

    int r = rand() % (k + 1);

    int cpt = 0;  // compteur total
    int cpt1 = 0; // compteur des entiers dans le premier intervale
    int cpt2 = 0; // compteur des entier dans le deuxième intervale

    while (r <= n)
    {
        if (r < m)
            cpt1++;
        else if (r > m)
            cpt2++;
        cpt++;
        r = rand() % (k + 1);
    }

    printf("pourcentage :\n");
    printf("d'entiers tires dans l'intervalle [0, m[ est : %d\n ", (cpt1 * 100 / cpt));
    printf("d'entiers tires dans l'intervalle [m, n[ est : %d\n ", (cpt2 * 100 / cpt));

    return 0;
}
