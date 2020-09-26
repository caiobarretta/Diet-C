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
#include "dieta.h"
#include "usuario.h"

#ifndef _STRUCTPACIENTE_H
#define _STRUCTPACIENTE_H

struct Paciente carrega_paciente_input();

char* monta_csv_texto_paciente(struct Paciente paciente);

int len_paciente(struct Paciente paciente);

char* retorna_codigo_paciente_input();

char* retorna_nome_paciente_input();

char* retorna_descricao_paciente_input();

void monta_pesquisa_paciente(char* mensagem_erro);

char* retorna_codigo_paciente_input(){
	return retorna_codigo_input_normalized_escape_char("código do paciente");
}

char* retorna_nome_paciente_input(){
	return retorna_nome_input_normalized_escape_char("da paciente");
}

char* retorna_descricao_paciente_input(){	
	return retorna_descricao_input_normalized_escape_char("da paciente");
}

struct Paciente carrega_paciente_input(){
	struct Paciente paciente;
	paciente.nome = retorna_nome_paciente_input();
	paciente.descricao = retorna_descricao_paciente_input();
	paciente.dietas = retorna_dietas_input();
	
	paciente.login = carrega_login_input();
	return paciente;
}

char* monta_csv_texto_paciente(struct Paciente paciente){
	int i = 0;
	int const quantidade_de_virgulas = 4;
	
	char* CADEIA_CARACTER_SEPARACAO = (char*)malloc(sizeof(char));
	memset(CADEIA_CARACTER_SEPARACAO, 0, sizeof(char));
	CADEIA_CARACTER_SEPARACAO[0] = CARACTER_SEPARACAO;
	
	int len = len_paciente(paciente);
	for(i = 0; i<quantidade_de_virgulas; i++)
		len += strlen(CADEIA_CARACTER_SEPARACAO);
		
	len += strlen(CARACTER_FINAL_DE_LINHA);
	
	char* texto = (char*)malloc(sizeof(char)*len);
	memset(texto, 0, sizeof(char)*len);
	
	char codigo_paciente[TAMANHO_MAXIMO_CARACTERES_CODIGO];
	memset(codigo_paciente, 0, TAMANHO_MAXIMO_CARACTERES_CODIGO);
	convert_int_to_string(paciente.codigo_paciente, codigo_paciente);
	
	strcat(texto, codigo_paciente);
	strcat(texto, CADEIA_CARACTER_SEPARACAO);
	
	strcat(texto, paciente.nome);
	strcat(texto, CADEIA_CARACTER_SEPARACAO);
	
	strcat(texto, paciente.descricao);
	strcat(texto, CADEIA_CARACTER_SEPARACAO);
	
	strcat(texto, paciente.dietas);
	
	strcat(texto, CARACTER_FINAL_DE_LINHA);
	
	return texto;
}

int len_paciente(struct Paciente paciente){
	int len = 0;
	int i = 0;
	
	char codigo_paciente[100];
	convert_int_to_string(paciente.codigo_paciente, codigo_paciente);
	
	len += strlen(codigo_paciente);
	len += strlen(paciente.nome);
	len += strlen(paciente.descricao);
	len += strlen(paciente.dietas);
	
	return len;
}

char* monta_cabecalho_tabela_paciente(){
	return "codigo_paciente|nome|descricao|dietas";
}

void monta_pesquisa_paciente(char* mensagem_erro){
	char* cabecalho_tabela = monta_cabecalho_tabela_paciente();
	char* mensagem_input_pesquisa = "paciente";
	
	struct Pesquisa* pesquisa = (struct Pesquisa*)malloc(sizeof(struct Pesquisa)*QTD_ITENS_PESQUISA_PADRAO);
	pesquisa  = retorna_pesquisa_padrao();	
	
	executa_pesquisa_arquivo(pesquisa, CAMIMNHO_ARQUIVO_PACIENTE, mensagem_input_pesquisa, QTD_ITENS_PESQUISA_PADRAO, cabecalho_tabela, mensagem_erro);
	
}

#endif /* _STRUCTPACIENTE_H */
