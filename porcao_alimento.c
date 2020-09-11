#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include "lib/strutil.h"

typedef enum {dom=1,seg=2,ter=3,qua=4,qui=5,sex=6,sab=7} DiasDaSemana;

//C�digo,Descri��o,DiasDaSemana,Refei��o
struct PorcaoAlimento{
	int codigo_porcao_alimento;
	char* descricao;
	int dia_da_semana[7];
};

void imprime_bem_vindo_cadastro_porcao_alimento();

void cadastrar_nova_porcao_de_alimento();

struct PorcaoAlimento carrega_porcao_alimento_input();

char* monta_csv_texto_porcao_alimento(struct PorcaoAlimento porcaoAlimento);

#define CAMIMNHO_ARQUIVO_PORCAO_ALIMENTO "db\\PorcaoAlimento.txt"

void main_cadastro_porcao_alimento(char* codigo_perfil){
	setlocale(LC_ALL, "Portuguese");
	imprime_bem_vindo_cadastro_porcao_alimento();
	int opcao = -1;
	do{
		if(strcmp(codigo_perfil, "N") == 0)
			printf("Entre com 1 para op��o Cadastrar Nova Por��o de alimento.\n");
		printf("Entre com 2 para op��o Visualizar as Por��es de alimento cadastradas.\n");
		printf("Entre com 3 para op��o Pesquisar Pro��o de alimento.\n");
		printf("Ou entre com 0 para voltar: ");
		scanf("%d", &opcao);
		system("cls");
		switch(opcao){
			case 0:
				break;
			case 1:
				if(strcmp(codigo_perfil, "N") == 0){
					printf("Cadastro Nova Por��o de alimento\n");
					cadastrar_nova_porcao_de_alimento();
				}
				else{
					printf("Voc� n�o tem permiss�o de acesso!\n");
					printf("Op��o Inv�lida!\n");
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
				printf("Op��o Inv�lida!\n");
		}
	}while(opcao != 0);
	printf("Retornando......\n");
	system("pause");
	system("cls");
}

void imprime_bem_vindo_cadastro_porcao_alimento(){
	printf("===============================================================\n");
	printf("==================== BEM-VINDO AO CADASTRO  ===================\n");
	printf("=============== DE POR��O DE ALIMENTO DO DIET-C ===============\n");
	printf("===============================================================\n");
}

void cadastrar_nova_porcao_de_alimento(){
	char arquivo[100];
	char* texto;
	
	/* Declaramos um ponteiro(link para o endere�o da mem�ria) para o arquivo de nome: 'pFile'*/
	FILE * pFile;
	
	/*  Os dados ser�o adicionados no fim do arquivo ("append"), 
		se ele j� existir, ou um novo arquivo ser� criado, no caso de arquivo n�o */
	pFile = fopen(CAMIMNHO_ARQUIVO_PORCAO_ALIMENTO , "a");
	
	/* Se o arquivo for n�o-vazio */
	if(pFile!=NULL){
		
		struct PorcaoAlimento porcaoAlimento = carrega_porcao_alimento_input();
		
		texto = monta_csv_texto_porcao_alimento(porcaoAlimento);
		
		/*Escreve uma string(da vari�vel 'texto') num arquivo. */
		fputs(texto, pFile);
		
		/* Quando acabamos de usar um arquivo que abrimos, devemos fech�-lo. Para tanto usa-se a fun��o fclose() */
		fclose(pFile);
		}
}

struct PorcaoAlimento carrega_porcao_alimento_input(){
	struct PorcaoAlimento porcaoAlimento;
	porcaoAlimento.codigo_porcao_alimento = 1000;
	//porcaoAlimento.descricao = (char*)malloc(sizeof(char)*100);
	porcaoAlimento.descricao = "Teste Descricao";
	porcaoAlimento.dia_da_semana[0] = 1; 
	porcaoAlimento.dia_da_semana[1] = 2; 
	porcaoAlimento.dia_da_semana[2] = 3; 
	porcaoAlimento.dia_da_semana[3] = 4; 
	porcaoAlimento.dia_da_semana[4] = 5; 
	porcaoAlimento.dia_da_semana[5] = 6;
	return porcaoAlimento;
}

char* monta_csv_texto_porcao_alimento(struct PorcaoAlimento porcaoAlimento){
	int i = 0;
	int const quantidade_de_virgulas = 2;
	
	int len = len_porcao_alimento(porcaoAlimento);
	for(i = 0; i<quantidade_de_virgulas; i++)
		len += strlen(",");
		
	len += strlen("\n");
	
	char* texto = (char*)malloc(sizeof(char)*len);
	memset(texto, 0, sizeof(char)*len);//Limpa lixo de mem�ria
	
	char codigo_porcao_alimento[100];
	convert_int_to_string(porcaoAlimento.codigo_porcao_alimento, codigo_porcao_alimento);
	
	strcat(texto, codigo_porcao_alimento);
	strcat(texto, ",");
	
	strcat(texto, porcaoAlimento.descricao);
	strcat(texto, ",");
	
	int len_dia_da_semana = sizeof(porcaoAlimento.dia_da_semana)/sizeof(int);
	for(i=0; i<=len_dia_da_semana; i++){
		char dia_da_semana[100]; 
		convert_int_to_string(porcaoAlimento.dia_da_semana[i], dia_da_semana);
		strcat(texto, dia_da_semana);
		strcat(texto, "|");
	}
	
	strcat(texto, "\n");
	
	return texto;
}

int len_porcao_alimento(struct PorcaoAlimento porcaoAlimento){
	int len = 0;
	int i = 0;
	
	char codigo_porcao_alimento[100];
	convert_int_to_string(porcaoAlimento.codigo_porcao_alimento, codigo_porcao_alimento);
	
	len += strlen(codigo_porcao_alimento);
	len += strlen(porcaoAlimento.descricao);
	
	int len_dia_da_semana = sizeof(porcaoAlimento.dia_da_semana)/sizeof(int);
	for(i=0; i<=len_dia_da_semana; i++){
		char dia_da_semana[100]; 
		convert_int_to_string(porcaoAlimento.dia_da_semana[i], dia_da_semana);
		len += strlen(dia_da_semana);
		len += strlen("|");
	}
	
	return len;
}


int main(){
	main_cadastro_porcao_alimento("N");
}
