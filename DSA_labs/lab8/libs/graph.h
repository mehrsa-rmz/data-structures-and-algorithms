#ifndef GRAPH_H
#define GRAPH_H

typedef struct ListNode
{

    int vertexNr;
    struct ListNode *next;

} node;

typedef struct graph_list
{

    int V;            // nr of vertices
    int E;            // nr of edges
    node **listHeads; // vector of list heads

} graph_list;

typedef struct graph_matrix
{

    int V;        // nr of vertices
    int E;        // nr of edges
    int **matrix; // matrix

} graph_matrix;

graph_list *matrixToList(graph_matrix *);
node *push_values(node *, int);
void free_graph_matrix(graph_matrix **);
void print_graph_matrix(graph_matrix *);
void print_graph_list(graph_list *);
graph_matrix *listToMatrix(graph_list *);
void free_graph_list(graph_list **);
int **findPaths(graph_matrix *);

#endif