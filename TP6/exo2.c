#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int nbr_words(const char *s);

int main()
{
    char *s = " aa a    ";

    printf("Nombre de mots %d \n", nbr_words(s));
}

int nbr_words(const char *s)
{
    int cpt = 0;

    // on se place au premier caractère non vide
    int i = 0;
    while (s[i] == ' ')
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
