#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include "lib/usuario.h"
#include "lib/definicoes.h"
#include "porcao_alimento.c"
#include "dieta.c"

void imprime_bem_vindo_perfil_paciente();

void main_perfil_paciente(){
	setlocale(LC_ALL, "Portuguese");
	imprime_bem_vindo_perfil_paciente();
	int codigo_usuario = autenticacao_usuario(CODIGO_PERFIL_PACIENTE);
	if(codigo_usuario >= 1){
		imprime_bem_vindo_perfil_paciente();
		carrega_sugestao_dieta_paciente(codigo_usuario);
		int opcao = -1;
		do{
			printf("Entre com 1 para op��o Por��o de alimento.\n");
			printf("Entre com 2 para op��o Dieta (Com base na por��o de alimento).\n");
			printf("Ou entre com 0 para voltar: ");
			scanf("%d", &opcao);
			system("cls");
			switch(opcao){
				case 0:
					break;
				case 1:
					main_cadastro_porcao_alimento(CODIGO_PERFIL_PACIENTE);
					imprime_bem_vindo_perfil_paciente();
					break;
				case 2:
					main_cadastro_dieta(CODIGO_PERFIL_PACIENTE);
					imprime_bem_vindo_perfil_paciente();
					break;
				default:
					printf("Op��o Inv�lida!\n");
					system("pause");
					system("cls");
					imprime_bem_vindo_perfil_paciente();
					break;
			}
		}while(opcao != 0);
		printf("Retornando......\n");
		system("pause");
		system("cls");
	}
}

void imprime_bem_vindo_perfil_paciente(){
	printf("===============================================================\n");
	printf("===================== BEM-VINDO AO DIET-C  ====================\n");
	printf("===================== PERFIL PACIENTE =========================\n");
	printf("===============================================================\n");
}
