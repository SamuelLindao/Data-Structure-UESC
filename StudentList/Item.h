//Essas diretivas servem para evitar que um header file seja incluído mais de uma vez
//no mesmo projeto
#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

    #include <string.h>
    #include <stdio.h>

    #define false 0;
    #define true 1;
    typedef int booleano;

    struct tpAluno {
        char nome[30];
        unsigned int id; //matrícula
    };

    typedef struct tpAluno tpItem;

    //-----------------------------------------------------------------------------
    /**
     * @param n = nome do aluno até 30 caracteres;
     * @param m = natural indicando a matricula do aluno;
     * @return Um tipo Item preenchido com nome=n e matrícula=m;
     */
    tpItem setItem( char n[],unsigned int m);

    //-----------------------------------------------------------------------------
    /**
     * Exibe no vídeo os dados de al.
     * @param al = um item com dados de um aluno;
     * @return
     */
    void printItem(tpItem al);


#endif // ITEM_H_INCLUDED



