#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

#define CODIGO_PERFIL_PACIENTE "P"

void imprime_bem_vindo_perfil_paciente();

void main_perfil_paciente(){
	setlocale(LC_ALL, "Portuguese");
	imprime_bem_vindo_perfil_paciente();
	int usuario_senha_valida = autenticacao_usuario(CODIGO_PERFIL_PACIENTE);
	printf("\nusuario_senha_valida:%d\n",usuario_senha_valida);
	if(usuario_senha_valida >= 1)
	{
		int opcao = -1;
		do{
			printf("Entre com 1 para opção Cadastro Porção de alimento.\n");
			printf("Entre com 2 para opção Cadastro Dieta (Com base na porção de alimento).\n");
			printf("Ou entre com 0 para voltar: ");
			scanf("%d", &opcao);
			system("cls");
			switch(opcao){
				case 0:
					break;
				case 1:
					//main_cadastro_porcao_alimento(CODIGO_PERFIL_PACIENTE);
					break;
				case 2:
					main_cadastro_dieta(CODIGO_PERFIL_PACIENTE);
					break;
				default:
					printf("Opção Inválida!\n");
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
