#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include "lib/strutil.h"
#include "lib/structutil.h"
#include "lib/definicoes.h"
#include "lib/fileutil.h"

void imprime_bem_vindo_cadastro_porcao_alimento();
void cadastrar_nova_porcao_de_alimento();
void main_cadastro_porcao_alimento(char* codigo_perfil);

void main_cadastro_porcao_alimento(char* codigo_perfil){
	setlocale(LC_ALL, "Portuguese");
	imprime_bem_vindo_cadastro_porcao_alimento();
	int opcao = -1;
	do{
		if(strcmp(codigo_perfil, "N") == 0)
			printf("Entre com 1 para opção Cadastrar Nova Porção de alimento.\n");
		printf("Entre com 2 para opção Visualizar as Porções de alimento cadastradas.\n");
		printf("Entre com 3 para opção Pesquisar Proção de alimento.\n");
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
				imprime_bem_vindo_cadastro_porcao_alimento();
				break;
			case 3:
				imprime_bem_vindo_cadastro_porcao_alimento();
				break;
			default:
				printf("Opção Inválida!\n");
				system("pause");
				system("cls");
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
	char arquivo[100];
	char* texto;
	
	/* Função que carrega o maior código de um arquivo */
	int max_codigo_porcao_alimento = retorna_last_id_file(CAMIMNHO_ARQUIVO_PORCAO_ALIMENTO);
	max_codigo_porcao_alimento++;
	printf("\nmax_codigo_porcao_alimento:%d\n", max_codigo_porcao_alimento);
	
	/* Declaramos um ponteiro(link para o endereço da memória) para o arquivo de nome: 'pFile'*/
	FILE * pFile;
	
	/*  Os dados serão adicionados no fim do arquivo ("append"), 
		se ele já existir, ou um novo arquivo será criado, no caso de arquivo não */
	pFile = fopen(CAMIMNHO_ARQUIVO_PORCAO_ALIMENTO , "a");
	
	/* Se o arquivo for não-vazio */
	if(pFile!=NULL){
		
		struct PorcaoAlimento porcaoAlimento = carrega_porcao_alimento_input();
		porcaoAlimento.codigo_porcao_alimento = max_codigo_porcao_alimento;
		texto = monta_csv_texto_porcao_alimento(porcaoAlimento);
		
		/*Escreve uma string(da variável 'texto') num arquivo. */
		fputs(texto, pFile);
		
		/* Quando acabamos de usar um arquivo que abrimos, devemos fechá-lo. Para tanto usa-se a função fclose() */
		fclose(pFile);
	}
}

int main(){
	main_cadastro_porcao_alimento("N");
}

