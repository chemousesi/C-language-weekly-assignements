#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 10
#define N 10

int aff_tab(int t[], int taille);
int max_tab(int t[], int taille);

int main()
{
    srand(time(NULL));
    //int m = 10;
    int tab[M];

    for (int i = 0; i < M; i++)
    {
        tab[i] = rand() % (N + 1);
    }
    aff_tab(tab, M);
    max_tab(tab, M);
}

int aff_tab(int t[], int taille)
{

    for (int i = 0; i < taille; i++)
    {
        printf("%d ", t[i]);
    }
    printf("\n");
    return 0;
}

int max_tab(int t[], int taille)
{
    int max = 0;

    for (size_t i = 0; i < taille; i++)
    {
        if (t[i] > t[max])
            max = i;
    }
    printf("le max est %d son indice %d", t[max], max);
    return max;
}