#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef struct
{
    int nbr;
    char **words;
} w_index;


int nbr_words(const char *s);
int word_len(const char *s);
char *extract_word(const char *w, int *pl);
void free_index(w_index *pi);

int main()
{
    char *s = "aa";

    printf("Nombre de mots:\t %s \t %d \n", s, nbr_words(s));
    printf("word len :\t %s \t %d\n", s, word_len(s));
    int new_l;
    char *new_s = extract_word(s, &new_l);
    printf("le mot copie : %s\n", new_s);

    



}

int nbr_words(const char *s)
{
    int cpt = 0;

    // on se place au premier caractère non vide
    int i = 0;
    while (s[i] != '\0' && s[i] == ' ')
    {
        i++;
    }

    bool in_word = false;
    for (; s[i] != '\0'; s++)
    {
        if (s[i] != ' ')
        {
            in_word = true;
            continue;
        }
        else if (in_word)
        {
            cpt++;
            in_word = false;
        }
    }
    if (in_word)
        cpt++;

    return cpt;
}

int word_len(const char *w)
{
    int cpt = 0;

    for (; *w; w++)
    {
        if (*w != ' ')
            cpt++;
    }
    return cpt;
}

char *extract_word(const char *w, int *pl)
{
    char *nw = malloc(word_len(w) + 1);
    assert(nw);
    int i = 0;
    for (; *w; w++)
    {
        nw[i] = *w;
        i++;
    }
    nw[i] = '\0';

    *pl = word_len(w);

    return nw;
}

void free_index(w_index *pi){

}
