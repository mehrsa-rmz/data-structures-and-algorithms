#include "utils.h"

FILE *openFile(const char *filename, const char *mode)
{
    FILE *file = fopen(filename, mode);
    if (file == NULL)
    {
        printf("Fisierul %s nu a putut fi deschis!", filename);
        printf("Iesire program!");
        exit(EXIT_FAILURE);
    }
    return file;
}

int *readArray(FILE *file, int *size)
{
    fscanf(file, "%d", size);

    int *arr = NULL;
    arr = (int*)malloc(sizeof(int) * (*size));

    for (int i = 0; i < *size; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    return arr;
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return;
}