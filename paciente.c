#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include "lib/strutil.h"
#include "lib/paciente.h"
#include "lib/structutil.h"
#include "lib/definicoes.h"
#include "lib/fileutil.h"
#include "lib/pesquisa.h"

#ifndef _PACIENTE_C
#define _PACIENTE_C

void imprime_bem_vindo_cadastro_paciente();

void cadastrar_novo_paciente();

void main_cadastro_paciente(char* codigo_perfil);

void imprime_pacientes_cadastradas();

void pesquisar_paciente();

void main_cadastro_paciente(char* codigo_perfil){
	setlocale(LC_ALL, "Portuguese");
	imprime_bem_vindo_cadastro_paciente();
	int opcao = -1;
	do{
		if(strcmp(codigo_perfil, "N") == 0)
			printf("Entre com 1 para opção Cadastrar Novo Paciente.\n");
		printf("Entre com 2 para opção Visualizar as Pacientes cadastradas.\n");
		printf("Entre com 3 para opção Pesquisar Pacientes.\n");
		printf("Ou entre com 0 para voltar: ");
		scanf("%d", &opcao);
		system("cls");
		switch(opcao){
			case 0:
				break;
			case 1:
				if(strcmp(codigo_perfil, "N") == 0){
					printf("Cadastro Novo Paciente\n");
					cadastrar_novo_paciente();
				}
				else{
					printf("Você não tem permissão de acesso!\n");
					printf("Opção Inválida!\n");
					system("pause");
					system("cls");
				}
				imprime_bem_vindo_cadastro_paciente();
				break;
			case 2:
				imprime_pacientes_cadastradas();
				imprime_bem_vindo_cadastro_paciente();
				break;
			case 3:
				pesquisar_paciente();
				imprime_bem_vindo_cadastro_paciente();
				break;
			default:
				printf("Opção Inválida!\n");
				system("pause");
				system("cls");
				imprime_bem_vindo_cadastro_paciente();
				break;
		}
	}while(opcao != 0);
	printf("Retornando......\n");
	system("pause");
	system("cls");
}

void imprime_bem_vindo_cadastro_paciente(){
	printf("===============================================================\n");
	printf("==================== BEM-VINDO AO CADASTRO  ===================\n");
	printf("===================== DE PACIENTES DO DIET-C =====================\n");
	printf("===============================================================\n");
}

void cadastrar_novo_paciente(){
	/* Função que carrega o maior código de um arquivo */
	int max_codigo_paciente = retorna_last_id_file(CAMIMNHO_ARQUIVO_PACIENTE);
	max_codigo_paciente++;
	
	char* texto;
	struct Paciente paciente = carrega_paciente_input();
	paciente.codigo_paciente = max_codigo_paciente;
	texto = monta_csv_texto_paciente(paciente);
	char* mensagem_erro = "Ocorreu um erro ao salvar dados da paciente.";
	
	salvar_conteudo_em_arquivo(CAMIMNHO_ARQUIVO_PACIENTE, texto, mensagem_erro);
	
	int max_codigo_login = retorna_last_id_file(CAMIMNHO_ARQUIVO_USUARIO);
	max_codigo_login++;
	char* mensagem_erro_login = "Ocorreu um erro ao salvar dados do login do paciente.";
	char* texto_login;
	paciente.login.codigo_usuario = max_codigo_login;
	texto_login = monta_csv_texto_login(paciente.login);
	
	salvar_conteudo_em_arquivo(CAMIMNHO_ARQUIVO_USUARIO, texto_login, mensagem_erro_login);
}

void imprime_pacientes_cadastradas(){
	char* mensagem_erro = "Não existem dados de pacientes ou ocorreu algum erro na solicitação de leitura.";
	char* cabecalho_tabela = monta_cabecalho_tabela_paciente();
	imprime_conteudo_de_arquivo_em_formato_de_tabela(CAMIMNHO_ARQUIVO_PACIENTE, mensagem_erro, cabecalho_tabela);
}

void pesquisar_paciente(){
	char* mensagem_erro = "Não existem dados de pacientes ou ocorreu algum erro na solicitação de leitura.";
	monta_pesquisa_paciente(mensagem_erro);
}

#endif /* _PACIENTE_C */
