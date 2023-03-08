#include <stdio.h>
#include <stdlib.h>

typedef struct obiecte
{
    float gi;
    float pi;
} obiecte;

struct r_node
{
    float p_actual, g_ramasa;
    struct r_node *parent, *right, *left;
};

typedef struct rucsac
{
    float profit_max;
    int nr_variante;
    struct r_node **variante;
    struct r_node *head;
} rucsac;

obiecte *citire(FILE *f, int *N, float *Gmax)
{
    int i, j;

    fscanf(f, "%d", N);
    fscanf(f, "%f", Gmax);
    obiecte *o = (obiecte *)malloc(sizeof(obiecte) * (*N));

    for (i = 0; i < *N; i++)
    {
        fscanf(f, "%f", &o[i].gi);
        fscanf(f, "%f", &o[i].pi);
    }

    return o;
}

void backtracking(obiecte *o, rucsac **r, struct r_node **node, int k, int N, float Gmax)
{
    int i;
    if (k == N)
    {
        if ((*r)->profit_max < (*node)->p_actual)
        {
            for (i = 0; i < (*r)->nr_variante; i++)
            {
                free((*r)->variante[i]);
                (*r)->variante[i] = NULL;
            }
            (*r)->profit_max = (*node)->p_actual;
            (*r)->nr_variante = 1;
            (*r)->variante[0] = (struct r_node *)malloc(sizeof(struct r_node));
            (*r)->variante[0] = (*node);
        }
        else if ((*r)->profit_max == (*node)->p_actual)
        {
            (*r)->nr_variante++;
            (*r)->variante[(*r)->nr_variante - 1] = (struct r_node *)malloc(sizeof(struct r_node));
            (*r)->variante[(*r)->nr_variante - 1] = (*node);
        }
    }
    else if (k < N)
    {
        if ((*node)->g_ramasa - o[k].gi >= 0)
        {
            (*node)->left = (struct r_node *)malloc(sizeof(struct r_node));
            (*node)->left->parent = (*node);
            (*node)->left->p_actual = (*node)->p_actual;
            (*node)->left->g_ramasa = (*node)->g_ramasa;
            (*node)->left->left = NULL;
            (*node)->left->right = NULL;

            (*node)->right = (struct r_node *)malloc(sizeof(struct r_node));
            (*node)->right->parent = (*node);
            (*node)->right->p_actual = (*node)->p_actual + o[k].pi;
            (*node)->right->g_ramasa = (*node)->g_ramasa - o[k].gi;
            (*node)->right->left = NULL;
            (*node)->right->right = NULL;

            backtracking(o, &(*r), &(*node)->left, k + 1, N, Gmax);
            backtracking(o, &(*r), &(*node)->right, k + 1, N, Gmax);
        }
        else
            backtracking(o, &(*r), &(*node), k + 1, N, Gmax);
    }
}

void afisare(rucsac *r)
{
    int i;
    struct r_node *x;
    printf("\n\n\nNumarul de variante de a adauga obiecte in ghiozdan pentru profitul maxim %.2f este:%d.\n", r->profit_max, r->nr_variante);
    for (i = 0; i < r->nr_variante; i++)
    {
        x = r->variante[i];
        printf("\nVarianta %d [perechi de tipul (greutate;profit)]: ", i + 1);
        while (x->parent != NULL)
        {
            if (x->p_actual != x->parent->p_actual && x->g_ramasa != x->parent->g_ramasa)
                printf("(%.2f ; %.2f) ; ", x->parent->g_ramasa - x->g_ramasa, x->p_actual - x->parent->p_actual);
            x = x->parent;
        }
    }
}

void stergere(struct r_node **r)
{
    if ((*r)->left == NULL && (*r)->right == NULL)
    {
        free(*r);
        (*r) = NULL;
    }
    else
    {
        if ((*r)->right != NULL)
            stergere(&(*r)->right);
        if ((*r)->left != NULL)
            stergere(&(*r)->left);
        free(*r);
        (*r) = NULL;
    }
}

int main()
{
    FILE *i1, *i2;
    i1 = (FILE *)malloc(sizeof(FILE));
    if (i1 = fopen("input1.txt", "rt") == NULL)
    {
        printf("Fisierul nu poate fi deschis.\n");
        exit(1);
    }
    i2 = (FILE *)malloc(sizeof(FILE));
    if (i2 = fopen("input2.txt", "rt") == NULL)
    {
        printf("Fisierul nu poate fi deschis.\n");
        exit(1);
    }

    int i, N1, N2;
    float Gmax1, Gmax2;
    obiecte *ob1, *ob2;
    rucsac *r1, *r2;

    ob1 = citire(i1, &N1, &Gmax1);
    r1 = (rucsac *)malloc(sizeof(rucsac));
    r1->head = (struct r_node *)malloc(sizeof(struct r_node));
    r1->head->parent = NULL;
    r1->head->right = NULL;
    r1->head->left = NULL;
    r1->head->p_actual = 0;
    r1->head->g_ramasa = Gmax1;
    r1->nr_variante = 0;
    r1->variante = (struct r_node **)malloc(N1 * sizeof(struct r_node *));
    r1->profit_max = 0;

    ob2 = citire(i2, &N2, &Gmax2);
    r2 = (rucsac *)malloc(sizeof(rucsac));
    r2->head = (struct r_node *)malloc(sizeof(struct r_node));
    r2->head->parent = NULL;
    r2->head->right = NULL;
    r2->head->left = NULL;
    r2->head->p_actual = 0;
    r2->head->g_ramasa = Gmax2;
    r2->nr_variante = 0;
    r2->variante = (struct r_node **)malloc(N2 * sizeof(struct r_node *));
    r2->profit_max = 0;

    backtracking(ob1, &r1, &r1->head, 0, N1, Gmax1);
    backtracking(ob2, &r2, &r2->head, 0, N2, Gmax2);

    afisare(r1);
    afisare(r2);

    free(ob1);
    ob1 = NULL;
    for (i = 0; i < r1->nr_variante; i++)
    {
        free((r1)->variante[i]);
        (r1)->variante[i] = NULL;
    }
    free(r1->variante);
    r1->variante = NULL;
    stergere(&r1->head);
    free(r1);
    r1 = NULL;

    free(ob2);
    ob2 = NULL;
    for (i = 0; i < r2->nr_variante; i++)
    {
        free((r2)->variante[i]);
        (r2)->variante[i] = NULL;
    }
    free(r2->variante);
    r2->variante = NULL;
    stergere(&r2->head);
    free(r2);
    r2 = NULL;

    fclose(i1);
    free(i1);
    i1 = NULL;
    fclose(i2);
    free(i2);
    i2 = NULL;

    return 0;
}