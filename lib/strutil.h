#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "definicoes.h"

#ifndef _STRUTIL_H
#define _STRUTIL_H

char* split_char_position(const char* frase, const char separador, const int position);
void replace_char(char* text_dest, const char* text_source, const char old_char, const char new_char);
void remove_char(char* text_dest, const char* text_source, const char old_char);
char* str_normalize_escape_char(const char* text_source);
char* convert_int_to_string(int value, char* str);

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

void replace_char(char* text_dest, const char* text_source, const char old_char, const char new_char){
	int i=0, tamanho=0;
	tamanho = strlen(text_source);
	for(i=0; i<tamanho-1; i++){
		if(text_source[i] == old_char)
			text_dest[i] = new_char;
		else
			text_dest[i] = text_source[i];
	}
}

void remove_char(char* text_dest, const char* text_source, const char old_char){
	int i=0, tamanho=0, count=0;
	tamanho = strlen(text_source);
	for(i=0; i<tamanho-1; i++){
		if(text_source[i] != old_char){
			text_dest[count] = text_source[i];
			count++;
		}
	}
}

char* str_normalize_escape_char(const char* text_source){
	char* text_source_normalize = (char*)malloc(strlen(text_source)*sizeof(char)); 
	remove_char(text_source_normalize, text_source, '\n');
	return text_source_normalize;
}

char* convert_int_to_string(int value, char* str){
    char temp;
    int i =0;
    while (value > 0) {
        int digito = value % 10;
        str[i] = digito + '0';
        value /= 10;
        i++;
    }
   i = 0;
   int j = strlen(str) - 1;
   while (i < j) {
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      i++;
      j--;
   }
    return str;
}

#endif /* _STRUTIL_H */
