//
// Created by lacer on 17/04/2025.
//

#include "Interface.h"
#include "Item.h"
#include "ListaE.h"
//-----------------------------------------------------------------------------
char menu(){
  char escolha;

  printf("\n----------------------------");
  printf("\n 1 - Cadastrar Aluno");
  printf("\n 2 - Exibir Alunos");
  printf("\n 3 - Consultar Aluno");
  printf("\n 4 - Remover aluno");
  printf("\n 5 - Organizar Crescentemente");
  printf("\n 6 - Sair do programa");
  printf("\n Escolha uma das op��es acima: ");
  do{
    escolha = getch();
  }while ( (escolha !='1') && (escolha !='2') && (escolha !='3') && (escolha !='4') && (escolha !='5')&& (escolha !='6'));
      printf(" %c \n----------------------------", escolha);
  return  escolha;
}
//-----------------------------------------------------------------------------
void cadastrarLstE(tpNo **lstAl){
    tpItem aluno;
    char nome[30];
    unsigned int mat;

    printf("\n Digite o nome do aluno: ");
    scanf("%s",nome);
    printf("\n Digite a matricula do aluno: ");
    scanf("%d",&mat);
    aluno = setItem(nome,mat);
    tpNo *lstAux =insertLstE(*lstAl, aluno);
    if ( isEmptyLstE(lstAux) ){
        printf("\n ERRO - aluno n�o cadastrado");
    } else {
        printf("\n CADASTRO COM SUCESSO!!!");
        (*lstAl) = lstAux;
    }

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void consultarLstE(tpNo *lstAl){
    unsigned int mat;

    printf("\n Digite a matricula do aluno: ");
    scanf("%d",&mat);
    tpItem *al = searchItemLstE(lstAl,mat);
    if ( al != NULL ){
        printf("\n aluno cadastrado");
        printf("\n Nome do aluno: %s", al->nome);
    } else {
        printf("\n ALUNO N�O CADASTRADO!!!");
    }
}

//-----------------------------------------------------------------------------


void removerList(tpNo **lstAl) {
    unsigned int mat;
    printf("\nDigite a matricula do aluno: ");
    scanf("%d", &mat);
    tpNo *tpAux = removerAluno(*lstAl, mat);
    if (tpAux == NULL) {
        printf("\n ALUNO NAO ENCONTRADO!!!");
    } else {
        printf("\n ALUNO REMOVIDO COM SUCESSO!!!");
        (*lstAl) = tpAux;
    }

}

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
void organizarLista(tpNo **lstAl) {
    bubbleSort(*lstAl);
    printLstE(*lstAl);
    printf("\nLista Organizada");
}


//-----------------------------------------------------------------------------

void lstEncadeada(){
    tpNo *lstAlunos = initLstE();
    printf("PROGRAMA ALUNOS!\n");
    char op;
    do{
            op = menu();
            switch (op){
                case '1': cadastrarLstE(&lstAlunos);
                          break;
                case '2': printLstE(lstAlunos);
                          break;
                case '3': consultarLstE(lstAlunos);
                          break;
                case '4':
                        removerList(&lstAlunos);
                    break;
                case '5':
                        organizarLista(&lstAlunos);
                    break;
                case '6': printf("\n Hasta la vista baby!");
            }
    }while (op != '6');
}
//-----------------------------------------------------------------------------

