#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "definicoes.h"
#include "strutil.h"

#ifndef _FILEUTIL_H
#define _FILEUTIL_H

int retorna_last_id_file(const char* FILE_NAME);

void salvar_conteudo_em_arquivo(const char* FILE_NAME, char* texto, char* mensagem_erro);

void imprime_conteudo_de_arquivo_em_formato_de_tabela(const char* FILE_NAME, char* mensagem_erro, char* cabecalho_tabela);

void pesquisa_conteudo_em_arquivo(const char* FILE_NAME, const char* pesquisa, const int coluna, char* mensagem_erro, char* cabecalho_tabela);

int retorna_quantidade_registro_arquivo(const char* FILE_NAME);

struct Selecao* carrega_selecao_de_arquivo(const char* FILE_NAME, int const QTD_LINHAS);

int retorna_last_id_file(const char* FILE_NAME){
	FILE *arq = NULL;
	char row[TAMANHO_MAXIMO_CARACTERES_LINHA] = {0}, *result = {0};
	int max_id_file = INT_MIN;
	
	// Abre um arquivo TEXTO para LEITURA
	arq = fopen(FILE_NAME, "rt");
	if (arq == NULL){  // Se houve erro na abertura
	 return 0;
	}
	while (!feof(arq)){
	  // L� uma linha (inclusive com o '\n')
	  result = fgets(row, TAMANHO_MAXIMO_CARACTERES_LINHA, arq);  // o 'fgets' l� at� TAMANHO_MAXIMO_CARACTERES_LINHA caracteres ou at� o '\n'
	  if (result){  // Se foi poss�vel ler
		char* sub_string = split_char_position(row, CARACTER_SEPARACAO, 0);
		int id_int = atoi(sub_string);
	  	if(max_id_file < id_int){
	  		max_id_file = id_int;
		  }
		free(sub_string);
	  }
	}
	fclose(arq);
	if(max_id_file == INT_MIN)
		return 0;
	return max_id_file;
}

void salvar_conteudo_em_arquivo(const char* FILE_NAME, char* texto, char* mensagem_erro){
	
	/* Declaramos um ponteiro(link para o endere�o da mem�ria) para o arquivo de nome: 'pFile'*/
	FILE * pFile;
	
	/*  Os dados ser�o adicionados no fim do arquivo ("append"), 
		se ele j� existir, ou um novo arquivo ser� criado, no caso de arquivo n�o */
	pFile = fopen(FILE_NAME , "a");
	
	/* Se o arquivo for n�o-vazio */
	if(pFile!=NULL){	
		int salvar_dados;
		do{
			printf("Resumo: '%s'.", texto);
			printf("Deseja salvar as informa��es 1 para sim 0 para n�o:");
			scanf("%d", &salvar_dados);
			switch(salvar_dados){
				case 1:
					printf("Salvando dados.\n");
					system("pause");
					/*Escreve uma string(da vari�vel 'texto') num arquivo. */
					fputs(texto, pFile);
					system("cls");
					break;
				case 0:
					printf("Opera��o cancelada.\n");
					system("pause");
					system("cls");
					break;
				default:
					printf("Opera��o inv�lida.\n");
					system("pause");
					system("cls");
					break;
			}	
		}while(salvar_dados >= 2);
		
		/* Quando acabamos de usar um arquivo que abrimos, devemos fech�-lo. Para tanto usa-se a fun��o fclose() */
		fclose(pFile);
	}
	else{
		printf("%s\n", &mensagem_erro);
		system("pause");
		system("cls");
	}
}

void imprime_conteudo_de_arquivo_em_formato_de_tabela(const char* FILE_NAME, char* mensagem_erro, char* cabecalho_tabela){
	FILE *arq = NULL;
	char row[TAMANHO_MAXIMO_CARACTERES_LINHA] = {0}, *result = {0};
	
	// Abre um arquivo TEXTO para LEITURA
	arq = fopen(FILE_NAME, "rt");
	if (arq == NULL){  // Se houve erro na abertura
	 printf("%s\n", mensagem_erro);
	 system("pause");
	 system("cls");
	 return;
	}
	
	int contador_linhas = 0, contador_paginas = 1;
	printf("%s\n", cabecalho_tabela);
	
	while (!feof(arq)){
	  // L� uma linha (inclusive com o '\n')
	  result = fgets(row, TAMANHO_MAXIMO_CARACTERES_LINHA, arq);  // o 'fgets' l� at� TAMANHO_MAXIMO_CARACTERES_LINHA caracteres ou at� o '\n'
	  if (result){  // Se foi poss�vel ler
	  	if(contador_linhas >= TAMANHO_MAXIMO_PAGINACAO_TABELAS){
	  		printf("Fim da P�gina: %d\n", contador_paginas);
	  		system("pause");
	  		system("cls");
	  		contador_paginas++;
	  		contador_linhas=0;
		  }
		printf("%s", row);
		contador_linhas++;
	  }
	}
	printf("Fim da P�gina: %d\n", contador_paginas);
	system("pause");
	system("cls");
	fclose(arq);
}

void pesquisa_conteudo_em_arquivo(const char* FILE_NAME, const char* pesquisa, const int coluna, char* mensagem_erro, char* cabecalho_tabela){
	FILE *arq = NULL;
	char row[TAMANHO_MAXIMO_CARACTERES_LINHA] = {0}, *result = {0};
	int contador_resultados_encontrador = 0;
	// Abre um arquivo TEXTO para LEITURA
	arq = fopen(FILE_NAME, "rt");
	if (arq == NULL){  // Se houve erro na abertura
	 printf("%s\n", mensagem_erro);
	 system("pause");
	 system("cls");
	 return;
	}
	
	while (!feof(arq)){
	  // L� uma linha (inclusive com o '\n')
	  result = fgets(row, TAMANHO_MAXIMO_CARACTERES_LINHA, arq);  // o 'fgets' l� at� TAMANHO_MAXIMO_CARACTERES_LINHA caracteres ou at� o '\n'
	  if (result){  // Se foi poss�vel ler
		char* sub_string = split_char_position(row, CARACTER_SEPARACAO, coluna);
		if(strcmp(pesquisa, sub_string)==0)
			contador_resultados_encontrador++;
	  }
	}
	fclose(arq);
	
	if(contador_resultados_encontrador > 0){
		// Abre um arquivo TEXTO para LEITURA
		arq = fopen(FILE_NAME, "rt");
		if (arq == NULL){  // Se houve erro na abertura
		 printf("%s\n", mensagem_erro);
		 system("pause");
		 system("cls");
		 return;
		}
		printf("Foram encontrados %d registros.\n", contador_resultados_encontrador);
		printf("%s\n", cabecalho_tabela);
		while (!feof(arq)){
		  // L� uma linha (inclusive com o '\n')
		  result = fgets(row, TAMANHO_MAXIMO_CARACTERES_LINHA, arq);  // o 'fgets' l� at� TAMANHO_MAXIMO_CARACTERES_LINHA caracteres ou at� o '\n'
		  if (result){  // Se foi poss�vel ler
			char* sub_string = split_char_position(row, CARACTER_SEPARACAO, coluna);
			if(strcmp(pesquisa, sub_string)==0)
				printf("%s", row);
		  }
		}
		fclose(arq);
	}
	else{
		printf("A pesquisa n�o retornou registros.\n");
	}
	printf("Fim da pesquisa\n");
	system("pause");
	system("cls");
}

int retorna_quantidade_registro_arquivo(const char* FILE_NAME){
	FILE *arq = NULL;
	char row[TAMANHO_MAXIMO_CARACTERES_LINHA] = {0}, *result = {0};
	int count_lines = 0;
	
	// Abre um arquivo TEXTO para LEITURA
	arq = fopen(FILE_NAME, "rt");
	if (arq == NULL){  // Se houve erro na abertura
	 return 0;
	}
	while (!feof(arq)){
	  // L� uma linha (inclusive com o '\n')
	  result = fgets(row, TAMANHO_MAXIMO_CARACTERES_LINHA, arq);  // o 'fgets' l� at� TAMANHO_MAXIMO_CARACTERES_LINHA caracteres ou at� o '\n'
	  if (result){  // Se foi poss�vel ler
		count_lines++;
	  }
	}
	fclose(arq);
	return count_lines;
}

struct Selecao* carrega_selecao_de_arquivo(const char* FILE_NAME, int const QTD_LINHAS){
	FILE *arq = NULL;
	char row[TAMANHO_MAXIMO_CARACTERES_LINHA] = {0}, *result = {0};
	int count_lines = 0;
	struct Selecao* selecao = (struct Selecao*)malloc(sizeof(struct Selecao)*QTD_LINHAS);
	
	char* CADEIA_CARACTER_SEPARADOR_INTERNO_MULTI_SELECAO = (char*)malloc(sizeof(char));
	memset(CADEIA_CARACTER_SEPARADOR_INTERNO_MULTI_SELECAO, 0, sizeof(char));
	CADEIA_CARACTER_SEPARADOR_INTERNO_MULTI_SELECAO[0] = CARACTER_SEPARADOR_INTERNO_MULTI_SELECAO;
	
	char* CADEIA_CARACTER_SEPARADOR_SELECAO = (char*)malloc(sizeof(char));
	memset(CADEIA_CARACTER_SEPARADOR_SELECAO, 0, sizeof(char));
	CADEIA_CARACTER_SEPARADOR_SELECAO[0] = CARACTER_SEPARADOR_SELECAO;
	
	// Abre um arquivo TEXTO para LEITURA
	arq = fopen(FILE_NAME, "rt");
	if (arq == NULL){  // Se houve erro na abertura
		printf("Houve erro na abertura do arquivo: %s\n", FILE_NAME);
		return 0;
	}
	printf("Carregando as sele��es do arquivo: %s\n", FILE_NAME);
	while (!feof(arq)){
	  // L� uma linha (inclusive com o '\n')
	  result = fgets(row, TAMANHO_MAXIMO_CARACTERES_LINHA, arq);  // o 'fgets' l� at� TAMANHO_MAXIMO_CARACTERES_LINHA caracteres ou at� o '\n'
	  if (result){  // Se foi poss�vel ler
		char* sub_string_codigo = split_char_position(row, CARACTER_SEPARACAO, 0);
		char* sub_string_nome = split_char_position(row, CARACTER_SEPARACAO, 1);
		
		int tamanho_nome_com_separador = (strlen(sub_string_codigo) + strlen(CADEIA_CARACTER_SEPARADOR_INTERNO_MULTI_SELECAO));
		tamanho_nome_com_separador += (strlen(sub_string_nome) + strlen(CADEIA_CARACTER_SEPARADOR_SELECAO));
		
		char* nome_com_separador= (char*)malloc(sizeof(tamanho_nome_com_separador));
		strcat(nome_com_separador, sub_string_codigo);
		strcat(nome_com_separador, CADEIA_CARACTER_SEPARADOR_INTERNO_MULTI_SELECAO);
		strcat(nome_com_separador, sub_string_nome);
		strcat(nome_com_separador, CADEIA_CARACTER_SEPARADOR_SELECAO);
		int codigo = atoi(sub_string_codigo);
		selecao[count_lines].codigo_selecao = codigo;
		selecao[count_lines].conteudo_exibicao_selecao = nome_com_separador;
		selecao[count_lines].conteudo_selecao = nome_com_separador;
		count_lines++;
	  }
	}
	fclose(arq);
	return selecao;
}

char* retorna_valor_campo_file(const char* FILE_NAME, char* COLUMN_SEARCH_VALUE, int const COLUMN_SEARCH_INDEX, int const COLUMN_RETURN_INDEX){
	FILE *arq = NULL;
	char row[TAMANHO_MAXIMO_CARACTERES_LINHA] = {0}, *result = {0};
	char* campo_conteudo = NULL;
	
	// Abre um arquivo TEXTO para LEITURA
	arq = fopen(FILE_NAME, "rt");
	if (arq == NULL){  // Se houve erro na abertura
	 return 0;
	}
	while (!feof(arq)){
	  // L� uma linha (inclusive com o '\n')
	  result = fgets(row, TAMANHO_MAXIMO_CARACTERES_LINHA, arq);  // o 'fgets' l� at� TAMANHO_MAXIMO_CARACTERES_LINHA caracteres ou at� o '\n'
	  if (result){  // Se foi poss�vel ler
		char* sub_string = split_char_position(row, CARACTER_SEPARACAO, COLUMN_SEARCH_INDEX);
		char* sub_string_value = split_char_position(row, CARACTER_SEPARACAO, COLUMN_RETURN_INDEX);
		
		if(strcmp(sub_string, COLUMN_SEARCH_VALUE)==0){
			campo_conteudo = (char*)malloc(strlen(sub_string_value)*sizeof(char));
			strcpy(campo_conteudo, sub_string_value);
			break;
		}
		free(sub_string);
	  }
	}
	fclose(arq);
	return campo_conteudo;
}
#endif /* _FILEUTIL_H */
