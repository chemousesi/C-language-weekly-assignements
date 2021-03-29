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

void free_index(w_index *pi)
{
    for (pi->words; pi->words < pi->words[pi->nbr]; pi->words++)
    {
        for (*(pi->words); *(pi->words) < strlen(pi->words); pi->words)
        {
            free(*(pi->words));
        }
    }
}
