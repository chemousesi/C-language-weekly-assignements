#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum etat
{
    VALIDEE,
    ENCOURS,
    EXPEDIEE
};

struct comm
{
    int numeroC;
    int prix_exp;
    int prix_prod;
    enum etat etatC;
};
typedef struct comm commande;

/*déclarations des fonctions*/

//int rand();
//void srand(unsigned seed);
commande comAlear();
void affCommande(commande c);
void affExpediees(commande t[], int taille);
int nbCEC(commande t[], int taille);
int coutVal(commande T[], int taille);

#define NBC 10

int main()
{
    srand(time(NULL));
    commande tab_cmds[NBC];

    // initialisation
    for (int i = 0; i < NBC; i++)
    {
        tab_cmds[i] = comAlear(i);
    }
    // affichage de toutes les commandes
    for (int i = 0; i < NBC; i++)
    {
        affCommande(tab_cmds[i]);
    }
    printf("\nles commandes exepdiees :\n");

    affExpediees(tab_cmds, NBC);
    printf("\nle nombre de commandes expediees :\t%d", nbCEC(tab_cmds, NBC));
    printf("\nle cout total de prix d'expedition des commandes validees :\t%d", coutVal(tab_cmds, NBC));

    return 0;
}

commande comAlear(int num)
{
    int prix = rand() % (20) + 1;
    int valeur = rand() % (2000) + 1;
    enum etat etatc = rand() % 3;

    commande cmd = {num, prix, valeur, etatc};
    return cmd;
}

void affCommande(commande c)
{
    printf("commande n:\t%d\t%d\t%d\t", c.numeroC, c.prix_exp, c.prix_prod);
    switch (c.etatC)
    {
    case 0:
        printf("VALIDEE");
        break;
    case 1:
        printf("ENCOURS");
        break;
    case 2:
        printf("EXPEDIEE");
        break;
    default:
        printf("NOSTATUS");
        break;
    }
    printf("\n");
}

void affExpediees(commande t[], int taille)
{
    for (int i = 0; i < taille; i++)
    {
        if (t[i].etatC == 2)
            affCommande(t[i]);
    }
}

int nbCEC(commande t[], int taille)
{
    int cpt = 0;
    for (int i = 0; i < taille; i++)
    {
        if (t[i].etatC == 1)
            cpt++;
    }
    return cpt;
}

int coutVal(commande t[], int taille)
{
    int total = 0;
    for (int i = 0; i < taille; i++)
    {
        if (t[i].etatC == 0)
            total += t[i].prix_exp;
    }
    return total;
}