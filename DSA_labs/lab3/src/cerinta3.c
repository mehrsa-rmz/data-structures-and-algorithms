#include "list.h"
#include "utils.h"

childNode *makeChildNode(int number, const char *name, childNode *next)
{
    childNode *nod = (childNode *)malloc(sizeof(childNode));
    nod->number = number;
    nod->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(nod->name, name);
    nod->next = next;
    return nod;
}

childNode *makeCircularList(FILE *file)
{
    int x;
    char s[15];
    childNode *nod, *head;

    if (fscanf(file, "%d %s", &x, s) != EOF)
    {
        nod = makeChildNode(x, s, NULL);
        head = nod;
    }

    while (fscanf(file, "%d %s", &x, s) != EOF)
        nod = makeChildNode(x, s, nod);
    head->next = nod;
    return nod;
}

childNode *playJosephGame(childNode *head, int p)
{
    childNode *head2, *end;
    int ok = 1;

    while (head->next != head)
    {
        for (int i = 2; i < p; i++)
            head = head->next;

        if (ok)
        {
            head2 = head->next;
            head->next = head->next->next;
            head = head->next;
            head2->next = NULL;
            ok = 0;
        }
        else
        {
            end=head->next;
            head->next = head->next->next;
            end->next=head2;
            head2=end;
            head = head->next;
        }
    }

    head->next=head2;

    end = head;
    printf("\nClasament:\n");
    while (end != NULL)
    {
        printf("%s\n", end->name);
        end = end->next;
    }

    return head;
}