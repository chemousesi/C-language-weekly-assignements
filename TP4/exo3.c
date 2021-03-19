#include <stdio.h>
#include <stdlib.h>

typedef struct array
{
    int *ptr;
    int size;
} array;

// déclarations des fonctions
void array_print(array *t);
array *array_init(int);

int main()
{
    array *t = array_init(10);
    array_print(t); // 10 valeurs aleatoires, mais exactement 10.
    printf("\n");
    /*
    for (int i = 0; i < t->size; i++)
    {
        //array_set(t, i, i);
    }
    //array_print(t);
    printf("\n");
    // 0 1 2 3 4 5 6 7 8 9

    for (int i = 0; i < t->size; i++)
    {
        printf("%d ", array_get(t, i));
    }
    printf("\n");
    // 0 1 2 3 4 5 6 7 8 9

    //array_insert(t, 3, 42);
    //array_print(t);
    printf("\n");
    // 0 1 2 42 3 4 5 6 7 8 9

    //array_insert(t, 11, 43);
    //array_print(t);
    printf("\n");
    // 0 1 2 42 3 4 5 6 7 8 9 43

    //array_erase(t, 11);
    //array_print(t);
    printf("\n");
    // 0 1 2 42 3 4 5 6 7 8 9

    //array_erase(t, 3);
    //array_print(t);
    printf("\n");
    // 0 1 2 3 4 5 6 7 8 9

    //array_erase(t, 0);
    //array_print(t);
    printf("\n");
    // 1 2 3 4 5 6 7 8 9
    */
    return 0;
}

void array_print(array *t)
{
    for (int i = 0; i < (*t).size; i++)
    {
        printf("%d ", (*t).ptr[i]);
    }
    printf("\n");
}
array *array_init(int n)
{
    array *a;
    a = malloc(sizeof(array));
    if (a == NULL)
    {
        perror("allocation non reussie\n");
        return NULL;
    }

    (*a).ptr = malloc(n * sizeof(int));
    (*a).size = n;
    return a;
}