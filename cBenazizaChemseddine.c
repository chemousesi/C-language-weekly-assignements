/* Benaziza Chemseddine 22017844 Eddine Groupe MI1*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char *sans_lettre(const char *s, char x);

int main(int argc, char const *argv[])
{

    // exo 1

    char *s1 = "";
    char *s2 = "aaaaa";
    char *s3 = "ala ma kota";

    printf("%s -> %s\n", s1, sans_lettre(s1, 'a'));
    printf("%s -> %s\n", s2, sans_lettre(s2, 'a'));
    printf("%s -> %s\n", s3, sans_lettre(s3, 'a'));

    return 0;
}



char *sans_lettre(const char *s, char x)
{
    int cmp = 0; // chars differents de x
    for (int i = 0; i < strlen(s); i++)
        if (s[i] != x)
            cmp++;

    if (cmp == 0)
        return "";

    char *res = malloc(cmp * sizeof(char));
    assert(res != NULL);  

    int j = 0;
    for (int i = strlen(s) - 1; i >= 0; i--)
        if (s[i] != x)
        {
            res[j] = s[i];
            j++;
        }

    res[j] = '\0';

    return res;
}
