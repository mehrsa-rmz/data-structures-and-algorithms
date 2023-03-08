#include <stdio.h>
#include <stdlib.h>

void afisare(FILE *f, int n, int **t)
{
    int i, j;
    fprintf(f, "Solutia:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            fprintf(f, "%d   ", t[i][j]);
        fprintf(f, "\n");
    }
}

int valid(int n, int **t, int i, int j)
{
    int x, y;
    for (x = i - 1; x >= 0; x--)
        if (t[x][j] == 1)
            return 0;
    for (x = j - 1; x >= 0; x--)
        if (t[i][x] == 1)
            return 0;
    for (x = i + 1, y = j - 1; x < n && y >= 0; x++, y--)
        if (t[x][y] == 1)
            return 0;
    for (x = i - 1, y = j - 1; x >= 0 && y >= 0; x--, y--)
        if (t[x][y] == 1)
            return 0;
    return 1;
}

void BKT(FILE *f, int k, int n, int ***t)
{
    if (k == n)
    {
        afisare(f, n, *t);
        exit(1);
    }
    else
    {
            for (int j = 0; j < n; j++)
            {
                (*t)[j][k] = 1;
                if (valid(n, *t, j, k))
                    BKT(f, k + 1, n, &(*t));
                (*t)[j][k] = 0;
            }
    }
}

int main()
{
    FILE *i, *o;

    i = (FILE *)malloc(sizeof(FILE));
    if ((i = fopen("input.txt", "rt")) == NULL)
    {
        printf("Fisierul nu poate fi deschis.\n");
        exit(1);
    }
    o = (FILE *)malloc(sizeof(FILE));
    if ((o = fopen("output.txt", "wt")) == NULL)
    {
        printf("Fisierul nu poate fi deschis.\n");
        exit(1);
    }

    int j, k, n, **t;
    fscanf(i, "%d", &n);
    t = (int **)malloc(sizeof(int *) * n);
    for (j = 0; j < n; j++)
    {
        t[j] = (int *)malloc(sizeof(int) * n);
        for (k = 0; k < n; k++)
            t[j][k] = 0;
    }

    BKT(o, 0, n, &t);

    for (j = 0; j < n; j++)
    {
        free(t[j]);
        t[j] = NULL;
    }
    free(t);
    t = NULL;

    fclose(i);
    free(i);
    i = NULL;
    fclose(o);
    free(o);
    o = NULL;

    return 0;
}