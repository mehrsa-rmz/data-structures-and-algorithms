#include "tree.h"
#include "stack.h"

TreeNode *createBalanced(int N, FILE *f)
{
    int val;
    if (N > 0)
    {
        TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
        fscanf(f, "%d", &val);
        root->val = val;
        root->left = createBalanced(N / 2, f);
        root->right = createBalanced(N - 1 - N / 2, f);
        return root;
    }
    else
        return NULL;
}

void inorderIterative(TreeNode *root, TreeNode **arr, int size)
{
    Stack *S = createStack(size);
    int i = 0;
    while (1)
    {
        while (root)
        {
            push(S, root);
            root = root->left;
        }
        if (isEmpty(S))
            break;
        root = pop(S);
        arr[i++] = root;
        root = root->right;
    }
    free(S);
}

void deleteTree(TreeNode *root)
{
    if (root)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

TreeNode *LCA(TreeNode *root, TreeNode *n1, TreeNode *n2)
{
    TreeNode *l, *r;
    if (!root)
        return NULL;
    if (root == n1 || root == n2)
        return root;
    l = LCA(root->left, n1, n2);
    r = LCA(root->right, n1, n2);
    if (l && r)
        return root;
    if (l == NULL)
        return r;
    return l;
}