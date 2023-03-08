#ifndef BST_H
#define BST_H

typedef struct binary_search_tree{
	
	int data;
	struct binary_search_tree *left, *right;
	struct binary_search_tree *parent;
	
}BST;

BST* createBalanced(int , FILE* );
bool checkBST(BST *root, int , int );
BST* createBSTNode(int );
BST* insertInBST(BST* , int );
BST* findNode(BST* , int );
BST* findMax(BST* );
BST* findMin(BST* );
BST* findSuccesor(BST* );
BST* findPredecessor(BST* );
void bstToArray(BST* , BST** , int* , int , int );
int numberOfNodesInBetween(BST* , int , int );
#endif