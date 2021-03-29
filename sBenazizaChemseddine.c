/* Benaziza Chems 22017844 Eddine Groupe MI1*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct
{
    int x;
    int y;
} point;

void afficher_point(point q);
void translate(point *p, int dist, char dir);
void translate_tab(int len, point v[], int dist, char dir);

int main(int argc, char const *argv[])
{

   
    point tab[] = {{.x = 1, .y = 1},
                   {.x = -1, .y = -1},
                   {.x = 1, .y = -1}};

    int taille = sizeof(tab) / sizeof(point);

    translate(&tab[0], 10, 'x');
    translate_tab(2, tab + 1, -50, 'y');

    for (int i = 0; i < taille; i++)
    {
        afficher_point(tab[i]);
    }

    return 0;
}

void translate(point *p, int dist, char dir)
{
    if (p == NULL)
        return;
    if (dir == 'x')
        p->x = p->x + dist;
    else if (dir == 'y')
        p->y = p->y + dist;
}

void translate_tab(int len, point v[], int dist, char dir)
{

    for (int i = 0; i < len; i++)
        translate(&v[i], dist, dir);
}

void afficher_point(point q)
{
    printf("(%d,%d)\n", q.x, q.y);
}