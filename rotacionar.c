#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da árvore
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// Função para criar um novo nó
No* criarNo(int valor) {
    No* novoNo = (No*) malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para inserir um valor na árvore
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    // Se valor já existir, não insere (evita duplicata)
    return raiz;
}

// Função para imprimir a árvore em ordem (in-order traversal)
void emOrdem(No* raiz) {
    if (raiz != NULL) {
                printf("%d ", raiz->valor);

        emOrdem(raiz->esquerda);
        emOrdem(raiz->direita);
    }
}
No* rotacionarDir(No* raiz)
{
    if(raiz != NULL)
    {
        No* aux = raiz->esquerda;
        No* auxB = aux->esquerda;
        
        aux = inserir(aux, raiz->valor);
        raiz = aux;
        return raiz;
    }
}

int main() {
    No* raiz = NULL;

    raiz = inserir(raiz, 45);
    raiz = inserir(raiz, 30);

    raiz = inserir(raiz, 15);
    raiz = rotacionarDir(raiz);

        printf("Elementos em ordem: ");
    emOrdem(raiz);
    printf("\n");
    return 0;
}
