#include "list.h"
#include "utils.h"

node *makeNode(int data, node *next)
{
    node *nod = (node *)malloc(sizeof(node));
    nod->data = data;
    nod->next = next;
    return nod;
}

node *makeList(FILE *file)
{
    int x;
    node *head, *nod;
    head = nod;

    if (fscanf(file, "%d", &x) != EOF)
        nod = makeNode(x, NULL);

    while (fscanf(file, "%d", &x) != EOF)
        if (x >= nod->data)
        {
            head = makeNode(x, nod);
            nod = head;
        }

    return head;
}

void print(node *head)
{
    printf("\nElementele din lista sunt:\n%d;  ", head->data);
    while (head->next != NULL)
    {
        head = head->next;
        printf("%d;  ", head->data);
    }
}