#include <stdio.h>

struct Item{
    int valor;
};
typedef  struct Item tprItem;
struct NO {
    tprItem item;
    struct NO *esq, *dir;
};
int main(void) {
    printf("Hello, World!\n");
    return 0;
}