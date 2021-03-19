#include <stdio.h>
#include <stdbool.h>
#define NB 4

void sort(int t[], int start, int end);
void swap(int *pa, int *pb);
void sort_rec(int t[], int start, int end);
void sort_rec_pt(int *start, int *end, int *nb);
void afficher(int, int t[]);
void opt_sort(int *start, int *end, int *nb);

int main()
{
    int t[4] = {2, 1, 8, 4};
    //sort(t, 0, NB);
    //sort_rec(t, 0, NB);
    // tri bulles récursiff et avec des pointeurs
    // sort_rec_pt(&t[0], &t[NB - 1]); // il faut ajouter le paramètre du nombre d'opérations
    afficher(NB, t);

    // Exemple :
    int tab[] = {3, 8, 1, 50, 3, 9, 0, 4, 5, 6, -7, 9};
    int taille_tab = sizeof(tab) / sizeof(tab[0]);

    int nb_ops = 0;

    sort_rec_pt(&tab[0], &tab[taille_tab], &nb_ops);
    afficher(taille_tab, tab);
    printf("number of operations with bubble sort :\t%d\n", nb_ops);

    int tab2[] = {3, 8, 1, 50, 3, 9, 0, 4, 5, 6, -7, 9};
    printf("\n");
    nb_ops = 0;
    opt_sort(&tab2[0], &tab2[taille_tab], &nb_ops);
    afficher(taille_tab, tab2);
    printf("number of operations with the optimized bubble sort :\t%d\n", nb_ops);

    return 0;
}

void sort(int t[], int start, int end)
{
    int i, j;
    for (i = start; i < end - 1; i++)

        for (j = start; j < end - i - 1; j++)
            if (t[j] > t[j + 1])
                swap(&t[j], &t[j + 1]);
}
void sort_rec(int t[], int start, int end)
{

    for (int i = start; i < end - 1; i++)
        if (t[i] > t[i + 1])
            swap(&t[i], &t[i + 1]);
    if (end > start)
        sort_rec(t, start, end - 1);
}
void sort_rec_pt(int *start, int *end, int *nb_ops)
{

    for (int *i = start; i < end - 1; i++)
        if (*i > *(i + 1))
        {
            *nb_ops = *nb_ops + 1;
            swap(i, i + 1);
        }

    if (end > start)
        sort_rec_pt(start, end - 1, nb_ops);
}
void opt_sort(int *start, int *end, int *nb_ops)
{
    bool swapped = false;
    for (int *i = start; i < end - 1; i++)
        if (*i > *(i + 1))
        {
            *nb_ops = *nb_ops + 1;
            swapped = true;
            swap(i, i + 1);
        }
    if (swapped == false)
        return;
    if (end > start)
        opt_sort(start, end - 1, nb_ops);
}

void swap(int *pa, int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
    return;
}

void afficher(int taille, int t[])
{
    for (int i = 0; i < taille; i++)
    {
        printf(" %d |", t[i]);
    }
    printf("\n");
}