
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
  struct node *prox;  
};
typedef struct node tprnode;

struct list
{
    int quant;
    tprnode* head;
    
};
typedef struct list tprList;

void printList(tprList *list)
{
    int index = 0;
    tprnode *aux = list->head;
    while(aux != NULL)
    {
        printf(" | %i - %i |", index,aux->data);
        aux = aux->prox;
        index++;
    }
    printf("\n");
    printf("\n");
    
}

int addElement(tprList *list, int data)
{
    if(list == NULL) {
        printf("\nError ");
        return 0;
    }
    
    if(list -> head == NULL) 
    {
        list->head = (tprnode*)malloc(sizeof(tprnode));
        list->head->data = data;
        list->quant++;
        printList(list);

        return 1;
    }
    tprnode *aux = list->head;
    tprnode *new = (tprnode*)malloc(sizeof(tprnode));
    new->data = data;
    new->prox = NULL;
    while(aux->prox != NULL)
    {
        aux = aux->prox;
    }
    aux->prox = new;

    
    printList(list);
    return 1;

}


int main()
{
    tprList *list = (tprList*)malloc(sizeof(tprList));
    list->head = NULL;
    addElement(list, 25);
    addElement(list, 1);
    addElement(list, 15);
    addElement(list, 4);
    addElement(list, 7);

    return 0;
}