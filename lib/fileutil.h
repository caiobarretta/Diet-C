#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "definicoes.h"
#include "strutil.h"

#ifndef _FILEUTIL_H
#define _FILEUTIL_H

int retorna_last_id_file(const char* FILE_NAME);

int retorna_last_id_file(const char* FILE_NAME){
	FILE *arq = NULL;
	char row[TAMANHO_MAXIMO_CARACTERES_LINHA] = {0}, *result = {0};
	int max_id_file = INT_MIN;
	
	// Abre um arquivo TEXTO para LEITURA
	arq = fopen(FILE_NAME, "rt");
	if (arq == NULL){  // Se houve erro na abertura
	 return 0;
	}
	while (!feof(arq)){
	  // Lê uma linha (inclusive com o '\n')
	  result = fgets(row, TAMANHO_MAXIMO_CARACTERES_LINHA, arq);  // o 'fgets' lê até TAMANHO_MAXIMO_CARACTERES_LINHA caracteres ou até o '\n'
	  if (result){  // Se foi possível ler
		char* sub_string = split_char_position(row, CARACTER_SEPARACAO, 0);
	  	int id_int = atoi(sub_string);
	  	if(max_id_file < id_int){
	  		max_id_file = id_int;
		  }
	  }
	}
	fclose(arq);
	if(max_id_file == INT_MIN)
		return 0;
	return max_id_file;
}

#endif /* _FILEUTIL_H */
