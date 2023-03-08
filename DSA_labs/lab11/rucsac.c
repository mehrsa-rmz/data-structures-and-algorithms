#include <stdio.h>
#include <stdlib.h>

typedef struct obiecte
{
    int idx;
    float gi;
    float pi;
    float raport;
} obiecte;

obiecte *citire(FILE *f, int *N, float *Gmax)
{
    int i, j;

    fscanf(f, "%d", N);
    fscanf(f, "%f", Gmax);
    obiecte *o = (obiecte *)malloc(sizeof(obiecte) * (*N));

    for (i = 0; i < *N; i++)
    {
        fscanf(f, "%f", o[i].gi);
        fscanf(f, "%f", o[i].pi);
        o[i].raport = o[i].pi / o[i].gi;
        o[i].idx=i;
    }

    return o;
}

int *rezolvare(obiecte **o, int N, float Gmax)
{
    int i, j, k, r = N - 1, l = 0, m = (r + l) / 2;
    int n1 = m - l + 1;
    int n2 = r - m;
    obiecte* L=(obiecte*)malloc(sizeof(obiecte)*n1);
    obiecte* R=(obiecte*)malloc(sizeof(obiecte)*n2);

    for (i = 0; i < n1; i++)
        L[i] = (*o)[l + i];
    for (j = 0; j < n2; j++)
        R[j] = (*o)[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].raport >= R[j].raport)
        {
            (*o)[k] = L[i];
            i++;
        }
        else
        {
            (*o)[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        (*o)[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        (*o)[k] = R[j];
        j++;
        k++;
    }
    free(L); L=NULL;
    free(R); R=NULL;
    
    float val, profit = 0, x;
    i = 0;

    while (Gmax > 0)
    {
        if ((*o)[i].gi < Gmax)
        {
            profit = profit + (*o)[i].pi;
            Gmax = Gmax - (*o)[i].gi;
        }
        else
        {
            x = (*o)[i].raport * Gmax;
            profit = profit + x;
            Gmax = 0;
        }
        i++;
    }

    int rucsac[i];
    for(j=0; j<i; j++)
    rucsac[j]=(*o)[j].idx;

    return rucsac;
}

void afisare (FILE *f, int* rucsac)
{
    int nr=sizeof(*rucsac)/sizeof(int);
    for(int i=0; i<nr; i++)
    fprintf(f, "%d   ", rucsac[i]);
}
