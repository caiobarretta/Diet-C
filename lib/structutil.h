#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "diasemanautil.h"
#include "refeicoesutil.h"
#include "definicoes.h"
#include "strutil.h"

#ifndef _STRUCTUTIL_H
#define _STRUCTUTIL_H

struct Login{
	int codigo_usuario;
	char* usuario;
	char* senha;
	char* codigo_perfil;
};

struct PorcaoAlimento{
	int codigo_porcao_alimento;
	char* nome;
	char* descricao;
	char* dia_da_semana;
	char* refeicoes;
};

struct PorcaoAlimento carrega_porcao_alimento_input();
char* monta_csv_texto_porcao_alimento(struct PorcaoAlimento porcaoAlimento);
int len_porcao_alimento(struct PorcaoAlimento porcaoAlimento);

struct PorcaoAlimento carrega_porcao_alimento_input(){
	struct PorcaoAlimento porcaoAlimento;
	
	char* nome = (char*)malloc(sizeof(char)*TAMANHO_MAXIMO_CARACTERES_NOME);
	printf("Entre com o nome da porção de alimento (até %d caracteres):", TAMANHO_MAXIMO_CARACTERES_NOME);
	setbuf(stdin, NULL);
	fgets(nome, TAMANHO_MAXIMO_CARACTERES_NOME, stdin);
	porcaoAlimento.nome = str_normalize_escape_char(nome);
	
	
	char* descricao = (char*)malloc(sizeof(char)*TAMANHO_MAXIMO_CARACTERES_DESCRICAO);
	printf("Entre com a descrição da porção de alimento (até %d caracteres):", TAMANHO_MAXIMO_CARACTERES_DESCRICAO);
	setbuf(stdin, NULL);
	fgets(descricao, TAMANHO_MAXIMO_CARACTERES_DESCRICAO, stdin);
	porcaoAlimento.descricao = str_normalize_escape_char(descricao);
	
	porcaoAlimento.dia_da_semana = carrega_dias_da_semana_input();
	porcaoAlimento.refeicoes = carrega_refeicoes_input();
	return porcaoAlimento;
}

char* monta_csv_texto_porcao_alimento(struct PorcaoAlimento porcaoAlimento){
	int i = 0;
	int const quantidade_de_virgulas = 4;
	
	char* CADEIA_CARACTER_SEPARACAO = (char*)malloc(sizeof(char));
	memset(CADEIA_CARACTER_SEPARACAO, 0, sizeof(char));
	CADEIA_CARACTER_SEPARACAO[0] = CARACTER_SEPARACAO;
	
	int len = len_porcao_alimento(porcaoAlimento);
	for(i = 0; i<quantidade_de_virgulas; i++)
		len += strlen(CADEIA_CARACTER_SEPARACAO);
		
	len += strlen(CARACTER_FINAL_DE_LINHA);
	
	char* texto = (char*)malloc(sizeof(char)*len);
	memset(texto, 0, sizeof(char)*len);
	
	char codigo_porcao_alimento[100];
	memset(codigo_porcao_alimento, 0, 100);
	convert_int_to_string(porcaoAlimento.codigo_porcao_alimento, codigo_porcao_alimento);
	
	strcat(texto, codigo_porcao_alimento);
	strcat(texto, CADEIA_CARACTER_SEPARACAO);
	
	strcat(texto, porcaoAlimento.nome);
	strcat(texto, CADEIA_CARACTER_SEPARACAO);
	
	strcat(texto, porcaoAlimento.descricao);
	strcat(texto, CADEIA_CARACTER_SEPARACAO);
	
	strcat(texto, porcaoAlimento.dia_da_semana);
	strcat(texto, CADEIA_CARACTER_SEPARACAO);
	
	strcat(texto, porcaoAlimento.refeicoes);
	
	strcat(texto, CARACTER_FINAL_DE_LINHA);
	
	return texto;
}

int len_porcao_alimento(struct PorcaoAlimento porcaoAlimento){
	int len = 0;
	int i = 0;
	
	char codigo_porcao_alimento[100];
	convert_int_to_string(porcaoAlimento.codigo_porcao_alimento, codigo_porcao_alimento);
	
	len += strlen(codigo_porcao_alimento);
	len += strlen(porcaoAlimento.nome);
	len += strlen(porcaoAlimento.descricao);
	len += strlen(porcaoAlimento.dia_da_semana);
	len += strlen(porcaoAlimento.refeicoes);
	
	return len;
}

#endif /* _STRUCTUTIL_H */
