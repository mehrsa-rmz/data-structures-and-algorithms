#include <stdio.h>
#include <stdlib.h>

int **bordare(int N, int **img)
{
    int i;
    for (i = 0; i <= N + 1; i++)
    {
        img[0][i] = -1;
        img[i][0] = -1;
        img[i][N + 1] = -1;
        img[N + 1][i] = -1;
    }
    return img;
}

int **citire(FILE *f, int *N, int **img)
{
    int i, j;

    fscanf(f, "%d", N);
    img = (int **)malloc(sizeof(int *) * (*N + 2));
    for (i = 0; i < *N + 2; i++)
        img[i] = (int *)malloc(sizeof(int) * (*N + 2));

    img = bordare(*N, img);
    for (i = 1; i <= *N; i++)
        for (j = 1; j <= *N; j++)
            fscanf(f, "%d", &img[i][j]);
    return img;
}

void umplere(int i, int j, int nr_ob, int ***img)
{
    if ((*img)[i][j] == 0)
    {
        (*img)[i][j] = nr_ob;
        umplere(i, j + 1, nr_ob, &(*img));
        umplere(i, j - 1, nr_ob, &(*img));
        umplere(i + 1, j, nr_ob, &(*img));
        umplere(i - 1, j, nr_ob, &(*img));
        umplere(i - 1, j - 1, nr_ob, &(*img));
        umplere(i - 1, j + 1, nr_ob, &(*img));
        umplere(i + 1, j - 1, nr_ob, &(*img));
        umplere(i + 1, j + 1, nr_ob, &(*img));
    }
}

int **rezolvare(int N, int **img, int *nr_ob)
{
    (*nr_ob) = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (img[i][j] == 0)
            {
                (*nr_ob)++;
                umplere(i, j, (*nr_ob), &img);
            }
    return img;
}

void afisare(FILE *f, int N, int **img, int nr_ob)
{
    fprintf(f, "%d\n", nr_ob);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            if (img[i][j] == -1)
                fprintf(f, "  %d", img[i][j]);
            else
                fprintf(f, "   %d", img[i][j]);
        fprintf(f, "\n");
    }
}

int main()
{
    FILE *i1, *i2, *o1, *o2;

    i1 = (FILE *)malloc(sizeof(FILE));
    if ((i1 = fopen("input1.txt", "rt")) == NULL)
    {
        printf("Fisierul nu poate fi deschis.\n");
        exit(1);
    }
    i2 = (FILE *)malloc(sizeof(FILE));
    if ((i2 = fopen("input2.txt", "rt")) == NULL)
    {
        printf("Fisierul nu poate fi deschis.\n");
        exit(1);
    }

    o1 = (FILE *)malloc(sizeof(FILE));
    if ((o1 = fopen("output1.txt", "wt")) == NULL)
    {
        printf("Fisierul nu poate fi deschis.\n");
        exit(1);
    }
    o2 = (FILE *)malloc(sizeof(FILE));
    if ((o2 = fopen("output2.txt", "wt")) == NULL)
    {
        printf("Fisierul nu poate fi deschis.\n");
        exit(1);
    }

    int i, N1, N2, **img1, **img2, nr_ob1 = 0, nr_ob2 = 0;

    img1 = citire(i1, &N1, img1);
    img2 = citire(i2, &N2, img2);

    img1 = rezolvare(N1, img1, &nr_ob1);
    img2 = rezolvare(N2, img2, &nr_ob2);

    afisare(o1, N1, img1, nr_ob1);
    afisare(o2, N2, img2, nr_ob2);

    for (i = 0; i <= N1 + 1; i++)
    {
        free(img1[i]);
        img1[i] = NULL;
    }
    free(img1);
    img1 = NULL;

    for (i = 0; i <= N2 + 1; i++)
    {
        free(img2[i]);
        img2[i] = NULL;
    }
    free(img2);
    img2 = NULL;

    fclose(i1);
    free(i1);
    i1 = NULL;
    fclose(i2);
    free(i2);
    i2 = NULL;

    fclose(o1);
    free(o1);
    o1 = NULL;
    fclose(o2);
    free(o2);
    o2 = NULL;

    return 0;
}