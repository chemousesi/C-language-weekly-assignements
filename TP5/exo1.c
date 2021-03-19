#include <stdio.h>
#include <stdlib.h>

typedef struct pile_amortie
{
    int occupation;
    int capacite;
    int *elements;
} pile_amortie;

//déclarations
pile_amortie *alloue_pile_amortie();
void libere_pile_amortie(pile_amortie *pile);
int depile_pile_amortie(pile_amortie *pile, int *e);
pile_amortie *copie_pile_amortie(pile_amortie *pile);
int empile_pile_amortie(pile_amortie *pile, int n);
void afficher(pile_amortie *pile);

/** MAIN */
int main()
{

    pile_amortie *pile = alloue_pile_amortie();
    empile_pile_amortie(pile, 1);
    empile_pile_amortie(pile, 2);
    empile_pile_amortie(pile, 3);
    int x;
    depile_pile_amortie(pile, &x);
    printf("element depile : %d\n", x);

    pile_amortie *pile2 = copie_pile_amortie(pile);
    afficher(pile2);

    afficher(pile);

    return 0;
}

pile_amortie *alloue_pile_amortie()
{

    pile_amortie *pile = malloc(sizeof(pile_amortie));
    if (pile == NULL)
        return NULL;
    pile->occupation = 0;
    pile->capacite = 1;

    (*pile).elements = malloc(sizeof(int));

    if (pile->elements == NULL)
        return NULL;

    return pile;
}

void libere_pile_amortie(pile_amortie *pile)
{
    if (pile != NULL)
        free(pile);
}

int empile_pile_amortie(pile_amortie *pile, int n)
{

    if (pile->occupation + 1 > pile->capacite) // tester si ça va déborder
    {
        pile->elements = realloc(pile->elements, 2 * pile->capacite * sizeof(int));
        pile->capacite = pile->capacite * 2;
        if (pile->elements == NULL)
            return -1;
    }
    pile->elements[pile->occupation] = n;
    pile->occupation++;
    return 0;
}

int depile_pile_amortie(pile_amortie *pile, int *e)
{

    if (pile->capacite <= 2 || pile->occupation < (pile->capacite / 4))
    {
        pile->elements = realloc(pile->elements, ((pile->capacite) / 2) * sizeof(int));
        pile->capacite = pile->capacite / 2;

        return 0;
    }
    // ici dépiler
    *e = pile->elements[pile->occupation - 1];
    pile->occupation--;
    return 0;
}

pile_amortie *copie_pile_amortie(pile_amortie *pile)
{
    pile_amortie *pile2 = alloue_pile_amortie();
    if (pile2 == NULL)
        return NULL;

    for (int i = 0; i < pile->occupation; i++)
    {
        empile_pile_amortie(pile2, pile->elements[i]);
    }
    return pile2;
}
void afficher(pile_amortie *pile)
{
    if (pile->occupation == 0)
    {
        printf("pile vide \n");
    }

    for (int i = pile->occupation - 1; i >= 0; i--)
    {
        printf("%d ", pile->elements[i]);
    }
    printf("\n");
}