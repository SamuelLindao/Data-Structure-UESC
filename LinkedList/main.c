#include <stdio.h>

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
    tpNo *p = NULL;
    tpNo *q = NULL;
    p->info = 1;
    p->prox = q;
    printfList(p);

    return 0;
}