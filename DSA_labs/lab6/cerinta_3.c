#include "utils.h"

void bstToArray(BST *root, BST **arr, int *size, int max_value, int min_value)
{
    *size = 0;
    BST *aux = root;
    root = findMin(root);
    arr[*size] = root;
    while (root != findMax(aux))
    {
        root = findSuccesor(root);
        (*size) = (*size) + 1;
        arr[*size] = root;
    }
    (*size) = (*size) + 1;
}

int numberOfNodesInBetween(BST *root, int max_value, int min_value)
{
    int count = 1;
    BST *aux = root;
    root = findMin(root);

    while (root != findMax(aux))
    {
        root = findSuccesor(root);
        count++;
    }
    return count;
}
