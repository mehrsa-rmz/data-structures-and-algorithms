#include "stack_node.h"

stack_node *createStackNode(char data)
{
    stack_node *newNode = (stack_node *)malloc(sizeof(stack_node));
    newNode->data = data;
    newNode->next=NULL;
    return newNode;
}