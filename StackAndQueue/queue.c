/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
struct no{
    int data;
    struct no *next;
    
};

typedef  struct no tprNo;

struct fila
{
    int n;
    tprNo *first;
    tprNo *last;
};
typedef struct fila tprQu;

tprQu *init()
{
    tprQu q = (tprQu*)malloc(sizeof(tprQu));
    q->first = NULL;
    q->last = NULL;
    int n = 0 ;
    
    
}
int insert(tprQu *fila, int data)
{
    tprNo no = (tprNo*)malloc(sizeof(tprNo));
    if(no == NULL) return 0 ;
    if(fila->first == NULL)
    {
    fila->first = no;
    }
    else
    {
        fila->last->prox = no;
        
    }
    
    
    fila->last = no;
    fila->n++;
    return 1;
}

int removeA(tprQu *fila)
{
    tprNo *remove = fila->first;
    fila->n--;
    fila->first = fila->first->prox;
    if(fila->first -> prox == NULL)
    {
        fila->last = NULL;
    }
   
    free(remove);
    return 0;
}
int main()
{
    printf("Hello World");

    return 0;
}