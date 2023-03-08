#include "utils.h"
#include "queue.h"
#include "queue_node.h"

void createQueue(Queue **queue)
{
    *queue = (Queue *)malloc(sizeof(Queue));
    (*queue)->front=NULL;
    (*queue)->rear=NULL;
}

void en(Queue *queue, char *data)
{
    queue_node *newNode = createQueueNode(data);
    newNode->next = NULL;
    if (queue->rear == NULL)
        queue->rear = newNode;
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    if (queue->front == NULL)
        queue->front = queue->rear;
}

char *de(Queue *queue)
{
    queue_node *temp;
    char *aux;
    if (isEmptyQueue(queue))
        return NULL;
    temp = queue->front;
    aux = (char *)malloc(sizeof(char) * (strlen(temp->data)+1));
    strcpy(aux, temp->data);
    queue->front = queue->front->next;
    free(temp->data);
    free(temp);
    return aux;
}

void deleteQueue(Queue *queue)
{
    while (queue->front->next != NULL)
    {
        deleteQueueNode(queue->front);
        queue_node *cop = queue->front;
        queue->front = queue->front->next;
        free(cop);
    }
    free(queue->front->data);
    free(queue->front);
    free(queue);
}

bool isEmptyQueue(Queue *queue)
{
    return queue->front == NULL;
}
