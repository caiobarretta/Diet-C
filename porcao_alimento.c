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
			printf("Entre com 1 para op��o Cadastrar Nova Por��o de alimento.\n");
		printf("Entre com 2 para op��o Visualizar as Por��es de alimento cadastradas.\n");
		printf("Entre com 3 para op��o Pesquisar Pro��o de alimento.\n");
		printf("Ou entre com 0 para voltar: ");
		scanf("%d", &opcao);
		system("cls");
		switch(opcao){
			case 0:
				break;
			case 1:
				if(strcmp(codigo_perfil, "N") == 0){
					printf("Cadastro Nova Por��o de alimento\n");
					cadastrar_nova_porcao_de_alimento();
				}
				else{
					printf("Voc� n�o tem permiss�o de acesso!\n");
					printf("Op��o Inv�lida!\n");
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
				printf("Op��o Inv�lida!\n");
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
	printf("=============== DE POR��O DE ALIMENTO DO DIET-C ===============\n");
	printf("===============================================================\n");
}

void cadastrar_nova_porcao_de_alimento(){
	char arquivo[100];
	char* texto;
	
	/* Fun��o que carrega o maior c�digo de um arquivo */
	int max_codigo_porcao_alimento = retorna_last_id_file(CAMIMNHO_ARQUIVO_PORCAO_ALIMENTO);
	max_codigo_porcao_alimento++;
	printf("\nmax_codigo_porcao_alimento:%d\n", max_codigo_porcao_alimento);
	
	/* Declaramos um ponteiro(link para o endere�o da mem�ria) para o arquivo de nome: 'pFile'*/
	FILE * pFile;
	
	/*  Os dados ser�o adicionados no fim do arquivo ("append"), 
		se ele j� existir, ou um novo arquivo ser� criado, no caso de arquivo n�o */
	pFile = fopen(CAMIMNHO_ARQUIVO_PORCAO_ALIMENTO , "a");
	
	/* Se o arquivo for n�o-vazio */
	if(pFile!=NULL){
		
		struct PorcaoAlimento porcaoAlimento = carrega_porcao_alimento_input();
		porcaoAlimento.codigo_porcao_alimento = max_codigo_porcao_alimento;
		texto = monta_csv_texto_porcao_alimento(porcaoAlimento);
		
		/*Escreve uma string(da vari�vel 'texto') num arquivo. */
		fputs(texto, pFile);
		
		/* Quando acabamos de usar um arquivo que abrimos, devemos fech�-lo. Para tanto usa-se a fun��o fclose() */
		fclose(pFile);
	}
}

int main(){
	main_cadastro_porcao_alimento("N");
}

