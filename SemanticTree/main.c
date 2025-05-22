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
tpNo* inserir_rec(tpNo *raiz, int valor) {
    if (raiz == NULL) {
        tpNo *novo = (tpNo *)malloc(sizeof(tpNo));
        if (novo == NULL) {
            printf("Erro ao alocar memória.\n");
            exit(1);
        }
        novo->item.valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }

    if (valor < raiz->item.valor) {
        raiz->esq = inserir_rec(raiz->esq, valor);
    } else {
        raiz->dir = inserir_rec(raiz->dir, valor);
    }

    return raiz;
}
void Insert(tprBinary *tree, int valor) {
    tree->root = inserir_rec(tree->root, valor);
}
//Codigo falhico
// void Insert(tprBinary *tree, int valor) {
//     tpNo *aux = (valor < tree->root->item.valor) ? tree->root->esq : tree->root->dir;
//     while ((valor < aux->item.valor) ? aux->esq : aux->dir != NULL ) {
//         aux = (valor < aux->item.valor) ? aux->esq : aux->dir;
//     }
//     tprItem item ;
//     item.valor = valor;
//     tpNo *novo = (tpNo*)malloc(sizeof(tpNo));
//     novo->item = item;
//     novo->esq = NULL;
//     novo->dir = NULL;
//     if (valor < aux->item.valor) {
//         aux->esq = novo;
//     }
//     else {
//         aux->dir = novo;
//     }
// }

int ArvoreTamanho(tpNo *root) {

    if (root == NULL) { return 0; }
    printf("\n--%i", root->item.valor);
    return 1 + ArvoreTamanho(root->esq) + ArvoreTamanho(root->dir);
}
int main(void) {
    tprBinary *tree = init();
    return 0;
}