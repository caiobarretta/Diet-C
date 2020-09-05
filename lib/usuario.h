#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "strutil.h"

int valida_usuario_senha(char* usuario, char* senha, char* codigo_perfil);
char* get_password(char *display_message);
int autenticacao_usuario(char* codigo_perfil);

#define CARACTER_MASCARA_SENHA '*'
#define TAMANHO_MAXIMO_CARACTERES_LINHA 100
#define TAMANHO_MAXIMO_CARACTERES_USUARIO 100

int autenticacao_usuario(char* codigo_perfil){
	int usuario_senha_valida = 0, tentativas = 0;
	do{
		char usuario[TAMANHO_MAXIMO_CARACTERES_USUARIO];
		printf("Entre com seu usuário:");
		setbuf(stdin, NULL);
		fgets(usuario, TAMANHO_MAXIMO_CARACTERES_USUARIO, stdin);
		
	  	char* usuario_normalizado = str_normalize_escape_char(usuario);
	  	
		//Validar gambiarra com a professora
		char* senha = get_password("Entre com sua senha:");
		char* senha_copia = (char*)malloc(strlen(senha)*sizeof(char));
		strcpy(senha_copia, senha);
		
		usuario_senha_valida = valida_usuario_senha(usuario_normalizado, senha_copia, codigo_perfil);
		
		if(usuario_senha_valida == 1)
			printf("\nUsuário autenticado com sucesso!\n");
		else
			printf("\nSenha ou Usuário inválidos!\n");
		system("pause");
		system("cls");
		tentativas++;
		
	}while(usuario_senha_valida != 1 && tentativas <3);
	return usuario_senha_valida;
}


int valida_usuario_senha(char* usuario, char* senha, char* codigo_perfil){
	FILE *arq = NULL;
	char row[TAMANHO_MAXIMO_CARACTERES_LINHA] = {0}, *result = {0};
	
	// Abre um arquivo TEXTO para LEITURA
	arq = fopen("db\\Usuarios.txt", "rt");
	if (arq == NULL){  // Se houve erro na abertura
	 printf("Problemas na abertura do arquivo de usuário e senha.\n");
	 return 0;
	}
	while (!feof(arq)){
	  // Lê uma linha (inclusive com o '\n')
	  result = fgets(row, TAMANHO_MAXIMO_CARACTERES_LINHA, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
	  if (result){  // Se foi possível ler
	  
	  	char **col= split_char(row,',');
	  	
	  	char* codigo_perfil_normalizado = str_normalize_escape_char(col[2]);
	  	
	  	if (strcmp(col[0], usuario) == 0 && strcmp(col[1], senha) == 0 && strcmp(codigo_perfil_normalizado, codigo_perfil) == 0){
	  		return 1;
	  	}
	  }
	}
	fclose(arq);
	return 0;
}

char* get_password(char *display_message){
    char buffer[256] = {0};
    char c = '\0';
    int pos = 0;
    
    printf("%s", display_message);
    do {
        c = getch();
        
        if(isprint(c)) 
        {
            buffer[pos++] = c;
            printf("%c", CARACTER_MASCARA_SENHA);
        }
        else if(c==8&&pos)
        {
            buffer[pos--] = '\0';
            printf("%s", "\b \b");
        }
    } while( c!= 13);
    return buffer;
}
