#include <stdio.h>
#include <stdlib.h>

int remplir_tab(int t[], int taille);
int eratosthene(int sup);
int aff_tab(int t[], int taille);

int main()
{
    int input;
    scanf("%d", &input);
    eratosthene(input);
}

int remplir_tab(int t[], int taille)
{
    for (int i = 0; i < taille; i++)
    {
        t[i] = i;
    }
    return 0;
}

int eratosthene(int sup)
{
    int taille = sup + 1;
    int t[taille];

    int index = 2; //  on commence de 2
    remplir_tab(t, taille);
    while (index < taille / 2)
    {
        aff_tab(t, taille);
        if (t[index] == 0)
            index++;
        else
        {
            for (int i = index + 1; i < taille; i++)
            {
                if (t[i] % index == 0)
                    t[i] = 0; // effacement
            }
            index++;
        }
    }
    return 0;
}

int aff_tab(int t[], int taille)
{
    for (int i = 2; i < taille; i++)
    {
        if (t[i] == 0)
            continue;
        printf("%d ", t[i]);
    }
    printf("\n");
    return 0;
}