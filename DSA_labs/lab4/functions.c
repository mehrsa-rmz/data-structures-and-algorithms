#include "functions.h"
#include "utils.h"

bool isNotStop(const char *word)
{
    return !(strcmp(word, "stop") == 0);
}

void readInputIn(Queue *queue, FILE *file)
{
    char cuv[30];
    while (fscanf(file, "%s", cuv) != EOF)
       if(isNotStop(cuv)) en(queue, cuv);
       else break;
}


void processInput(Queue *queue, Stack *results)
{
    Stack *help;
    createStack(&help);
    char *s;
    while (!isEmptyQueue(queue))
    {
        s=de(queue);
        int n = strlen(s);
        for (int i = 0; i < n; i++)
            push(help, s[i]);
        
        while(!isEmptyStack(help))
        {
            push(results, pop(help));
        }  
    }
    free(help);
}
