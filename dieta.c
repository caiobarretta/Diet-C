#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include "lib/strutil.h"
#include "lib/dieta.h"
#include "lib/structutil.h"
#include "lib/definicoes.h"
#include "lib/fileutil.h"
#include "lib/pesquisa.h"

#ifndef _DIETA_C
#define _DIETA_C

void imprime_bem_vindo_cadastro_dieta();

void cadastrar_nova_dieta();

void main_cadastro_dieta(char* codigo_perfil);

void imprime_dietas_cadastradas();

void pesquisar_dieta();

void main_cadastro_dieta(char* codigo_perfil){
	setlocale(LC_ALL, "Portuguese");
	imprime_bem_vindo_cadastro_dieta();
	int opcao = -1;
	do{
		if(strcmp(codigo_perfil, "N") == 0)
			printf("Entre com 1 para opção Cadastrar Nova Dieta.\n");
		printf("Entre com 2 para opção Visualizar as Dietas cadastradas.\n");
		printf("Entre com 3 para opção Pesquisar Dietas.\n");
		printf("Ou entre com 0 para voltar: ");
		scanf("%d", &opcao);
		system("cls");
		switch(opcao){
			case 0:
				break;
			case 1:
				if(strcmp(codigo_perfil, "N") == 0){
					printf("Cadastro Nova Porção de alimento\n");
					cadastrar_nova_dieta();
				}
				else{
					printf("Você não tem permissão de acesso!\n");
					printf("Opção Inválida!\n");
					system("pause");
					system("cls");
				}
				imprime_bem_vindo_cadastro_dieta();
				break;
			case 2:
				imprime_dietas_cadastradas();
				imprime_bem_vindo_cadastro_dieta();
				break;
			case 3:
				pesquisar_dieta();
				imprime_bem_vindo_cadastro_dieta();
				break;
			default:
				printf("Opção Inválida!\n");
				system("pause");
				system("cls");
				imprime_bem_vindo_cadastro_dieta();
				break;
		}
	}while(opcao != 0);
	printf("Retornando......\n");
	system("pause");
	system("cls");
}

void imprime_bem_vindo_cadastro_dieta(){
	printf("===============================================================\n");
	printf("==================== BEM-VINDO AO CADASTRO  ===================\n");
	printf("===================== DE DIETAS DO DIET-C =====================\n");
	printf("===============================================================\n");
}

void cadastrar_nova_dieta(){
	/* Função que carrega o maior código de um arquivo */
	int max_codigo_dieta = retorna_last_id_file(CAMIMNHO_ARQUIVO_DIETA);
	max_codigo_dieta++;
	
	char* texto;
	struct Dieta dieta = carrega_dieta_input();
	dieta.codigo_dieta = max_codigo_dieta;
	texto = monta_csv_texto_dieta(dieta);
	char* mensagem_erro = "Ocorreu um erro ao salvar dados da dietas.";
	
	salvar_conteudo_em_arquivo(CAMIMNHO_ARQUIVO_DIETA, texto, mensagem_erro);
}

void imprime_dietas_cadastradas(){
	char* mensagem_erro = "Não existem dados de dietas ou ocorreu algum erro na solicitação de leitura.";
	char* cabecalho_tabela = monta_cabecalho_tabela_dieta();
	imprime_conteudo_de_arquivo_em_formato_de_tabela(CAMIMNHO_ARQUIVO_DIETA, mensagem_erro, cabecalho_tabela);
}

void pesquisar_dieta(){
	char* mensagem_erro = "Não existem dados de dietas ou ocorreu algum erro na solicitação de leitura.";
	monta_pesquisa_dieta(mensagem_erro);
}

#endif /* _DIETA_C */
