/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int maiorValor(int v[], int tamanho, int i, int valorMax)
{
    if(i >= tamanho) return valorMax;
    if(v[i] > valorMax)
        valorMax = v[i];
    i++;
    maiorValor(v, tamanho, i, valorMax);
}

int main()
{
    int vetor[5] = {5,10,1,23,1};
    printf("\nIndex == %i", maiorValor(vetor, 5, 0, -1));
    
    return 0;
}