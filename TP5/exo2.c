#include <stdio.h>
#include <stdlib.h>

#define affiche_nbr(a) printf("%p (%lu)\n", a, (unsigned long)a)

//declarations

// variables globales
char c1, c2;
int x1, x2;
int *p1, *p2;

int main()
{
    char cm1, cm2;
    int xm1, xm2;
    int *pm1, *pm2;

    // variables globales
    affiche_nbr(&c1);
    affiche_nbr(&c2);
    affiche_nbr(&x1);
    affiche_nbr(&x2);
    affiche_nbr(&p1);
    affiche_nbr(&p2);

    // variables locales dans le main
    affiche_nbr(&cm1);
    affiche_nbr(&cm2);
    affiche_nbr(&xm1);
    affiche_nbr(&xm2);
    affiche_nbr(&pm1);
    affiche_nbr(&pm2);

    printf("\%zu \n", sizeof(int));
    printf("\%zu", sizeof(int));
}

void f1(int *p)
{
    int i = 7;
    char c = 'A';
    affiche_nbr(p);
    affiche_nbr(*p);
    affiche_nbr(&p);
    affiche_nbr();
    affiche_nbr();
    affiche_nbr();
    affiche_nbr();

}