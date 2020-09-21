#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include "lib/strutil.h"
#include "lib/porcaoalimento.h"
#include "lib/structutil.h"
#include "lib/definicoes.h"
#include "lib/fileutil.h"
#include "lib/pesquisa.h"

void imprime_bem_vindo_cadastro_porcao_alimento();
void cadastrar_nova_porcao_de_alimento();
void main_cadastro_porcao_alimento(char* codigo_perfil);
void imprime_porcao_de_alimentos_cadastradas();
void pesquisar_porcao_de_alimento();

//void main(){
//	main_cadastro_porcao_alimento("N");
//}

void main_cadastro_porcao_alimento(char* codigo_perfil){
	setlocale(LC_ALL, "Portuguese");
	imprime_bem_vindo_cadastro_porcao_alimento();
	int opcao = -1;
	do{
		if(strcmp(codigo_perfil, "N") == 0)
			printf("Entre com 1 para opção Cadastrar Nova Porção de alimento.\n");
		printf("Entre com 2 para opção Visualizar as Porções de alimento cadastradas.\n");
		printf("Entre com 3 para opção Pesquisar Porção de alimento.\n");
		printf("Ou entre com 0 para voltar: ");
		scanf("%d", &opcao);
		system("cls");
		switch(opcao){
			case 0:
				break;
			case 1:
				if(strcmp(codigo_perfil, "N") == 0){
					printf("Cadastro Nova Porção de alimento\n");
					cadastrar_nova_porcao_de_alimento();
				}
				else{
					printf("Você não tem permissão de acesso!\n");
					printf("Opção Inválida!\n");
					system("pause");
					system("cls");
				}
				imprime_bem_vindo_cadastro_porcao_alimento();
				break;
			case 2:
				imprime_porcao_de_alimentos_cadastradas();
				imprime_bem_vindo_cadastro_porcao_alimento();
				break;
			case 3:
				pesquisar_porcao_de_alimento();
				imprime_bem_vindo_cadastro_porcao_alimento();
				break;
			default:
				printf("Opção Inválida!\n");
				system("pause");
				system("cls");
				imprime_bem_vindo_cadastro_porcao_alimento();
				break;
		}
	}while(opcao != 0);
	printf("Retornando......\n");
	system("pause");
	system("cls");
}

void imprime_bem_vindo_cadastro_porcao_alimento(){
	printf("===============================================================\n");
	printf("==================== BEM-VINDO AO CADASTRO  ===================\n");
	printf("=============== DE PORÇÃO DE ALIMENTO DO DIET-C ===============\n");
	printf("===============================================================\n");
}

void cadastrar_nova_porcao_de_alimento(){
	/* Função que carrega o maior código de um arquivo */
	int max_codigo_porcao_alimento = retorna_last_id_file(CAMIMNHO_ARQUIVO_PORCAO_ALIMENTO);
	//int max_codigo_porcao_alimento =  0;//Mock
	max_codigo_porcao_alimento++;
	
	char* texto;
	struct PorcaoAlimento porcaoAlimento = carrega_porcao_alimento_input();
	porcaoAlimento.codigo_porcao_alimento = max_codigo_porcao_alimento;
	texto = monta_csv_texto_porcao_alimento(porcaoAlimento);
	char* mensagem_erro = "Ocorreu um erro ao salvar dados da porção de alimentos.";
	
	salvar_conteudo_em_arquivo(CAMIMNHO_ARQUIVO_PORCAO_ALIMENTO, texto, mensagem_erro);
}

void imprime_porcao_de_alimentos_cadastradas(){
	//char* mensagem_erro = "Não existem dados de porção de alimentos ou ocorreu algum erro na solicitação de leitura.";
	//char* cabecalho_tabela = monta_cabecalho_tabela_porcao_alimento();
	//imprime_conteudo_de_arquivo_em_formato_de_tabela(CAMIMNHO_ARQUIVO_PORCAO_ALIMENTO, mensagem_erro, cabecalho_tabela);
}

void pesquisar_porcao_de_alimento(){
	//char* mensagem_erro = "Não existem dados de porção de alimentos ou ocorreu algum erro na solicitação de leitura.";
	//monta_pesquisa_porcao_de_alimento(mensagem_erro);
}
