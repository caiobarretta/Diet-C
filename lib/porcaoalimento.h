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
#include "selecaoutil.h"

#ifndef _STRUCTPORCAOALIMENTO_H
#define _STRUCTPORCAOALIMENTO_H

struct PorcaoAlimento carrega_porcao_alimento_input();

char* monta_csv_texto_porcao_alimento(struct PorcaoAlimento porcaoAlimento);

int len_porcao_alimento(struct PorcaoAlimento porcaoAlimento);

char* retorna_codigo_porcao_alimento_input();

char* retorna_nome_porcao_alimento_input();

char* retorna_descricao_porcao_alimento_input();

void monta_pesquisa_porcao_de_alimento(char* mensagem_erro);

char* retorna_porcoes_input();

int retorna_qtd_porcao_alimento();

char* retorna_codigo_porcao_alimento_input(){
	return retorna_codigo_input_normalized_escape_char("código da porção de alimento");
}

char* retorna_nome_porcao_alimento_input(){
	return retorna_nome_input_normalized_escape_char("da porção de alimento");
}

char* retorna_descricao_porcao_alimento_input(){	
	return retorna_descricao_input_normalized_escape_char("da porção de alimento");
}

struct PorcaoAlimento carrega_porcao_alimento_input(){
	struct PorcaoAlimento porcaoAlimento;
	
	porcaoAlimento.nome = retorna_nome_porcao_alimento_input();
	porcaoAlimento.descricao = retorna_descricao_porcao_alimento_input();
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
	
	char codigo_porcao_alimento[TAMANHO_MAXIMO_CARACTERES_CODIGO];
	memset(codigo_porcao_alimento, 0, TAMANHO_MAXIMO_CARACTERES_CODIGO);
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

char* monta_cabecalho_tabela_porcao_alimento(){
	return "codigo_porcao_alimento|nome|descricao|dia_da_semana|refeicoes";
}

void monta_pesquisa_porcao_de_alimento(char* mensagem_erro){
	char* cabecalho_tabela = monta_cabecalho_tabela_porcao_alimento();
	char* mensagem_input_pesquisa = "porção de alimento";
	
	struct Pesquisa* pesquisa = (struct Pesquisa*)malloc(sizeof(struct Pesquisa)*QTD_ITENS_PESQUISA_PADRAO);
	pesquisa  = retorna_pesquisa_padrao();	
	
	executa_pesquisa_arquivo(pesquisa, CAMIMNHO_ARQUIVO_PORCAO_ALIMENTO, mensagem_input_pesquisa, QTD_ITENS_PESQUISA_PADRAO, cabecalho_tabela, mensagem_erro);
	free(pesquisa);
}

char* retorna_porcoes_input(){
	int qtd_porcao_alimento = retorna_qtd_porcao_alimento();
	int vetor_opcoes[qtd_porcao_alimento];
	memset(vetor_opcoes, 0, sizeof(int)*qtd_porcao_alimento);
	
	struct Selecao* selecao = (struct Selecao*)malloc(sizeof(struct Selecao)*qtd_porcao_alimento);
	memset(selecao, 0, sizeof(struct Selecao)*qtd_porcao_alimento);
	
	selecao = carrega_selecao_de_arquivo(CAMIMNHO_ARQUIVO_PORCAO_ALIMENTO, qtd_porcao_alimento);
	char* itens_selecionados = monta_menu_selecao(vetor_opcoes, qtd_porcao_alimento, selecao, selecao_obrigatoria);
	free(selecao);
	return itens_selecionados;
}

int retorna_qtd_porcao_alimento(){
	return retorna_quantidade_registro_arquivo(CAMIMNHO_ARQUIVO_PORCAO_ALIMENTO);
}

#endif /* _STRUCTPORCAOALIMENTO_H */
