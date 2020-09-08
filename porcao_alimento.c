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
			printf("Entre com 1 para opção Cadastrar Nova Porção de alimento.\n");
		printf("Entre com 2 para opção Visualizar as Porções de alimento cadastradas.\n");
		printf("Entre com 3 para opção Pesquisar Proção de alimento.\n");
		printf("Ou entre com 0 para sair: ");
		scanf("%d", &opcao);
		system("cls");
		switch(opcao){
			case 0:
				break;
			case 1:
				if(strcmp(codigo_perfil, "N") == 0){
					printf("Cadastro Nova Porção de alimento\n");
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
