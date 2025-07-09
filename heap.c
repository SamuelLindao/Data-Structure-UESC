#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef  struct heapStruct {
    int data[MAX_SIZE];
    int size;
}heapTpr;

void printHeap(heapTpr *heap) {
    printf("\n");
    for (int i =0 ; i < heap->size;i++) {
        printf("%i-", heap->data[i]);
    }
}

void inserirAleatoria(heapTpr *heap) {
    int x = rand() % 256;
    heap->data[heap->size++] = x;
}

heapTpr* initializeHeap() {
    heapTpr *tpr = (heapTpr*)malloc(sizeof(heapTpr));

    tpr->size = 0;
    return tpr;
}

void desce_heap(heapTpr *heap, int i) {
    int left = i * 2  +1;
    int right = i * 2 + 2;
    int major = i;
    if (left < heap->size && heap->data[left] > heap->data[major]) {
        major = left;
    }
    if (right < heap->size && heap->data[right] > heap->data[major]) {
        major = right;
    }

    if (i != major) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[major];
        heap->data[major] = temp;
        desce_heap(heap, major);
    }
}

void constroi_heap(heapTpr * heap) {
    for (int i =heap->size/2 ; i >= 0; i--) {
        desce_heap(heap, i);
    }
}

void sobe_heap(heapTpr *heap, int i) {
    while (i > 0 && heap->data[i] > heap->data[i/2]) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[i/2];
        heap->data[i/2] = temp;
        i /=2;
    }
}
void remover_topo(heapTpr *heap) {
    int temp = heap->data[0];
    heap->data[0] = heap->data[heap->size-1];
    heap->data[heap->size-1] = temp;
    heap->size--;
    desce_heap(heap, 0);

}

void adicionar_elemento(heapTpr *heap, int x) {
    heap->data[heap->size++] = x;
    //sobe_heap(heap, heap->size-1);
    int i = heap->size-1;
    while (i > 0 && heap->data[i] > heap->data[i/2]) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[i/2];
        heap->data[i/2] = temp;
        i /=2;
    }
}

void heap_sort(heapTpr *heap) {

    int aux = heap->size;
    for (int i = heap->size-1 ; i >= 0; i--) {

        int temp = heap->data[0];
        heap->data[0] = heap->data[i];
        heap->data[i] = temp;
        heap->size = i;
        desce_heap(heap, 0);
        printHeap(heap);


    }
    heap->size = aux;


}
int main(void) {
    srand(time(NULL));

    heapTpr *heap = initializeHeap();;

    inserirAleatoria(heap);
    inserirAleatoria(heap);
    inserirAleatoria(heap);
    inserirAleatoria(heap);
    inserirAleatoria(heap);
    inserirAleatoria(heap);

    printf("Initial Vetor\n");
    printHeap(heap);

    constroi_heap(heap);
    printf("\nPos Heap\n");
    printHeap(heap);

    remover_topo(heap);
    printf("\nRemovido Heap\n");
    printHeap(heap);

    adicionar_elemento(heap, 1);
    printf("\nAdicionar Heap\n");
    printHeap(heap);

    heap_sort(heap);
    printf("\nHeap Sort\n");
    printHeap(heap);
    return 0;
}