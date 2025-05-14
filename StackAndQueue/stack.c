/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct no{
  int data;
  struct no*prox;
  
};
typedef struct no tprNo;

struct stack{
    int n;
    struct no* top;

};
typedef struct stack tprStack;

void printStack(tprStack *stack)
{
    if(stack ->top == NULL) return;
    tprNo *aux = stack->top;
    while(aux != NULL)
    {
        printf(" |  aux == %i -- %i |", aux->data, stack->n);
        aux = aux->prox;
    }
    printf("\n\n");
}

int insert(tprStack *stack, int data)
{
    if(stack == NULL) return 0;
    tprNo *new = (tprNo*)malloc(sizeof(tprNo));
    if(new == NULL) return 0 ;
    new->prox = stack->top;
    new->data = data;
    
    stack->top = new;
    stack->n++;
    return 1;
}
tprStack *initStack()
{
    tprStack *stack = (tprStack*)malloc(sizeof(tprStack));
    stack->top = NULL;
    stack->n = 0;
    return stack;
}

int main()
{
    tprStack *stack = initStack();
    stack->top = NULL;
    stack->n = 0;
    
    insert(stack, 10);
    insert(stack, 11);
    insert(stack, 12);
    insert(stack, 13);
    printStack(stack);
    return 0;
}