/********************************************************************
 * Este arquivo cont�m c�digo para manipular uma lista encadeada de itens.
 * Um item � uma estrutura definida pelo usu�rio da biblioteca ListaE.h.
 * Uma lista encadeada � um ponteiro para um n�. Um n� possui dois campos:
 * a) um campo do tipo tpItem;
 * b) um ponteiro para o pr�ximo n�;
 *
 * Obs:
 * -> O tipo tpItem deve conter obrigat�riamente um campo nomeado de id do tipo unsigned int.
 *
 */
#include "ListaE.h"
//-----------------------------------------------------------------------------
struct Celula {
       tpItem    item;
       struct Celula  *prox;
};

typedef  struct Celula tpNo;
//-----------------------------------------------------------------------------
/**
 * @param .
 * @return a lista inicializada com o ponteiro apontando para NULL;
 */
tpNo * initLstE(){
    tpNo *lst = NULL;
    return lst;
}

/**
 * @param lst = uma Lista de itens;
 * @param item= um item a ser inserido em lst
 * @return a lista se o item foi inserido em lst ou NULL caso contr�rio.
 */
tpNo *insertLstE(tpNo *lst, tpItem item){
    tpNo *no = (tpNo*)malloc(sizeof(tpNo));
   	if (no !=NULL){
		no->item = item;
		no->prox = lst;
   		lst=no;
   		return lst;
	}
    return NULL;
}
//-----------------------------------------------------------------------------
/**
 * @param lst = uma Lista n�o vazia de itens;
 * @return retorna o item da primeira posi��o de lst.
 */
tpItem  getE(tpNo *lst){
       return lst->item;
}


//-----------------------------------------------------------------------------
/**
 * Exibe no monitor os itens da lista.
 * @param lst = uma Lista de itens;
 * @return
 */
void printLstE(tpNo *lst){
    //tpNo *aux = lst;

    while (lst != NULL) {
            printItem(lst->item);
            printf("\n----------------------------------");
            lst = lst->prox;
    }
}

//-----------------------------------------------------------------------------
/**
 * Verifica se a lista est� vazia.
 * @param lst = uma Lista de itens;
 * @return true se lst vazia ou false caso contr�rio.
 */
booleano isEmptyLstE(tpNo *lst){
    if (lst == NULL) return true;
    return false;
}

//-----------------------------------------------------------------------------
/**
 * Verifica se a lista est� vazia.
 * @param lst = uma Lista de itens;
 * @param id = � o identificador que ser� buscado em lst.
 * @return o item na lista com o id ou NULL se n�o for encontrado.
 */
tpItem * searchItemLstE(tpNo *lst, unsigned int id){
    if  (lst != NULL){
        if (lst->item.id == id){
            return &(lst->item);
        } else {
            return searchItemLstE(lst->prox, id);
        }
    }
    return NULL;
}
tpNo * removerAluno(tpNo *lst, unsigned int id) {
    if (lst == NULL) {
        return NULL;
    }

    if (lst->item.id == id) {
        tpNo *proximo = lst->prox;
        free(lst);
        return proximo;
    }

    if (lst->prox != NULL && lst->prox->item.id == id) {
        tpNo *noARemover = lst->prox;
        lst->prox = noARemover->prox;
        free(noARemover);
        return lst;
    }

    lst->prox = removerAluno(lst->prox, id);
    return lst;
}

//Bubble Sort
void bubbleSort(tpNo *lst) {
    if (lst == NULL) return;

    int trocou;
    tpNo *ptr1;
    tpNo *lptr = NULL;

    do {
        trocou = 0;
        ptr1 = lst;

        while (ptr1->prox != lptr) {
            if (ptr1->item.id > ptr1->prox->item.id) {
                tpItem temp = ptr1->item;
                ptr1->item = ptr1->prox->item;
                ptr1->prox->item = temp;
                trocou = 1;
            }
            ptr1 = ptr1->prox;
        }
        lptr = ptr1;
    } while (trocou);
}