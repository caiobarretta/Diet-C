#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structutil.h"
#include "definicoes.h"
#include "selecaoutil.h"

#ifndef _DIASEMANAUTIL_H
#define _DIASEMANAUTIL_H

char* carrega_dias_da_semana_input();

struct Selecao* carrega_selecao_dias_da_semana();

//dom|seg|ter|qua|qui|sex|sab|
char* carrega_dias_da_semana_input(){
	int vetor_opcoes[QTD_DIAS_DA_SEMANA];
	memset(vetor_opcoes, 0, sizeof(int)*QTD_DIAS_DA_SEMANA);
	setlocale(LC_ALL, "Portuguese");
	
	struct Selecao* selecao = (struct Selecao*)malloc(sizeof(struct Selecao)*QTD_DIAS_DA_SEMANA);
	selecao = carrega_selecao_dias_da_semana();
	return monta_menu_selecao(vetor_opcoes, QTD_DIAS_DA_SEMANA, selecao, selecao_opcional);
}

struct Selecao* carrega_selecao_dias_da_semana(){
	struct Selecao* selecao = (struct Selecao*)malloc(sizeof(struct Selecao)*QTD_DIAS_DA_SEMANA);
		
	selecao[0].codigo_selecao = 1;
	selecao[0].conteudo_selecao = "dom|";
	selecao[0].conteudo_exibicao_selecao = "domingo";
	
	selecao[1].codigo_selecao = 2;
	selecao[1].conteudo_selecao = "seg|";
	selecao[1].conteudo_exibicao_selecao = "segunda-feira";
	
	selecao[2].codigo_selecao = 3;
	selecao[2].conteudo_selecao = "ter|";
	selecao[2].conteudo_exibicao_selecao = "terça-feira";
	
	selecao[3].codigo_selecao = 4;
	selecao[3].conteudo_selecao = "qua|";
	selecao[3].conteudo_exibicao_selecao = "quarta-feira";
	
	selecao[4].codigo_selecao = 5;
	selecao[4].conteudo_selecao = "qui|";
	selecao[4].conteudo_exibicao_selecao = "quinta-feira";
	
	selecao[5].codigo_selecao = 6;
	selecao[5].conteudo_selecao = "sex|";
	selecao[5].conteudo_exibicao_selecao = "sexta-feira";
	
	selecao[6].codigo_selecao = 7;
	selecao[6].conteudo_selecao = "sab|";
	selecao[6].conteudo_exibicao_selecao = "sábado";

	return selecao;
}

#endif /* _DIASEMANAUTIL_H */
