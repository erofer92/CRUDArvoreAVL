#ifndef ARVORE_H
#define ARVORE_H

#include "Aluno.h"

/*
------------------------------------------------------------------------------------
---------------------------------ESTRUTURA DA �RVORE--------------------------------
------------------------------------------------------------------------------------
*/

typedef struct arvore Arvore;

/*
------------------------------------------------------------------------------------
---------------------------------OPERA��ES GEN�RICAS--------------------------------
------------------------------------------------------------------------------------
*/

Arvore* criar();
void destruir(Arvore *arv);
long long int contar_nos(Arvore *arv);
long long int contar_folhas(Arvore *arv);
long long int altura2(Arvore *arv); // -1 = �RVORE VAZIA;
long long int altura(Arvore *arv); // -1 = �RVORE VAZIA;
int vazia(Arvore *arv); // 1 = VAZIA; 0 = N�O VAZIA;
long long int menor_chave(Arvore *arv); // -1 = �RVORE VAZIA;
long long int maior_chave(Arvore *arv); // -1 = �RVORE VAZIA;
int buscar(Arvore *arv, long long int chave); // 1 = EXISTE; 0 = N�O EXISTE;

/*
------------------------------------------------------------------------------------------
------------------------------------INSER��O E REMO��O------------------------------------
------------------------------------------------------------------------------------------
*/

int inserir(Arvore *arv, long long int chave, Aluno *aluno); // 1 = OK; 0 = FAIL;
int remover(Arvore *arv, long long int chave); // 1 = OK; 0 = FAIL;

/*
------------------------------------------------------------------------------------------
----------------------------------------TESTE AVL-----------------------------------------
------------------------------------------------------------------------------------------
*/

int avl(Arvore *arv); // 1 = AVL; 0 = N�O AVL;

/*
------------------------------------------------------------------------------------------
----------------------------------OPERA��ES DO TRABALHO-----------------------------------
------------------------------------------------------------------------------------------
*/

Aluno* buscar_aluno(Arvore *arv, long long int matricula); // NULL = ALUNO N�O EXISTE;
void imprimir_alunos_in_ordem(Arvore *arv); // IMPRIME AS INFORMA��ES DOS ALUNOS
void remover_todos_os_alunos_da_arvore(Arvore *arv); // REMOVE TODOS OS ALUNOS DA �RVORE.
void salvar_alunos_no_arquivo(Arvore *arv, FILE *fp); // SALVA OS ALUNOS NO ARQUIVO PASSADO POR PARAMETRO.

#endif // ARVORE_H
