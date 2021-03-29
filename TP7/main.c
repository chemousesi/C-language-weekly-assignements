#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "afficheur.c"
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

node *cons_tree(int val, node *left, node *right);
void free_tree(node *t);
int size_tree(node *t);
int sum_tree(node *t);
int depth_tree(node *t);
void print_abr(node *t);
node *insert_abr(node *t, int val);
node *max_abr(node *t);
node *min_abr(node *t);
int check_abr(node *t);
node *delete_abr(node *t, int val);

int main(int argc, char const *argv[])
{
    node *t;
    t = cons_tree(1, cons_tree(10, NULL, NULL),
                  cons_tree(6, cons_tree(4, NULL, NULL), NULL));

    pretty_print(t);
    printf("size tree is  %d\n", size_tree(t));
    printf("sum tree is  %d\n", sum_tree(t));
    printf("depth tree is %d\n", depth_tree(t));

    node *t2 = NULL;
    int vals[10] = {8, 3, 1, 2, 6, 4, 7, 10, 14, 13};
    for (int i = 0; i < 10; i++)
    {
        t2 = insert_abr(t2, vals[i]);
    }
    pretty_print(t2);
    printf("min dans l'abr %d \n", min_abr(t2)->val);
    printf("max dans l'abr %d \n", max_abr(t2)->val);
    printf("t est an ABR %d \n", check_abr(t));
    printf("t2 est an ABR %d \n", check_abr(t2));

    t2 = delete_abr(t2, 8);
    t2 = delete_abr(t2, 3);
    t2 = delete_abr(t2, 4);
    t2 = delete_abr(t2, 1);

    pretty_print(t2);

    return 0;
}

node *cons_tree(int val, node *left, node *right)
{

    node *racine = malloc(sizeof(node));
    assert(racine != NULL);
    racine->val = val;
    racine->left = left;
    racine->right = right;

    return racine;
}
void free_tree(node *t)
{
    if (t == NULL)
        return;

    free_tree(t->left);
    free_tree(t->right);
    free(t);
}
int size_tree(node *t)
{
    if (t == NULL)
        return 0;
    return size_tree(t->left) + size_tree(t->right) + 1;
}

int sum_tree(node *t)
{
    if (t == NULL)
        return 0;
    return sum_tree(t->left) + sum_tree(t->right) + t->val;
}

int depth_tree(node *t)
{
    if (t == NULL)
        return 0;
    return MAX(depth_tree(t->left), depth_tree(t->right)) + 1;
}

void print_abr(node *t)
{
    if (t == NULL)
        return;
    print_abr(t->left);
    printf("%d ", t->val);
    print_abr(t->right);
}

// insertion
node *insert_abr(node *t, int val)
{
    if (t == NULL)
        return cons_tree(val, NULL, NULL);
    else if (t->val == val)
        return t;
    if (val < t->val)
        return cons_tree(t->val, insert_abr(t->left, val), t->right);
    else // val > t-> val
        return cons_tree(t->val, t->left, insert_abr(t->right, val));
}

node *search_abr(node *t, int val)
{
    if (t == NULL)
        return t;
    if (t->val == val)
        return t;

    if (val < t->val)
        return search_abr(t->left, val);
    else
        return search_abr(t->right, val);
}

node *max_abr(node *t)
{
    if (t == NULL)
        return NULL;
    else if (t->right == NULL)
        return t;
    else
        return max_abr(t->right);
}

node *min_abr(node *t)
{
    if (t == NULL)
        return NULL;
    else if (t->left == NULL)
        return t;
    else
        return min_abr(t->left);
}

int check_abr(node *t)
{
    if (t == NULL)
        return 1;
    if (max_abr(t)->val < min_abr(t)->val)
        return 0;
    return check_abr(t->left) && check_abr(t->right);
}

node *delete_abr(node *t, int val)
{
    if (t == NULL)
        return NULL;
    if (val < t->val)
        t->left = delete_abr(t->left, val);
    else if (val > t->val)
        t->right = delete_abr(t->right, val);
    // egalité
    else if (t->right == NULL && t->left == NULL)
    {
        free(t);
        return NULL;
    }
    else if (t->right == NULL)
    {
        node *sauv = t->left;
        free(t);
        return sauv;
    }
    else if (t->left == NULL)
    {
        node *sauv = t->right;
        free(t);
        return sauv;
    }
    else
    {
        node *max = max_abr(t->left);

        int temp = t->val;
        t->val = max->val;
        max->val = temp;

        t->left = delete_abr(t->left, max->val);
    }

    return t;
}