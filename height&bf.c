/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

struct root
{
    int value;
    struct root *left;
    struct root *right;
};

typedef struct root rootStr;

int arvoreAltura(rootStr *root)
{
    if(root == NULL) return -1;
    int alturaEsq = arvoreAltura(root->left);
    int alturaDir = arvoreAltura(root->right);
    return (alturaEsq>alturaDir?alturaEsq:alturaDir) + 1;
}

int calcularFb(rootStr *root)
{
    return (arvoreAltura(root->dir)) - (arvoreAltura(root->esq));
}

int main()
{
    printf("Hello World");

    return 0;
}