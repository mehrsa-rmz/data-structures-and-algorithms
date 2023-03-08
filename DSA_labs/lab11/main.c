#include "rucsac.c"

int main()
{
    FILE* i1, *i2, *o1, *o2;
    if(i1=fopen("input1.txt", "r+")==NULL)
    {
        printf("Fisierul nu poate fi deschis.\n");
        exit(1);
    }
    if(i2=fopen("input2.txt", "r+")==NULL)
    {
        printf("Fisierul nu poate fi deschis.\n");
        exit(1);
    }
    if(o1=fopen("output1.txt", "w+")==NULL)
    {
        printf("Fisierul nu poate fi deschis\n.");
        exit(1);
    }
    if(o2=fopen("output2.txt", "w+")==NULL)
    {
        printf("Fisierul nu poate fi deschis.\n");
        exit(1);
    }

    int N1, Gmax1, N2, Gmax2, *r1, *r2;
    obiecte *ob1, *ob2;
    ob1=citire(i1, &N1, &Gmax1);
    ob2=citire(i2, &N2, &Gmax2);
    r1=rezolvare(&ob1, N1, Gmax1);
    r2=rezolvare(&ob2, N2, Gmax2);
    afisare(o1, r1);
    afisare(o2, r2);

    fclose(i1);
    fclose(i2);
    fclose(o1);
    fclose(o2);

    return 0;
}
