#include <stdio.h>
#include <stdlib.h>

void affiche(int t[], int, int);
int *build_tab(int a, int n);

int main(void)
{
    printf("\nbuild tab\n");
    int *tab = build_tab(0, 15);
    printf("tab : %p\n", tab);
    affiche(tab, 0, 15); // SEG_FAULT!
    return 0;
}

void affiche(int t[], int a, int b)
{
    for (int i = a; i < b - 1; i++)
    {
        printf("%d, ", t[i]);
    }
    printf("%d\n", t[b - 1]);
}

int *build_tab(int a, int n)
{
    //int t[n]; // erreur de segmentation // l'adresse est locale déclarée statique elle est perdue juste apres la fin de l'exécution

    int *t; // allocation dynamique dans tas, l'@ sera préservée
    t = malloc(n * sizeof(int));

    if (t == NULL)
    {
        perror("tableau null \n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        t[i] = a + i;
    }
    printf("t : %p : ", t); // TEST
    affiche(t, 0, 15);      // TEST
    return t;
}
// WARNING! // ça va faire le warning du local variable // function returns address of local variable
