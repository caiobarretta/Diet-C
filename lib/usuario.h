#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include "strutil.h"
#include "structutil.h"
#include "definicoes.h"

#ifndef _USUARIO_H
#define _USUARIO_H

int valida_login(struct Login login);
char* get_password(char *display_message);
int autenticacao_usuario(char* codigo_perfil);

int autenticacao_usuario(char* codigo_perfil){
	int usuario_senha_valida = 0, tentativas = 0;
	do{
		char usuario[TAMANHO_MAXIMO_CARACTERES_USUARIO];
		//char senha[TAMANHO_MAXIMO_CARACTERES_SENHA];
		
		struct Login login;
		printf("Entre com seu usuário:");
		setbuf(stdin, NULL);
		fgets(usuario, TAMANHO_MAXIMO_CARACTERES_USUARIO, stdin);
	  	char* usuario_normalizado = str_normalize_escape_char(usuario);
	  	
		//Validar gambiarra com a professora
		char* senha = get_password("Entre com sua senha:");
		char* senha_copia = (char*)malloc(strlen(senha)*sizeof(char));
		strcpy(senha_copia, senha);
		
		//printf("Entre com sua senha:");
		//setbuf(stdin, NULL);
		//fgets(senha, TAMANHO_MAXIMO_CARACTERES_USUARIO, stdin);
		//char* senha_normalizada = str_normalize_escape_char(senha);
		
		login.codigo_perfil = codigo_perfil;
		login.usuario = usuario_normalizado;
		login.senha = senha_copia;
		//login.senha = senha_normalizada;
		usuario_senha_valida = valida_login(login);
		login.codigo_usuario = usuario_senha_valida;
		
		if(usuario_senha_valida > 0)
			printf("\nUsuário autenticado com sucesso!\n");
		else
			printf("\nSenha ou Usuário inválidos!\n");
		system("pause");
		system("cls");
		tentativas++;
		
	}while(usuario_senha_valida <= 0 && tentativas <3);
	return usuario_senha_valida;
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
	  	char* codigo_perfil_normalizado = str_normalize_escape_char(codigo_perfil);
		if (strcmp(usuario, login.usuario) == 0 && strcmp(senha, login.senha) == 0 && 
		  	strcmp(codigo_perfil_normalizado, login.codigo_perfil) == 0){
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
    return entrada;
}

#endif /* _USUARIO_H */
