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

char* retorna_dietas_input();

int retorna_qtd_dieta();

char* retorna_codigo_dieta_input(){
	return retorna_codigo_input_normalized_escape_char("c�digo da dieta");
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
	//printf("struct Dieta carrega_dieta_input()1\n");
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
	
	free(CADEIA_CARACTER_SEPARACAO);
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
	free(pesquisa);	
}

char* retorna_dietas_input(){
	int qtd_dieta = retorna_qtd_dieta();
	
	int vetor_opcoes[qtd_dieta];
	memset(vetor_opcoes, 0, sizeof(int)*qtd_dieta);
	
	struct Selecao* selecao = (struct Selecao*)malloc(sizeof(struct Selecao)*qtd_dieta);
	memset(selecao, 0, sizeof(struct Selecao)*qtd_dieta);
	
	selecao = carrega_selecao_de_arquivo(CAMIMNHO_ARQUIVO_DIETA, qtd_dieta);
	char* itens_selecionados = monta_menu_selecao(vetor_opcoes, qtd_dieta, selecao, selecao_obrigatoria);
	free(selecao);
	return itens_selecionados;
}

int retorna_qtd_dieta(){
	return retorna_quantidade_registro_arquivo(CAMIMNHO_ARQUIVO_DIETA);
}

void retorna_sugestao_dieta_paciente(int codigo_usuario){
	
	printf("Dieta(s) Recomendadas:\n\n");
	char codigo_usuario_str[TAMANHO_MAXIMO_CARACTERES_CODIGO];
	memset(codigo_usuario_str, 0, TAMANHO_MAXIMO_CARACTERES_CODIGO);
	convert_int_to_string(codigo_usuario, codigo_usuario_str);
	
	char* dietas = retorna_valor_campo_file(CAMIMNHO_ARQUIVO_PACIENTE, codigo_usuario_str, 4, 3);
	int i = 0, quantidade_dietas = 0;
	
	for(i=0; i<strlen(dietas); i++){
		if(dietas[i] == CARACTER_SEPARADOR_SELECAO)
			quantidade_dietas++;
	}
	
	for(i=0; i<quantidade_dietas; i++){
		char* dieta = split_char_position(dietas, CARACTER_SEPARADOR_SELECAO, i);
		char* codigo_dieta = split_char_position(dieta, CARACTER_SEPARADOR_INTERNO_MULTI_SELECAO, 0);
		char* dieta_nome = split_char_position(dieta, CARACTER_SEPARADOR_INTERNO_MULTI_SELECAO, 1);
		printf("Dieta:%s\n", dieta_nome);
		char* porcoes = retorna_valor_campo_file(CAMIMNHO_ARQUIVO_DIETA, codigo_dieta, 0, 3);
		printf("Por��es:%s\n", porcoes);
	}
	printf("\n\n");
}

#endif /* _STRUCTDIETA_H */
