#include <stdio.h>
#include <stdlib.h>
//Inicio do estudo de pilhas de filas
//Stacks

struct  list {
    int data;
    struct list *next;
};

typedef struct  list List;

struct stack {
    struct list *top;
};

typedef struct stack Stack;

Stack* create(void) {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push(Stack*p, int v) {
    List *new = (Stack*)malloc(sizeof(Stack));
    new->data = v;
    new->next = p->top;
    p->top = new;
}
int pop(Stack*p) {
    List *t;
    int v;
    if (p->top == NULL) {
        printf("Stack is empty\n");
        return 1;
    }
    t = p->top;
    v = t->data;
    p->top = t->next;
    free(t);
    return v;
}

void free_stack(Stack *p) {
    List *t = p->top;
    while (t != NULL) {
        List *tAux = t->next;
        free(t);
        t = tAux;
    }

    free(t);

}
int main(void) {
    printf("Hello, World!\n");
    return 0;
}