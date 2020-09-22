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
	int usuario_senha_valida = autenticacao_usuario(CODIGO_PERFIL_PACIENTE);
	if(usuario_senha_valida >= 1){
		imprime_bem_vindo_perfil_paciente();
		int opcao = -1;
		do{
			printf("Entre com 1 para opção Porção de alimento.\n");
			printf("Entre com 2 para opção Dieta (Com base na porção de alimento).\n");
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
					printf("Opção Inválida!\n");
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
