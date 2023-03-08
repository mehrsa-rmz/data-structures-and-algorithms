#include "utils.h"

int **findPaths(graph_matrix *graph)
{
    int n = graph->V;
    int **paths=(int**) malloc(sizeof(int*)*n);

    for (int i = 0; i < n; i++)
        {
            paths[i]=(int*) malloc(sizeof(int)*n);
            for (int j = 0; j < n; j++)
                paths[i][j] = graph->matrix[i][j];
        }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j && paths[i][j] == 0)
                    paths[i][j] = paths[i][k] * paths[k][j];
    
    return paths;
}