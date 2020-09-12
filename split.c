#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


char* split_char_position(const char* frase, const char separador, const int position);

int main(){
	
	char* frase = "1,Caio,1234,N,1234567bkjhdbcajdh,cdhcajdchd,cahdcadjcha,casdjkckajsbdjasd,jihcbajkdbcjhbd,caijdcadj";
	char separador = ',';
	
	char* trecho = split_char_position(frase, separador, 1);
	printf("trecho:%s\n", trecho);
	
	trecho = split_char_position(frase, separador, 0);
	printf("trecho:%s\n", trecho);
}

char* split_char_position(const char* frase, const char separador, const int posicao){
	int i = 0, qtd_separador = 0, contador_trecho_frase = 0, index_inicio = 0, index_fim = 0;
	char* trecho_frase;
	for(i=0; i<strlen(frase); i++){
		char caracter = frase[i];
		if(separador == caracter)
			qtd_separador++;
		if(qtd_separador == posicao && frase[i] != separador){
			if(index_inicio == 0) 
				index_inicio = i;
			index_fim = i;
			contador_trecho_frase++;
		}
	}
	trecho_frase = (char*)malloc(sizeof(char)*contador_trecho_frase);
	memset(trecho_frase, 0, sizeof(char)*contador_trecho_frase);
	
	contador_trecho_frase = 0;
	for(i=index_inicio; i<=index_fim; i++){
		trecho_frase[contador_trecho_frase] = frase[i];
		contador_trecho_frase++;
	}
	return trecho_frase;
}

