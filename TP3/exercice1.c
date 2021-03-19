#include <stdio.h>

#define NB 2

typedef struct
{
    int x;
    int y;
} point;

void swap(int *pa, int *pb);

int main()
{
    int x, y;
    x = 5;
    y = 6;
    int tab[NB] = {1, 10};
    point p = {.x = 5, .y = 20};
    // echange entre entier
    printf("echange d'entier :\n");
    printf("Valeur de x avant echange : % d\n", x);
    printf("Valeur de y avant echange : % d\n", y);
    swap(&x, &y);
    printf("Valeur de x apres echange : % d\n", x);
    printf("Valeur de y apres echange : % d\n", y);
    // dans un tableau
    printf("echange dans un tableau:\n");
    printf("Valeur de tab[0] avant echange : % d\n", tab[0]);
    printf("Valeur de tab[NB - 1] avant echange : % d\n", tab[NB - 1]);
    swap(tab, &tab[NB - 1]);
    printf("Valeur de tab[0] apres echange : % d\n", tab[0]);
    printf("Valeur de tab[NB - 1] apres echange : % d\n", tab[NB - 1]);
    // dans une structure
    printf("echange dans un structure:\n");
    printf("Valeur de p.x avant echange : % d\n", p.x);
    printf("Valeur de p.y avant echange : % d\n", p.y);
    swap(&p.x, &p.y);
    printf("Valeur de p.x apres echange : % d\n", p.x);
    printf("Valeur de p.y apres echange : % d\n", p.y);
}

void swap(int *pa, int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
    return;
}