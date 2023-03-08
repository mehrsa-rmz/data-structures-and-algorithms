#include "list.h"
#include "utils.h"

node *removeDuplicates(node *list)
{
    node *nod, *aux;
    nod = list;
    while (nod->next != NULL)
    {
        if (nod->data != nod->next->data)
            nod = nod->next;
        else
        {
            aux = nod->next;
            nod->next = nod->next->next;
            free(aux);
        }
    }
    return list;
}
