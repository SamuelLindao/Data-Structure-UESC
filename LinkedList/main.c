#include <stdio.h>
#include <stdlib.h>

struct celula {
    int info;
    struct celula *prox;
};

typedef  struct celula tpNo;
typedef struct {
    tpNo *head;
    int size;
} tpLista;

void printfList(tpLista *list) {
    tpNo *p = list->head;
    while (p != NULL) {
        printf("%d\n", p->info);
        p = p->prox;
    }
}

tpLista * createList() {
    tpLista *list = (tpLista*)malloc(sizeof(tpLista));
    list->head = NULL;
    list->size = 0;
    return list;
}

int main(void) {
    /*
    tpNo *p = (tpNo*)malloc(sizeof(tpNo));
    tpNo *q =  (tpNo*)malloc(sizeof(tpNo));
    p->info = 1;
    p->prox = q;

    q->info = 2;
    q->prox = NULL;
    printfList(p);
    */

    tpLista *list = createList();

    for (int i = 0 ; i < 10 ; i++) {
        tpNo *p = (tpNo*)malloc(sizeof(tpNo));
        p->info = i;
        p->prox = NULL;
        if (list->head == NULL) {
            list->head = p;
        }
        else {
            tpNo *aux = list->head;
            while (aux->prox != NULL) {
                aux = aux->prox;
            }
            aux->prox = p;
        }
    }
    printfList(list);
    return 0;
}