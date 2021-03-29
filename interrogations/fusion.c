#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void fusion(int *debut_a, int *fin_a, int *debut_b, int *fin_b, int *dest);

int main()
{
    int ta[] = {-3, -2, 88, 120, 500};
    int tb[] = {1, 10, 12, 30};
    int *tab = malloc(sizeof(ta) + sizeof(tb));
    assert(tab != NULL);

    fusion(ta, ta + 5, tb, tb + 4, tab);

    int taille = (sizeof(ta) + sizeof(tb)) / sizeof(int);
    for (int i = 0; i < taille; i++)
        printf("%d ", tab[i]);

    printf("\n");
}

void fusion(int *debut_a, int *fin_a, int *debut_b, int *fin_b, int *dest)
{

    while (debut_a < fin_a && debut_b < fin_b)
        if (*debut_a <= *debut_b)
            *dest++ = *debut_a++;
        else
            *dest++ = *debut_b++;

    if (debut_a < fin_a)
        memmove(dest, debut_a, (fin_a - debut_a) * sizeof(int));
    else
        memmove(dest, debut_b, (fin_b - debut_b) * sizeof(int));
}