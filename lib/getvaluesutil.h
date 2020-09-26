#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "strutil.h"

#ifndef _GETVALUESUTIL_H
#define _GETVALUESUTIL_H

char* retorna_nome_input(char* module_message);

char * retorna_nome_input_normalized_escape_char(char* module_message);

char* retorna_descricao_input(char* module_message);

char* retorna_descricao_input_normalized_escape_char(char* module_message);

char* retorna_codigo_input(char* codigo_nome);

char* retorna_codigo_input_normalized_escape_char(char* codigo_nome);

char* retorna_pesquisa_input(char* module_message);

char* retorna_pesquisa_input_normalized_escape_char(char* module_message);

char* retorna_padrao_input(char* nome_input, char* module_message);

char* retorna_padrao_input_normalized_escape_char(char* nome_input, char* module_message);

char* retorna_codigo_input(char* codigo_nome){
	char* codigo = (char*)malloc(sizeof(char)*TAMANHO_MAXIMO_CARACTERES_CODIGO);
	memset(codigo, 0, sizeof(char)*TAMANHO_MAXIMO_CARACTERES_CODIGO);
	printf("Entre com o %s (até %d caracteres):", codigo_nome, TAMANHO_MAXIMO_CARACTERES_CODIGO);
	setbuf(stdin, NULL);
	fgets(codigo, TAMANHO_MAXIMO_CARACTERES_NOME, stdin);
	return codigo;
}

char* retorna_codigo_input_normalized_escape_char(char* codigo_nome){
	char* codigo = retorna_codigo_input(codigo_nome);
	return str_normalize_escape_char(codigo);
}

char* retorna_nome_input(char* module_message){
	char* nome = (char*)malloc(sizeof(char)*TAMANHO_MAXIMO_CARACTERES_NOME);
	printf("Entre com o nome %s (até %d caracteres):", module_message, TAMANHO_MAXIMO_CARACTERES_NOME);
	memset(nome, 0, sizeof(char)*TAMANHO_MAXIMO_CARACTERES_NOME);
	setbuf(stdin, NULL);
	fgets(nome, TAMANHO_MAXIMO_CARACTERES_NOME, stdin);
	return nome;
}

char * retorna_nome_input_normalized_escape_char(char* module_message){
	char* nome = retorna_nome_input(module_message);
	return str_normalize_escape_char(nome);
}

char* retorna_descricao_input(char* module_message){
	char* descricao = (char*)malloc(sizeof(char)*TAMANHO_MAXIMO_CARACTERES_DESCRICAO);
	printf("Entre com a descrição %s (até %d caracteres):", module_message,  TAMANHO_MAXIMO_CARACTERES_DESCRICAO);
	memset(descricao, 0, sizeof(char)*TAMANHO_MAXIMO_CARACTERES_DESCRICAO);
	setbuf(stdin, NULL);
	fgets(descricao, TAMANHO_MAXIMO_CARACTERES_DESCRICAO, stdin);
	return descricao;
}

char* retorna_descricao_input_normalized_escape_char(char* module_message){
	char* descricao = retorna_descricao_input(module_message);
	return str_normalize_escape_char(descricao);
}

char* retorna_pesquisa_input(char* module_message){
	char* pesquisa = (char*)malloc(sizeof(char)*TAMANHO_MAXIMO_CARACTERES_PESQUISA);
	printf("Entre com o valor para ser pesquisado em: %s (até %d caracteres):", module_message,  TAMANHO_MAXIMO_CARACTERES_PESQUISA);
	memset(pesquisa, 0, sizeof(char)*TAMANHO_MAXIMO_CARACTERES_PESQUISA);
	setbuf(stdin, NULL);
	fgets(pesquisa, TAMANHO_MAXIMO_CARACTERES_DESCRICAO, stdin);
	return pesquisa;
}

char* retorna_pesquisa_input_normalized_escape_char(char* module_message){
	char* pesquisa = retorna_pesquisa_input(module_message);
	return str_normalize_escape_char(pesquisa);
}

char* retorna_padrao_input(char* nome_input, char* module_message){
	char* input = (char*)malloc(sizeof(char)*TAMANHO_MAXIMO_CARACTERES_INPUT_PADRAO);
	printf("Entre com o %s %s (até %d caracteres):", nome_input, module_message, TAMANHO_MAXIMO_CARACTERES_INPUT_PADRAO);
	memset(input, 0, sizeof(char)*TAMANHO_MAXIMO_CARACTERES_INPUT_PADRAO);
	setbuf(stdin, NULL);
	fgets(input, TAMANHO_MAXIMO_CARACTERES_INPUT_PADRAO, stdin);
	return input;
}

char* retorna_padrao_input_normalized_escape_char(char* nome_input, char* module_message){
	char* input = retorna_padrao_input(nome_input, module_message);
	return str_normalize_escape_char(input);
}

#endif /* _GETVALUESUTIL_H */
