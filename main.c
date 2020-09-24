#include <stdio.h>
#include <locale.h>
#include "perfil_nutricionista.c"
#include "perfil_paciente.c"
#include "lib/usuario.h"

void imprime_bem_vindo();

void perfil_nutricionista();

void perfil_paciente();

int main(){
	setlocale(LC_ALL, "Portuguese");
	imprime_bem_vindo();
	int opcao = -1;
	do{
		printf("Entre com 1 para perfil Nutricionista, 2 para perfil Paciente ou 0 para sair: ");
		scanf("%d", &opcao);
		system("cls");
		switch(opcao){
			case 0:
				break;
			case 1:
				system("color 2");
				main_perfil_nutricionista();
				imprime_bem_vindo();
				break;
			case 2:
				system("color 70");
				main_perfil_paciente();
				imprime_bem_vindo();
				break;
			default:
				system("cls");
				printf("Perfil Inválido!\n");
		}
	}while(opcao != 0);
	system("pause");
	printf("Finalizando o programa. . . . . .\n");
	return 0;
}

void imprime_bem_vindo(){
	system("color 7");
	printf("===============================================================\n");
	printf("===================== BEM-VINDO AO DIET-C =====================\n");
	printf("===============================================================\n");
}
