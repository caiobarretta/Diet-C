#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

void imprime_bem_vindo_perfil_nutricionista();

void main_perfil_nutricionista(){
	setlocale(LC_ALL, "Portuguese");
	imprime_bem_vindo_perfil_nutricionista();
	int usuario_senha_valida = autenticacao_usuario("N");
	if(usuario_senha_valida == 1)
	{
		int opcao = -1;
		do{
			printf("Entre com 1 para opção XPTO, 2 para opção XYZ ou 0 para sair: ");
			scanf("%d", &opcao);
			switch(opcao){
				case 0:
					break;
				case 1:
					break;
				case 2:
					break;
				default:
					system("cls");
					printf("Opção Inválida!");
			}
		}while(opcao != 0);
		printf("Retornando......\n");
		system("pause");
		system("cls");
	}
}

void imprime_bem_vindo_perfil_nutricionista(){
	printf("===============================================================\n");
	printf("===================== BEM-VINDO AO DIET-C  ====================\n");
	printf("===================== PERFIL NUTRICIONISTA ====================\n");
	printf("===============================================================\n");
}
