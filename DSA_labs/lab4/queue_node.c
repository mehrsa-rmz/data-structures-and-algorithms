#include "queue_node.h"
#include "utils.h"

queue_node *createQueueNode(char *data)
{
    queue_node *newNode = (queue_node *)malloc(sizeof(queue_node));
    newNode->data = (char *)malloc(sizeof(char) * (strlen(data)+1));
    strcpy(newNode->data, data);
    newNode->next=NULL;
    return newNode;
}

void deleteQueueNode(queue_node *oldNode)
{
    free(oldNode->data);
}