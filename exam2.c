#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct
{
    int x;
    int y;
} point;

char *sans_lettre(const char *s, char x);
void afficher_point(point q);
void translate(point *p, int dist, char dir);
void translate_tab(int len, point v[], int dist, char dir);
int main(int argc, char const *argv[])
{

    // exo 1

    char *s = "";
    char *s2 = "aaaaa";
    char *s3 = "ala ma kota";

    printf("%s\n", sans_lettre(s, 'a'));
    printf("%s\n", sans_lettre(s2, 'a'));
    printf("%s\n", sans_lettre(s3, 'a'));

    // test exo 2

    point tab[] = {{.x = 1, .y = 1},
                   {.x = -1, .y = -1},
                   {.x = 1, .y = -1}};

    translate(&tab[0], 10, 'x');
    translate_tab(2, tab + 1, -50, 'y');

    for (int i = 0; i < 3; i++)
    {
        afficher_point(tab[i]);
    }

    return 0;
}

char *sans_lettre(const char *s, char x)
{
    int cmp = 0; // chars nonx
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] != x)
            cmp++;
    }

    if (cmp == 0)
        return "";

    char *res = malloc(cmp * sizeof(char));
    assert(res != NULL);

    int j = 0;
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        if (s[i] != x)
        {
            res[j] = s[i];
            j++;
        }
    }
    res[j] = '\0';

    return res;
}

void translate(point *p, int dist, char dir)
{
    if (p == NULL)
        return;

    if (dir == 'x')
    {
        p->x = p->x + dist;
    }
    else if (dir == 'y')
        p->y = p->y + dist;
}

void translate_tab(int len, point v[], int dist, char dir)
{

    for (int i = 0; i < len; i++)
    {
        translate(&v[i], dist, dir);
    }
}

void afficher_point(point q)
{
    printf("(%d,%d)\n", q.x, q.y);
}