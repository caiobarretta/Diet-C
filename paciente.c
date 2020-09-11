#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

void imprime_bem_vindo_cadastro_paciente();

void main_cadastro_paciente(char* codigo_perfil){
	setlocale(LC_ALL, "Portuguese");
	imprime_bem_vindo_cadastro_paciente();
	int opcao = -1;
	do{
		printf("Entre com 1 para opção Cadastrar Novo Paciente.\n");
		printf("Entre com 2 para opção Visualizar os Pacientes cadastrados.\n");
		printf("Entre com 3 para opção Pesquisar Pacientes.\n");
		printf("Ou entre com 0 para voltar: ");
		scanf("%d", &opcao);
		system("cls");
		switch(opcao){
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			default:
				printf("Opção Inválida!\n");
		}
	}while(opcao != 0);
	printf("Retornando......\n");
	system("pause");
	system("cls");
}

void imprime_bem_vindo_cadastro_paciente(){
	printf("===============================================================\n");
	printf("==================== BEM-VINDO AO CADASTRO  ===================\n");
	printf("===================== DE DIETAS DO DIET-C =====================\n");
	printf("===============================================================\n");
}
