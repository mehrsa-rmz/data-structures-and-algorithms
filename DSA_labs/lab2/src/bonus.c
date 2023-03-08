#include "utils.h"
#include "counting.h"

//----- Counting Sort -----

int *countingSort(int *arr, int dim)
{
    int i, v[50];
    for (i = 0; i < dim; i++)
        v[arr[i]]++;
    int k = 0;
    for (i = 0; i < dim; i++)
    {
        while (v[k] == 0)
            k++;
        arr[i] = k;
        v[k]--;
    }
    return v;
}

/**
 * //TODO: Care este complexitatea spatiala si cea temporala?
 * De ce nu este mai folosit?
 * Complexitatea spatiala este O(dim) si cea temporala este O(dim*2).
 * Nu este mai folosit deoarece nu se pliaza decat pe cazul in care avem numere naturale.
 * De asemenea, daca vectorul (de numere naturale) are valoarea maxima foarte mare se pierde mult timp la parcurgerea vectorului de frecventa.
 */