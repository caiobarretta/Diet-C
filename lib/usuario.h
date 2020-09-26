#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include "strutil.h"
#include "structutil.h"
#include "definicoes.h"
#include "getvaluesutil.h"

#ifndef _USUARIO_H
#define _USUARIO_H

int valida_login(struct Login login);

char* get_password(char *display_message);

int autenticacao_usuario(char* codigo_perfil);

char* retorna_usuario_login_input();

char* retorna_senha_login_input();

struct Login carrega_login_input();

char* monta_csv_texto_login(struct Login login);

int len_login(struct Login login);

int autenticacao_usuario(char* codigo_perfil){
	int codigo_usuario = 0, tentativas = 0;
	do{
		char usuario[TAMANHO_MAXIMO_CARACTERES_USUARIO];
		
		struct Login login;
		printf("Entre com seu usuário:");
		setbuf(stdin, NULL);
		fgets(usuario, TAMANHO_MAXIMO_CARACTERES_USUARIO, stdin);
	  	char* usuario_normalizado = str_normalize_escape_char(usuario);
	  	
		char* senha = get_password("Entre com sua senha:");
		char* senha_aux = (char*)malloc(strlen(senha)*sizeof(char));
		strcpy(senha_aux, senha);
				
		login.codigo_perfil = (char*)malloc(strlen(codigo_perfil)*sizeof(char));
		strcpy(login.codigo_perfil, codigo_perfil);
		
		login.usuario = (char*)malloc(strlen(usuario_normalizado)*sizeof(char));
		strcpy(login.usuario, usuario_normalizado);
		
		login.senha = (char*)malloc(strlen(senha_aux)*sizeof(char));
		strcpy(login.senha, senha_aux);
		
		codigo_usuario = valida_login(login);
		login.codigo_usuario = codigo_usuario;
		
		if(codigo_usuario > 0)
			printf("\nUsuário autenticado com sucesso!\n");
		else
			printf("\nSenha ou Usuário inválidos!\n");
		system("pause");
		system("cls");
		tentativas++;
		
	}while(codigo_usuario <= 0 && tentativas <3);
	return codigo_usuario;
}

int valida_login(struct Login login){
	FILE *arq = NULL;
	char row[TAMANHO_MAXIMO_CARACTERES_LINHA] = {0}, *result = {0};
	
	// Abre um arquivo TEXTO para LEITURA
	arq = fopen(CAMIMNHO_ARQUIVO_USUARIO, "rt");
	if (arq == NULL){  // Se houve erro na abertura
	 printf("Problemas na abertura do arquivo de usuário e senha.\n");
	 return 0;
	}
	while (!feof(arq)){
	  // Lê uma linha (inclusive com o '\n')
	  result = fgets(row, TAMANHO_MAXIMO_CARACTERES_LINHA, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
	  if (result){  // Se foi possível ler
	  	char* codigo_usuario = split_char_position(row, CARACTER_SEPARACAO, 0);
	  	char* usuario = split_char_position(row, CARACTER_SEPARACAO, 1);
	  	char* senha = split_char_position(row, CARACTER_SEPARACAO, 2);
	  	char* codigo_perfil = split_char_position(row, CARACTER_SEPARACAO, 3);
	  	
		if (strcmp(usuario, login.usuario) == 0 && strcmp(senha, login.senha) == 0 && 
		  	strcmp(codigo_perfil, login.codigo_perfil) == 0){
		  	return atoi(codigo_usuario);
	  	}
	  }
	}
	fclose(arq);
	return 0;
}

char* get_password(char *display_message){
    char entrada[256] = {0};
    char c = '\0';
    int pos = 0;
    
    printf("%s", display_message);
    do {
        c = getch();
        
        if(isprint(c)) 
        {
            entrada[pos++] = c;
            printf("%c", CARACTER_MASCARA_SENHA);
        }
        else if(c==8&&pos)
        {
            entrada[pos--] = '\0';
            printf("%s", "\b \b");
        }
    } while( c!= 13);
    printf("\n");
    return entrada;
}

char* retorna_usuario_login_input(){
	return retorna_padrao_input_normalized_escape_char("Usuário", "Entre com o usuário do paciente");
}

char* retorna_senha_login_input(){
	return retorna_padrao_input_normalized_escape_char("Senha", "Entre com a senha do paciente");
}

struct Login carrega_login_input(){
	struct Login login;
	login.usuario = retorna_usuario_login_input();
	login.senha = retorna_senha_login_input();
	login.codigo_perfil = CODIGO_PERFIL_PACIENTE;
	return login;
}

char* monta_csv_texto_login(struct Login login){
	int i = 0;
	int const quantidade_de_virgulas = 3;
	
	char* CADEIA_CARACTER_SEPARACAO = (char*)malloc(sizeof(char));
	memset(CADEIA_CARACTER_SEPARACAO, 0, sizeof(char));
	CADEIA_CARACTER_SEPARACAO[0] = CARACTER_SEPARACAO;
	
	int len = len_login(login);
	for(i = 0; i<quantidade_de_virgulas; i++)
		len += strlen(CADEIA_CARACTER_SEPARACAO);
		
	len += strlen(CARACTER_FINAL_DE_LINHA);
	
	char* texto = (char*)malloc(sizeof(char)*len);
	memset(texto, 0, sizeof(char)*len);
	
	char codigo_login[TAMANHO_MAXIMO_CARACTERES_CODIGO];
	memset(codigo_login, 0, TAMANHO_MAXIMO_CARACTERES_CODIGO);
	convert_int_to_string(login.codigo_usuario, codigo_login);
	
	strcat(texto, codigo_login);
	strcat(texto, CADEIA_CARACTER_SEPARACAO);
	
	strcat(texto, login.usuario);
	strcat(texto, CADEIA_CARACTER_SEPARACAO);
	
	strcat(texto, login.senha);
	strcat(texto, CADEIA_CARACTER_SEPARACAO);
	
	strcat(texto, login.codigo_perfil);
	
	strcat(texto, CARACTER_FINAL_DE_LINHA);
	
	return texto;
}

int len_login(struct Login login){
	int len = 0;
	int i = 0;
	
	char codigo_usuario[100];
	convert_int_to_string(login.codigo_usuario, codigo_usuario);
	
	len += strlen(codigo_usuario);
	len += strlen(login.usuario);
	len += strlen(login.senha);
	len += strlen(login.codigo_perfil);
	
	return len;
}

#endif /* _USUARIO_H */
