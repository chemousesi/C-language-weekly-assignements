#include <stdio.h>
#define NB 4

void minmax(int n, int t[], int *pmin, int *pmax);
void occurences(int n, int t[], int e, int *pocc, int *first);
void occurences_bis(int n, int t[], int e, int *pocc, int **first);

int main()
{
    int a, b;
    int t[NB] = {5, 1, 7, 1};
    minmax(NB, t, &a, &b);
    printf("indice du min  : %d indice du max : %d\n", a, b);
    int occ, premier_indice;
    int x = 1;
    occurences(NB, t, x, &occ, &premier_indice);
    printf("nombre d'occurence de : %d est : %d, avec premier indice : %d\n", x, occ, premier_indice);
    int *adr_prem;
    occurences_bis(NB, t, x, &occ, &adr_prem);
    printf("nombre d'occurence de : %d est : %d, avec adresse memoire de la première occurence : %pd\n", x, occ, adr_prem);
    printf("\nindice %d", adr_prem - t);
}

void minmax(int n, int t[], int *pmin, int *pmax)
{
    *pmin = t[0];
    *pmax = t[0];

    for (int i = 0; i < n; i++)
    {
        if (t[i] > *pmax)
            *pmax = i;
        else if (t[i] < *pmin)
            *pmin = i;
    }
}
void occurences(int n, int t[], int e, int *pocc, int *first)
// retourne dans first le premier indice
{
    int premier = 1;
    *pocc = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i] == e)
        {
            *pocc = *pocc + 1;
            if (premier)
            {
                *first = i; // indice de la première occurence
                premier = 0;
            }
        }
    }
}
void occurences_bis(int n, int t[], int e, int *pocc, int **first)
// retourne dans first le pointeur de la premiere occurence de e dans le tableau
{
    int premier = 1;
    *pocc = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i] == e)
        {
            *pocc = *pocc + 1;
            if (premier)
            {
                *first = &t[i]; // adresse de la première occurence
                premier = 0;
            }
        }
    }
}
