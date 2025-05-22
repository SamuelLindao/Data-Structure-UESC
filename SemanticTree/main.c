#include <stdio.h>
#include <stdlib.h>

struct Item{
    int valor;
};
typedef  struct Item tprItem;
struct NO {
    tprItem item;
    struct NO *esq, *dir;
};

typedef struct NO tpNo;

tpNo *init() {
    tpNo *no = (tpNo*)malloc(sizeof(tpNo));
    no->esq = NULL;
    no->dir = NULL;

    return no;
}

int main(void) {
    tpNo *binary = init();
    return 0;
}