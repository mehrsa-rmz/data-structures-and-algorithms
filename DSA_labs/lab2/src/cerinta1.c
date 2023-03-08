#include "merge.h"
#include "quick.h"
#include "utils.h"

//----- MergeSort -----

void merge(int *arr, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int *arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int middle = left + (right - left) / 2;
    mergesort(arr, left, middle);
    mergesort(arr, middle + 1, right);
    merge(arr, left, middle, right);
}

//----- Quick Sort -----

void swap(int *x, int *y)
{
    int t;
    t = *x;
    *x = *y;
    *y = t;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

//----- Analiza functiilor -----

/**
 * //TODO: Care dintre metodele anterior implementate reprezinta metode de sortare stabile
 * si care reprezinta metode de sortare instabile? Argumentati.
 * Merge sort este stabila, deoarece mentine ordinea relativa a inregistrarilor cu chei egale.
 * Quick sort nu este stabil, deoarece doua elemente cu valoare egala nu isi pastreaza ordinea precedenta sortarii.
 */