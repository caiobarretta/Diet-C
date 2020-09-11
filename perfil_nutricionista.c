#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include "porcao_alimento.c"
#include "dieta.c"
#include "paciente.c"
 
void imprime_bem_vindo_perfil_nutricionista();

#define CODIGO_PERFIL_NUTRICIONISTA "N"

void main_perfil_nutricionista(){
	setlocale(LC_ALL, "Portuguese");
	imprime_bem_vindo_perfil_nutricionista();
	int usuario_senha_valida = autenticacao_usuario(CODIGO_PERFIL_NUTRICIONISTA);
	if(usuario_senha_valida == 1)
	{
		int opcao = -1;
		do{
			printf("Entre com 1 para op��o Cadastro Por��o de alimento.\n");
			printf("Entre com 2 para op��o Cadastro Dieta (Com base na por��o de alimento).\n");
			printf("Entre com 3 para op��o Cadastro Paciente (Associa��o a sugest�o de Dieta).\n");
			printf("Ou entre com 0 para voltar: ");
			scanf("%d", &opcao);
			system("cls");
			switch(opcao){
				case 0:
					break;
				case 1:
					main_cadastro_porcao_alimento(CODIGO_PERFIL_NUTRICIONISTA);
					break;
				case 2:
					main_cadastro_dieta(CODIGO_PERFIL_NUTRICIONISTA);
					break;
				case 3:
					main_cadastro_paciente(CODIGO_PERFIL_NUTRICIONISTA);
					break;
				default:
					printf("Op��o Inv�lida!\n");
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
