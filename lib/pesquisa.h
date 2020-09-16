#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "structutil.h"
#include "definicoes.h"
#include "fileutil.h"

#ifndef _PESQUISA_H
#define _PESQUISA_H

struct Pesquisa* retorna_pesquisa_padrao();

void executa_pesquisa_arquivo(struct Pesquisa* pesquisa, const char* FILE_NAME, char* mensagem_input_pesquisa, 
							  int const QTD_ITENS_PESQUISA, char* cabecalho_tabela, char* mensagem_erro);

struct Pesquisa* retorna_pesquisa_padrao(){
	struct Pesquisa* pesquisa = (struct Pesquisa*)malloc(sizeof(struct Pesquisa)*QTD_ITENS_PESQUISA_PADRAO);
	
	pesquisa[0].opcao = 1;
	pesquisa[0].nome_opcao = "Código";
	pesquisa[0].coluna_arquivo = 0;
	
	pesquisa[1].opcao = 2;
	pesquisa[1].nome_opcao = "Nome";
	pesquisa[1].coluna_arquivo = 1;
	
	pesquisa[2].opcao = 3;
	pesquisa[2].nome_opcao = "Descrição";
	pesquisa[2].coluna_arquivo = 2;
	
	return pesquisa;
}

void executa_pesquisa_arquivo(struct Pesquisa* pesquisa, const char* FILE_NAME, char* mensagem_input_pesquisa, 
							  int const QTD_ITENS_PESQUISA, char* cabecalho_tabela, char* mensagem_erro){
	int opcao = -1, opcao_pesquisar_novamente = -1, i = 0;
	do{
		char* valor_pesquisa = retorna_pesquisa_input_normalized_escape_char(mensagem_input_pesquisa);	
		do{
			printf("Valor a ser pesquisado:%s\n", valor_pesquisa);
			for(i=0; i<QTD_ITENS_PESQUISA; i++)
				printf("Entre com %d para opção Pesquisar por %s\n", pesquisa[i].opcao, pesquisa[i].nome_opcao);
			printf("Ou entre com 0 para voltar: ");
			scanf("%d", &opcao);
			system("cls");
			
			if(opcao != 0){
				if(opcao > 0 && opcao <= QTD_ITENS_PESQUISA){
					for(i=0; i<QTD_ITENS_PESQUISA; i++){
						if(pesquisa[i].opcao == opcao){
							pesquisa_conteudo_em_arquivo(FILE_NAME, valor_pesquisa, pesquisa[i].coluna_arquivo, mensagem_erro, cabecalho_tabela);
						}
					}
				}
				else{
					printf("Opção Inválida!\n");
					system("pause");
					system("cls");
				}
			}
		}while(opcao != 0);
		
		do{
			printf("Deseja efetuar uma nova pesquisa? 1-sim/0-não:");
			scanf("%d", &opcao_pesquisar_novamente);	
		}while(opcao_pesquisar_novamente != 1 && opcao_pesquisar_novamente != 0);
		
	}while(opcao_pesquisar_novamente!=0);
	
	printf("Retornando......\n");
	system("pause");
	system("cls");
}

#endif /* _PESQUISA_H */
