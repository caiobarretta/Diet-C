#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "diasemanautil.h"
#include "refeicoesutil.h"
#include "definicoes.h"
#include "strutil.h"
#include "structutil.h"
#include "getvaluesutil.h"
#include "pesquisa.h"
#include "fileutil.h"
#include "porcaoalimento.h"

#ifndef _STRUCTDIETA_H
#define _STRUCTDIETA_H

struct Dieta carrega_dieta_input();

char* monta_csv_texto_dieta(struct Dieta dieta);

int len_dieta(struct Dieta dieta);

char* retorna_codigo_dieta_input();

char* retorna_nome_dieta_input();

char* retorna_descricao_dieta_input();

void monta_pesquisa_dieta(char* mensagem_erro);

char* retorna_codigo_dieta_input(){
	return retorna_codigo_input_normalized_escape_char("código da dieta");
}

char* retorna_nome_dieta_input(){
	return retorna_nome_input_normalized_escape_char("da dieta");
}

char* retorna_descricao_dieta_input(){	
	return retorna_descricao_input_normalized_escape_char("da dieta");
}

struct Dieta carrega_dieta_input(){
	struct Dieta dieta;
	
	dieta.nome = retorna_nome_dieta_input();
	dieta.descricao = retorna_descricao_dieta_input();
	dieta.porcoes = retorna_porcoes_input();
	
	return dieta;
}

char* monta_csv_texto_dieta(struct Dieta dieta){
	int i = 0;
	int const quantidade_de_virgulas = 4;
	
	char* CADEIA_CARACTER_SEPARACAO = (char*)malloc(sizeof(char));
	memset(CADEIA_CARACTER_SEPARACAO, 0, sizeof(char));
	CADEIA_CARACTER_SEPARACAO[0] = CARACTER_SEPARACAO;
	
	int len = len_dieta(dieta);
	for(i = 0; i<quantidade_de_virgulas; i++)
		len += strlen(CADEIA_CARACTER_SEPARACAO);
		
	len += strlen(CARACTER_FINAL_DE_LINHA);
	
	char* texto = (char*)malloc(sizeof(char)*len);
	memset(texto, 0, sizeof(char)*len);
	
	char codigo_dieta[TAMANHO_MAXIMO_CARACTERES_CODIGO];
	memset(codigo_dieta, 0, TAMANHO_MAXIMO_CARACTERES_CODIGO);
	convert_int_to_string(dieta.codigo_dieta, codigo_dieta);
	
	strcat(texto, codigo_dieta);
	strcat(texto, CADEIA_CARACTER_SEPARACAO);
	
	strcat(texto, dieta.nome);
	strcat(texto, CADEIA_CARACTER_SEPARACAO);
	
	strcat(texto, dieta.descricao);
	strcat(texto, CADEIA_CARACTER_SEPARACAO);
	
	strcat(texto, dieta.porcoes);
	
	strcat(texto, CARACTER_FINAL_DE_LINHA);
	
	return texto;
}

int len_dieta(struct Dieta dieta){
	int len = 0;
	int i = 0;
	
	char codigo_dieta[100];
	convert_int_to_string(dieta.codigo_dieta, codigo_dieta);
	
	len += strlen(codigo_dieta);
	len += strlen(dieta.nome);
	len += strlen(dieta.descricao);
	len += strlen(dieta.porcoes);
	
	return len;
}

char* monta_cabecalho_tabela_dieta(){
	return "codigo_dieta|nome|descricao|porcaoalimento";
}

void monta_pesquisa_dieta(char* mensagem_erro){
	char* cabecalho_tabela = monta_cabecalho_tabela_dieta();
	char* mensagem_input_pesquisa = "dieta";
	
	struct Pesquisa* pesquisa = (struct Pesquisa*)malloc(sizeof(struct Pesquisa)*QTD_ITENS_PESQUISA_PADRAO);
	pesquisa  = retorna_pesquisa_padrao();	
	
	executa_pesquisa_arquivo(pesquisa, CAMIMNHO_ARQUIVO_DIETA, mensagem_input_pesquisa, QTD_ITENS_PESQUISA_PADRAO, cabecalho_tabela, mensagem_erro);
	
}

#endif /* _STRUCTDIETA_H */
