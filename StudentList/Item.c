/********************************************************************
 * Este arquivo implementa um item do tipo Aluno.
 * Nesta implementação um aluno possui dois campos: matrícula e nome.
 * A estrutura de um Aluno está definida no arquivo Item.h.
 */

#include "Item.h"

//-----------------------------------------------------------------------------
/**
 * @param n = nome do aluno até 30 caracteres;
 * @param m = natural indicando a matricula do aluno;
 * @return Um tipo Item preenchido com nome=n e matrícula=m;
 */
tpItem  setItem(char n[], unsigned int m){
    tpItem al;
    strcpy(al.nome, n);
    al.id = m;
    return al;
}

//-----------------------------------------------------------------------------
/**
 * Exibe no vídeo os dados de al.
 * @param al = um item com dados de um aluno;
 * @return
 */
void printItem(tpItem al){
    printf("\n Nome: %s  ",al.nome);
    printf("\n Matricula: %d",al.id);
}






