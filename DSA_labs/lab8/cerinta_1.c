#include "utils.h"

graph_list *matrixToList(graph_matrix *graph)
{
    graph_list *list = (graph_list *)malloc(sizeof(graph_list));
    if (list == NULL)
    {
        printf("Eroare de memorie");
        return NULL;
    }
    list->E = graph->E;
    list->V = graph->V;
    list->listHeads = (node **)malloc(sizeof(node *) * (list->V));
    for (int i = 0; i < list->V; i++)

        list->listHeads[i] = NULL;

    for (int i = 0; i < list->V; i++)
    {
        for (int j = 0; j < list->V; j++)
            if (graph->matrix[i][j] == 1)
                list->listHeads[i] = push_values(list->listHeads[i], j);
    }

    free_graph_matrix(&graph);
    return list;
}

void free_graph_matrix(graph_matrix **graph)
{
    for (int i = 0; i < (*graph)->V; i++)
    {
        free((*graph)->matrix[i]);
        (*graph)->matrix[i] = NULL;
    }
    free((*graph)->matrix);
    (*graph)->matrix = NULL;
    free((*graph));
    (*graph) = NULL;
}

node *push_values(node *root, int val)
{
    node *aux = root, *newNode = (node *)malloc(sizeof(node));
    newNode->vertexNr = val;
    newNode->next = NULL;
    if (root == NULL)
        return newNode;

    for (aux = root; aux->next != NULL; aux = aux->next)
        ;
    aux->next = newNode;
    return root;
}

void print_graph_list(graph_list *graph)
{
    node *j;
    for (int i = 0; i < graph->V; i++)
    {
        printf("\nLista de adiacenta a nodului %d:  ", i);
        j = graph->listHeads[i];
        while (j)
        {
            printf("%d;  ", j->vertexNr);
            j = j->next;
        }
    }
    free(j);
}
