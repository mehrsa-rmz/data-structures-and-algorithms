#include "utils.h"

graph_matrix *listToMatrix(graph_list *graph)
{
    graph_matrix *mtrx = (graph_matrix *)malloc(sizeof(graph_matrix));
    if (mtrx == NULL)
    {
        printf("Eroare de memorie");
        return NULL;
    }
    mtrx->V = graph->V;
    mtrx->E = graph->E;
    mtrx->matrix = (int **)calloc(mtrx->V, sizeof(int *));
    for (int i = 0; i < mtrx->V; i++)
        mtrx->matrix[i] = (int *)calloc(mtrx->V, sizeof(int));

    node *j;
    for (int i = 0; i < graph->V; i++)
    {
        j = graph->listHeads[i];
        while (j)
        {
            if (i != j->vertexNr)
                mtrx->matrix[i][j->vertexNr] = 1;
            j = j->next;
        }
    }
    free(j);
    free_graph_list(&graph);
    return mtrx;
}

void free_graph_list(graph_list **graph)
{
    node *j;
    for (int i = 0; i < (*graph)->V; i++)
    {
        j = (*graph)->listHeads[i];
        while (j)
        {
            (*graph)->listHeads[i] = (*graph)->listHeads[i]->next;
            free(j);
            j = NULL;
            j = (*graph)->listHeads[i];
        }
        free((*graph)->listHeads[i]);
        (*graph)->listHeads[i] = NULL;
    }
    free(j);
    j = NULL;
    free((*graph)->listHeads);
    (*graph)->listHeads = NULL;
    free((*graph));
    (*graph) = NULL;
}

void print_graph_matrix(graph_matrix *graph)
{
    printf("Matricea de adiacenta a grafului este:\n");
    for (int i = 0; i < graph->V; i++)
    {
        for (int j = 0; j < graph->V; j++)
            printf("%d   ", graph->matrix[i][j]);
        printf("\n");
    }
}