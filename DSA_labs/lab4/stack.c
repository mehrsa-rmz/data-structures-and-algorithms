#include "utils.h"
#include "stack.h"
#include "stack_node.h"

void createStack(Stack **stack)
{
    *stack = (Stack *)malloc(sizeof(Stack));
    (*stack)->head=NULL;
    (*stack)->size=0;
}


void deleteStack(Stack *stack)
{
    while (stack->head->next != NULL)
    {
        stack_node *cop = stack->head;
        stack->head = stack->head->next;
        free(cop);
    }
    free(stack->head);
    free(stack);
}

void push(Stack *stack, char data)
{
    stack_node *newNode = createStackNode(data);
    newNode->next = stack->head;
    stack->head = newNode;
    stack->size++;
}


char pop(Stack *stack)
{
    if (isEmptyStack(stack))
        return -1;
    stack_node *temp = stack->head;
    char aux=stack->head->data;
    stack->head = stack->head->next;
    free(temp);
    stack->size--;
    return aux;
}


bool isEmptyStack(Stack *stack)
{
    return stack->size==0;
}
