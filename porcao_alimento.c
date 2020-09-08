#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

void imprime_bem_vindo_cadastro_porcao_alimento();

void main_cadastro_porcao_alimento(char* codigo_perfil){
	setlocale(LC_ALL, "Portuguese");
	imprime_bem_vindo_cadastro_porcao_alimento();
	int opcao = -1;
	do{
		if(strcmp(codigo_perfil, "N") == 0)
			printf("Entre com 1 para op��o Cadastrar Nova Por��o de alimento.\n");
		printf("Entre com 2 para op��o Visualizar as Por��es de alimento cadastradas.\n");
		printf("Entre com 3 para op��o Pesquisar Pro��o de alimento.\n");
		printf("Ou entre com 0 para sair: ");
		scanf("%d", &opcao);
		system("cls");
		switch(opcao){
			case 0:
				break;
			case 1:
				if(strcmp(codigo_perfil, "N") == 0){
					printf("Cadastro Nova Por��o de alimento\n");
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
