#include <stdio.h>
#include <stdlib.h>

struct celula {
    int info;
    struct celula *prox;
};

typedef  struct celula tpNo;

void printfList(tpNo *list) {
    tpNo *p = list;
    while (p != NULL) {
        printf("%d\n", p->info);
        p = p->prox;
    }
}

int main(void) {
    tpNo *p = (tpNo*)malloc(sizeof(tpNo));
    tpNo *q =  (tpNo*)malloc(sizeof(tpNo));
    p->info = 1;
    p->prox = q;

    q->info = 2;
    q->prox = NULL;
    printfList(p);

    return 0;
}