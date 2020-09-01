#include <stdio.h>
#include <locale.h>
#include "perfil_nutricionista.c"
#include "perfil_paciente.c"

void imprime_bem_vindo();
void perfil_nutricionista();
void perfil_paciente();

int main(){
	setlocale(LC_ALL, "Portuguese");
	imprime_bem_vindo();
	int opcao = -1;
	while(opcao != 0)
	{
		printf("Entre com 1 para perfil Nutricionista, 2 para perfil Paciente ou 0 para sair:");
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				perfil_nutricionista();
				break;
			case 2:
				perfil_paciente();
				break;
			default:
				system("cls");
				printf("Perfil Inválido!");
		}
	}
	
	printf("Finalizando o programa. . . . . .\n");
	return 0;
}

void imprime_bem_vindo(){
	printf("===============================================================\n");
	printf("===================== BEM-VINDO AO DIET-C =====================\n");
	printf("===============================================================\n");
}

void perfil_nutricionista(){
	system("cls");
	main_perfil_nutricionista();
}

void perfil_paciente(){
	system("cls");
	main_perfil_paciente();
}
