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

struct binary {
    tpNo *root;

};

typedef struct binary tprBinary;

tprBinary *init() {
    tprBinary *tree = (tprBinary*)malloc(sizeof(tprBinary));
    tree->root = NULL;
    return tree;
}

int main(void) {
    tprBinary *tree = init();
    return 0;
}