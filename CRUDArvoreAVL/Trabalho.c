#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trabalho.h"
#include "Arvore.h"

// OK
int menu(Arvore *arv)
{
	int opcao, aluno;

	system("cls");

	printf(" \n\t"
		"CRUD usando Arvore \n\n\t"
		"Selecione o que deseja fazer \n\t"
		"1 - Cadastrar Aluno \n\t"
		"2 - Excluir Aluno \n\t"
		"3 - Pesquisar Aluno \n\t"
		"4 - Salvar \n\t"
		"5 - Sair \n\t");

	printf(">> ");
	scanf("%d", &opcao);
	fflush(stdin);

	while (opcao > 5 || opcao < 1)
	{
		printf("\tSelecione uma opcao valida! \n\t");
		printf(">> ");
		scanf("%d", &opcao);
		fflush(stdin);
	}

	switch (opcao)
	{
		case 1:
			printf("\tselecionou opcao 1 \n");
			//cadastrar_aluno(arv);
			break;
		case 2:
			printf("\tselecionou opcao 2 \n");
			//excluir_aluno(arv);
			break;
		case 3:
			printf("\tselecionou opcao 3 \n");

			int matricula;

			printf("\tQual a matricula do aluno? ");
			scanf("%d", &matricula);
			fflush(stdin);

			while (matricula < 1 || matricula > 9999999)
			{
				printf("\tInsira uma matricula valida: ");
				scanf("%d", &matricula);
				fflush(stdin);
			}

			//aluno = pesquisar_aluno(arv, matricula);

			break;
		case 4:
			printf("\tselecionou opcao 4 \n");
			//salvar_e_sair(arv);
			break;
		case 5:
			printf("\tselecionou opcao 5 \n");
			return 0;
			break;
		default:
			printf("\tERRO NA ESTRUTURA DE SWITCH DO MENU");
			break;
	}
	return 1;
}

// OK
int recuperar_chave(char *str) // est� pegando a matricula no inicio da linha, porem esse campo ser� do nome
{
	int i;
	char s[100];

	for (i = 0; str[i] != ' '; i++)
		s[i] = str[i];
	s[i] = '\n';

	return atoi(s);
}

// OK
char** recuperar_dados(char *str)
{
	// Ex de string recebida por parametro:
	// 1510522 | Aluno mat. 1510522 | 1510522@ffb.edu.br | 9151.0522
	// NOME				MATRICULA		EMAIL				TELEFONE

	char **dados;
	char *nome, *matricula, *email, *telefone;
	int i, j;

	dados =		(char **) malloc(4 * sizeof(char *));
	nome =		(char *) malloc(50 * sizeof(char));
	matricula = (char *) malloc(10 * sizeof(char));
	email =		(char *) malloc(50 * sizeof(char));
	telefone =	(char *) malloc(10 * sizeof(char));

	// recupera o nome
	for (i = 0, j = 0; str[i] != ' '; i++, j++)
		nome[j] = str[i];
	nome[j] = '\0';
	dados[0] = nome;

	// recupera a matricula
	for (i += 14, j = 0; str[i] != ' '; i++, j++)
		matricula[j] = str[i];
	matricula[j] = '\0';
	dados[1] = matricula;

	// recupera o email
	for (i += 3, j = 0; str[i] != ' '; i++, j++)
		email[j] = str[i];
	email[j] = '\0';
	dados[2] = email;

	// recupera o telefone
	for (i += 3, j = 0; str[i] != '\n'; i++, j++)
		telefone[j] = str[i];
	telefone[j] = '\0';
	dados[3] = telefone;

	return dados;
}

// OK
// carrega os dados do arquivo na arvore (em mem�ria)
void carregar_arvore(Arvore *arv)
{
	FILE *fp = fopen("C:\\Users\\1510522\\Desktop\\TreeProject\\DB\\BDAlunos10e1v4.txt", "r");
	char str[1000]; // "str" receber� cada linha do arquivo e ser� fragmentada para um array de strings.
	char **dados; // "dados" guardar� o array de strings da fragmenta��o de "str"
	int key, i;

	while (fgets(str, sizeof str, fp) != NULL)
	{
		dados = recuperar_dados(str);

		// segundo parametro transforma a string de matricula para inteiro e usa como chave da arvore
		inserir(arv, atoi(dados[1]), str);

		// imprimindo os dados recebidos (s� para testar se est� tudo ok)
		printf("%s %s %s %s \n", dados[0], dados[1], dados[2], dados[3]);

		// limpando as informa��es j� inseridas na arvore
		for (i = 0; i < 4; i++)
			free(dados[i]);
		free(dados);
	}

	fclose(fp);
}

//OK
char* pesquisar_aluno(Arvore *arv, int key)
{
	char *str;

	str = buscar(arv, key);

	//printf("strlen(str): %d \n", strlen(str));
	//printf("str: %s", str);

	return (strlen(str) == 0 ? "Aluno nao encontrado! \n\0" : str);
}

void excluir_aluno(Arvore *arv)
{

}

void listar_alunos(Arvore *arv)
{
    FILE *fp = fopen("C:\\Users\\1510522\\Desktop\\TreeProject\\DB\\PesqAlunos10e1.txt", "r");
	char str[20]; // "str" receber� cada linha do arquivo.
    int matricula; // "matricula" receber� o valor de "str" em formato inteiro.

    printf("\n \t\tNome \t\tMatricula \t  E-mail \t  Telefone \n\n");

    while (fgets(str, sizeof str, fp) != NULL)
	{
		matricula = atoi(str);
		printf("Mat.: %d - ", matricula);
        printf("%s", pesquisar_aluno(arv, matricula));
	}
}
/*
void cadastrar_aluno(Arvore *arv)
{
	char *dados;
	char *nome = (char*)malloc(50 * sizeof(char));
	char *telefone = (char*)malloc(10 * sizeof(char));
	char *email = (char*)malloc(18 * sizeof(char));
	int matricula = maior_chave(arv);

	printf("Nome: ");
	scanf_s("%s", nome);

	printf("E-mail: ");
	scanf_s("%s", email);

	printf("Telefone: ");
	scanf_s("%s", telefone);


	dados = strcat(dados, nome);
	dados = strcat(dados, " | Aluno mat. ");
	//dados = strcat(dados, intToString(matricula));
	dados = strcat(dados, " | ");
	dados = strcat(dados, email);
	dados = strcat(dados, " | ");
	dados = strcat(dados, telefone);
	dados = strcat(dados, "\n\0");

	//dados = (char*)malloc(63 * sizeof(char))

	printf("Digite os dados do aluno (ex: \"1510522 | Aluno mat. 1510522 | 1510522@ffb.edu.br | 9151.0522\")");
	scanf_s("%s", dados);


	printf("Digite os dados do aluno (ex: \"1510522 | Aluno mat. 1510522 | 1510522@ffb.edu.br | 9151.0522\")");
	scanf_s("%s", dados);

	matricula = recuperar_chave(dados);
	inserir(arv, matricula, dados);
	printf("Aluno Cadastrado! \n");
}

/*
void salvar(Arvore *arv)
{
	FILE *fp = fopen("C:\\Users\\Eron\\Desktop\\Trabalho\\BDAlunos10e1v1.txt", "w");
	char *str; // 63 � o tamanho da linha do arquivo incluindo \n e \0
	int key, i, qtd_nos;
	qtd_nos = contar_nos(arv);

	while (fp != NULL)
	{
		for (i = 0; i < qtd_nos; i++)
		{
			str = pesquisar(arv, i);
			fputs(str, sizeof str, fp);
		}

		key = recuperar_chave(str);
		inserir(arv, key, str);
	}

	fclose(fp);
}*/

void sair_sem_salvar()
{

}
