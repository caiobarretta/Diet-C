#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structutil.h"
#include "definicoes.h"
#include "selecaoutil.h"

#ifndef _REFEICOESUTIL_H
#define _REFEICOESUTIL_H

char* carrega_refeicoes_input();
struct Selecao* carrega_selecao_refeicoes();

//Cafe da manha|Brunch|Almoco|Lanche|Jantar|Sobremesa|Ceia|
char* carrega_refeicoes_input(){
	
	int vetor_opcoes[QTD_REFEICOES];
	memset(vetor_opcoes, 0, sizeof(int)*QTD_REFEICOES);
	setlocale(LC_ALL, "Portuguese");
	
	struct Selecao* selecao = (struct Selecao*)malloc(sizeof(struct Selecao)*QTD_REFEICOES);
	selecao = carrega_selecao_refeicoes();
	return monta_menu_selecao(vetor_opcoes, QTD_DIAS_DA_SEMANA, selecao, selecao_obrigatoria);
}

struct Selecao* carrega_selecao_refeicoes(){
	struct Selecao* selecao = (struct Selecao*)malloc(sizeof(struct Selecao)*QTD_REFEICOES);
	//Cafe da manha|Brunch|Almoco|Lanche|Jantar|Sobremesa|Ceia|
	selecao[0].codigo_selecao = 1;
	selecao[0].conteudo_selecao = "Cafe da manha|";
	selecao[0].conteudo_exibicao_selecao = "Cafe da manha";
	
	selecao[1].codigo_selecao = 2;
	selecao[1].conteudo_selecao = "Brunch|";
	selecao[1].conteudo_exibicao_selecao = "Brunch";
	
	selecao[2].codigo_selecao = 3;
	selecao[2].conteudo_selecao = "Almoco|";
	selecao[2].conteudo_exibicao_selecao = "Almoco";
	
	selecao[3].codigo_selecao = 4;
	selecao[3].conteudo_selecao = "Lanche|";
	selecao[3].conteudo_exibicao_selecao = "Lanche";
	
	selecao[4].codigo_selecao = 5;
	selecao[4].conteudo_selecao = "Jantar|";
	selecao[4].conteudo_exibicao_selecao = "Jantar";
	
	selecao[5].codigo_selecao = 6;
	selecao[5].conteudo_selecao = "Sobremesa|";
	selecao[5].conteudo_exibicao_selecao = "Sobremesa";
	
	selecao[6].codigo_selecao = 7;
	selecao[6].conteudo_selecao = "Ceia|";
	selecao[6].conteudo_exibicao_selecao = "Ceia";

	return selecao;
}

#endif /* _REFEICOESUTIL_H */
