#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "strutil.h"

#ifndef _SELECAOUTIL_H
#define _SELECAOUTIL_H

enum TipoSelecao{
	selecao_obrigatoria=0,
	selecao_opcional=1
};

char* monta_menu_selecao(int* opcoes, int const QTD_OPCOES, struct Selecao* selecao, enum TipoSelecao tipo_selecao);

char* carrega_opcoes(int* const opcoes, struct Selecao* selecao, int const QTD_OPCOES);

char* carrega_opcoes(int* const opcoes, struct Selecao* selecao, int const QTD_OPCOES){
	int i = 0, count_dias=0, len_opcoes=0;
	for(i=0; i<QTD_OPCOES; i++){
		if(opcoes[i] == 1){
			count_dias++;
			len_opcoes += strlen(selecao[i].conteudo_selecao);
		}
	}
	char* opcoes_selecionadas = (char*)malloc(sizeof(char)*len_opcoes);
	memset(opcoes_selecionadas, 0, sizeof(char)*len_opcoes);
	for(i=0; i<QTD_OPCOES; i++){
		if(opcoes[i] == 1){
			strcat(opcoes_selecionadas, selecao[i].conteudo_selecao);
		}
	}
	if(len_opcoes == 0){
		return VALOR_SELECAO_VAZIA;
	}
	if(len_opcoes == 1){
		char * opcao_selecionada =  (char*)malloc(sizeof(char)*strlen(opcoes_selecionadas)-1);
		memset(opcao_selecionada, 0, sizeof(char)*strlen(opcoes_selecionadas)-1);
		remove_char(opcao_selecionada, opcoes_selecionadas, CARACTER_SEPARADOR_SELECAO);
		return opcao_selecionada;
	}
	return opcoes_selecionadas;
}

char* monta_menu_selecao(int* opcoes, int const QTD_OPCOES, struct Selecao* selecao, enum TipoSelecao tipo_selecao){
	int opcao = -1, i=0;
	do{
		char* opcoes_escolhidas = carrega_opcoes(opcoes, selecao, QTD_OPCOES);
		printf("Opções selecionadas:%s.\n", opcoes_escolhidas);
		for(i=0; i<QTD_OPCOES; i++){
			printf("Entre com %d para adicionar/remover %s.\n", selecao[i].codigo_selecao, selecao[i].conteudo_exibicao_selecao);
		}
		printf("Ou entre com 0 para voltar: ");
		scanf("%d", &opcao);
		system("cls");
		if(opcao == 0){
			if(tipo_selecao == selecao_obrigatoria && strcmp(opcoes_escolhidas, VALOR_SELECAO_VAZIA)==0){
				printf("Valor da seleção obrigatório!\n");
				system("pause");
				system("cls");
			}
			else if(tipo_selecao == selecao_opcional || 
			(tipo_selecao == selecao_obrigatoria && strcmp(opcoes_escolhidas, VALOR_SELECAO_VAZIA)!=0)){
				printf("Retornando......\n");
				system("pause");
				system("cls");
				return opcoes_escolhidas;
			}
			else{
				printf("Tipo de seleção não implementada\n");
				system("pause");
				system("cls");
				return NULL;
			}
			
		}
		if(opcao >= 1 && opcao <= QTD_OPCOES){
			if(opcoes[opcao-1] == 0)
				opcoes[opcao-1] = 1;
			else
				opcoes[opcao-1] = 0;
		}
		else{
			printf("Opção Inválida!\n");
			system("pause");
			system("cls");
		}
	}while(1==1);
}

#endif /* _SELECAOUTIL_H */
