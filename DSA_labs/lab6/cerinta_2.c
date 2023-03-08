#include "utils.h"

BST *findNode(BST *root, int data)
{

    while (root)
    {
        if (root->data == data)
            return root;
        else if (root->data > data)
            root = root->left;
        else
            root = root->right;
    }

    return NULL;
}

BST *findMax(BST *root)
{
    while (root->right)
        root = root->right;
    return root;
}

BST *findMin(BST *root)
{
    while (root->left)
        root = root->left;
    return root;
}

BST *findSuccesor(BST *root)
{
    if (root->right)
        return findMin(root->right);

    else
    {
        while (root != root->parent->left && root->parent != NULL)
            root = root->parent;
        return root->parent;
    }
}

BST *findPredecessor(BST *root)
{
    if (root->left)
        return findMax(root->left);

    else
    {
        while (root != root->parent->right && root->parent != NULL)
            root = root->parent;
        return root->parent;
    }
}
