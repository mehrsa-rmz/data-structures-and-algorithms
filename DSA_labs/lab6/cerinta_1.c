#include "utils.h"

BST *createBalanced(int N, FILE *f)
{
    int val;
    if (N > 0)
    {
        BST *root = (BST *)malloc(sizeof(BST));
        fscanf(f, "%d", &val);
        root->data = val;
        root->left = createBalanced(N / 2, f);
        root->right = createBalanced(N - 1 - N / 2, f);
        return root;
    }
    else
        return NULL;
}

bool checkBST(BST *root, int max_value, int min_value)
{
    if (root == NULL)
        return true;
    if (root->data > min_value && root->data < max_value)
    {
        return checkBST(root->left, root->data, min_value) && checkBST(root->right, max_value, root->data);
    }
    else
        return false;
}

BST *createBSTNode(int data)
{
    BST *node = (BST *)malloc(sizeof(BST));
    node->data = data;
    node->left = node->right = node->parent = NULL;
    return node;
}

BST *insertInBST(BST *root, int data)
{
    if (root == NULL)
        return createBSTNode(data);
    if (data < root->data)
    {
        root->left = insertInBST(root->left, data);
        root->left->parent = root;
    }
    else if (data > root->data)
    {
        root->right = insertInBST(root->right, data);
        root->right->parent = root;
    }
    return root;
}