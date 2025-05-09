#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node tprNode;

struct list {
    int quantity;
    tprNode *first;
    tprNode *last;
};
typedef struct list tprList;

// Cria um novo nó
tprNode* createNode(int value) {
    tprNode* newNode = (tprNode*)malloc(sizeof(tprNode));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Cria uma nova lista
tprList* createList() {
    tprList* newList = (tprList*)malloc(sizeof(tprList));
    newList->quantity = 0;
    newList->first = NULL;
    newList->last = NULL;
    return newList;
}

// Insere no final da lista
void append(tprList *list, int value) {
    tprNode *newNode = createNode(value);

    if (list->first == NULL) {
        list->first = newNode;
        list->last = newNode;
    } else {
        list->last->next = newNode;
        newNode->prev = list->last;
        list->last = newNode;
    }

    list->quantity++;
}

// Remove o primeiro nó com valor igual a 'value'
void removeNode(tprList *list, int value) {
    tprNode *current = list->first;

    while (current != NULL && current->data != value) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Valor %d não encontrado na lista.\n", value);
        return;
    }

    tprNode *anterior = current->prev;
    tprNode *proximo = current->next;

    if (anterior != NULL)
        anterior->next = proximo;
    else
        list->first = proximo;  // Removendo o primeiro elemento

    if (proximo != NULL)
        proximo->prev = anterior;
    else
        list->last = anterior;  // Removendo o último elemento

    free(current);
    list->quantity--;
    printf("Valor %d removido da lista.\n", value);
}

// Imprime a lista
void printList(tprList *list) {
    tprNode *current = list->first;
    printf("Lista: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\nQuantidade de elementos: %d\n", list->quantity);
}

int main(void) {
    tprList *list = createList();

    append(list, 10);
    append(list, 20);
    append(list, 30);
    append(list, 40);

    printList(list);

    removeNode(list, 30);
    printList(list);

    removeNode(list, 10);
    printList(list);

    return 0;
}
