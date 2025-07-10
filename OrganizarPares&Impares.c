#include <stdio.h>
//int entrada [] = {10,4,32,34,543,3456,654,567,87,6789,98}; 
//const int tamanho = sizeof(entrada)/sizeof(entrada[0]);
void printEntrada(int valores[], int n) {for(int i= 0 ; i < n; i++){printf("%i\n", valores[i]); }}


int cmp_asc(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return x - y;
}

int cmp_desc(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return y - x;
}


void OrganizarPareEImpares(int entrada[], int tamanho)
{
    int pares[tamanho];
    int impares[tamanho];
    int tamanhoPares = 0;
    int tamanhoImpares = 0;
    
    if(tamanho <= 0) return;
    
    for(int i= 0 ; i < tamanho;i++)
    {
        if(entrada[i] % 2 == 0)
        {
            pares[tamanhoPares++] = entrada[i];
        }
        else
        {
            impares[tamanhoImpares++] = entrada[i];
        }
    }
    qsort(pares, tamanhoPares, sizeof(int), cmp_asc);
    qsort(impares, tamanhoImpares, sizeof(int), cmp_desc);
    int novo[tamanho];
    for(int i =0 ; i < tamanho;i++)
    {
        if(i >= tamanhoPares)
        {
            novo[i] = impares[i - tamanhoPares];
        }
        else
        {
            novo[i] = pares[i];
        }
    }
    printEntrada(novo, tamanho);
    return ;
}

int main() {
    int n;

    scanf("%d", &n);

    int entrada[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &entrada[i]);
    }


    OrganizarPareEImpares(entrada, n);

   return 0;
}