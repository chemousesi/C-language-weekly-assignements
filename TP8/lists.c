#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct element element;
struct element
{
    int val;
    element *next;
    element *previous;
};

// declarations des fonctions
element *cons_list();
void add_fst_list(element *L, int v);
void add_lst_list(element *L, int v);
int isempty_list(element *L);
int len_list(element *L);
void print_list(element *L);
int del_fst_list(element *L);
int del_lst_list(element *L);
void free_list(element *L);
element *copy_list(element *L);
void insert_prev_list(element *p, int v);
void insert_next_list(element *p, int v);
element *get_elet_list(element *L, int v);
void concat_list(element *l1, element *l2);
int get_val_list(element *L, int i);
void reverse_list(element *L);
element *fusion_list(element *l1, element *l2);

int main(int argc, char const *argv[])
{

    element *list = cons_list();
    print_list(list);

    int value;
    for (int i = 1; i < argc; i++)
    {
        value = atoi(argv[i]);
        add_lst_list(list, value);
    }
    //del_fst_list(list);
    //del_lst_list(list);

    print_list(list);
    printf("element %d est %d\n", 3, get_val_list(list, 3));

    // construire une nouvelle liste

    element *new_list = cons_list();
    add_fst_list(new_list, 80);
    add_fst_list(new_list, 30);
    add_fst_list(new_list, 20);

    // make the fusion between new_list and the list entered in the command line

    element *fus_list = fusion_list(list, new_list);
    printf("this is the fused list:\n");
    print_list(fus_list);

    //printf("this is the new list \n");
    //print_list(new_list);

    reverse_list(fus_list);
    printf("reversed list :\n");
    print_list(fus_list);

    return 0;
}

element *cons_list()
{
    element *el = malloc(sizeof(element));
    assert(el != NULL);
    el->next = el;
    el->previous = el;

    return el;
}
void add_fst_list(element *L, int v)
{
    element *el = cons_list();
    el->val = v;
    el->next = L->next;

    el->next->previous = el;

    el->previous = L;
    L->next = el;
}
void add_lst_list(element *L, int v)
{
    element *el = cons_list();
    el->val = v;
    el->previous = L->previous;

    el->previous->next = el;

    el->next = L;
    L->previous = el;
}

/**
 * comparaison par rapport à une liste simlpement chainée 
 * insertion debut : temps constant o(1) pour SC et DC  
 * insertion fin : SC o(n), DC temps constant o(1) 
 * */

int isempty_list(element *L)
{
    return L->next == L;
}
int len_list(element *L)
{
    element *n = L->next;
    int count = 0;
    for (count = 0; n != L; count++, n = n->next)
    {
        /*boucle vide*/
    }
    return count;
}
void print_list(element *L)
{
    if (isempty_list(L))
    {
        printf("[empty list]\n");
        return;
    }
    element *n = L->next;
    while (n != L)
    {
        printf("%d ", n->val);
        n = n->next;
    }
    printf("\n");
}

int del_fst_list(element *L)
{
    if (isempty_list(L))
    {
        perror("empty list, impossible to delete \n");
        return 0;
    }
    element *to_delete = L->next;
    L->next = to_delete->next;
    to_delete->next->previous = L;
    int deleted_value = to_delete->val;
    free(to_delete);
    return deleted_value;
}

int del_lst_list(element *L)
{
    if (isempty_list(L))
    {
        perror("empty list, impossible to delete \n");
        return -1;
    }
    element *to_delete = L->previous;
    L->previous = to_delete->previous;
    to_delete->previous->next = L;
    int deleted_value = to_delete->val;
    free(to_delete);
    return deleted_value;
}
void free_list(element *L)
{
    element *n = L->next;
    while (n != L)
    {
        element *sauv = n;
        n = n->next;
        free(sauv);
    }
    free(L);
}

element *copy_list(element *L)
{
    element *new_list = cons_list();
    element *n = L->next;
    while (n != L)
    {
        add_lst_list(new_list, n->val);
        n = n->next;
    }

    return new_list;
}
void insert_prev_list(element *p, int v)
{
    element *n = cons_list();
    n->val = v;

    n->previous = p->previous;
    n->previous->next = n;

    n->next = p;
    p->previous = n;
}
void insert_next_list(element *p, int v)
{

    element *n = cons_list();
    n->val = v;

    n->next = p->next;
    n->next->previous = n;

    n->previous = p;
    p->next = n;
}

void del_list(element *p)
{
    p->previous->next = p->next;
    p->next->previous = p->previous;
    free(p);
}

element *get_elet_list(element *L, int v)
{
    element *n = L->next;
    while (n != L)
    {
        if (n->val == v)
            return n;
        n = n->next;
    }
    return NULL;
}
void concat_list(element *l1, element *l2)
{
    /*insère la
    *  liste l2 en tête de la liste l1 
    */
    element *n = l2->previous;
    while (n != l2)
    {
        add_fst_list(l1, n->val);
        n = n->previous;
    }
}
// oui cette opération est efficace car on a pas a décaler et chaqu insertion a un cout constant

int get_val_list(element *L, int i)
{

    if (i >= len_list(L))
    {
        perror("range out of list length\n");
        return -1;
    }

    element *n = L->next;
    int j = 0;
    while (j < i && n != L)
    {
        j++;
        n = n->next;
    }

    return n->val;
} // elle n'est pas efficace car elle necessite un parcours

void reverse_list(element *L)
{
    if (L == NULL)
        return;

    element *c, *n, *p;
    c = L;
    do
    {
        n = c->next;
        p = c->previous;
        c->next = p;
        c->previous = n;
        c = c->previous;
    } while (c != L);
}

element *fusion_list(element *l1, element *l2)
{
    element *new_list = cons_list();
    element *n1 = l1->next;
    element *n2 = l2->next;

    while (n1 != l1 && n2 != l2)
    {
        if (n1->val <= n2->val)
        {
            add_lst_list(new_list, n1->val);
            n1 = n1->next;
        }
        else
        {
            add_lst_list(new_list, n2->val);
            n2 = n2->next;
        }
    }
    if (n1 == l1)
        while (n2 != l2)
        {
            add_lst_list(new_list, n2->val);
            n2 = n2->next;
        }
    else
        while (n1 != l1)
        {
            add_lst_list(new_list, n1->val);
            n1 = n1->next;
        }

    return new_list;
}
