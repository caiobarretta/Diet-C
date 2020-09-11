#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

char **split_char(const char* frase, const char separador);
void replace_char(char* text_dest, const char* text_source, const char old_char, const char new_char);
void remove_char(char* text_dest, const char* text_source, const char old_char);
char* str_normalize_escape_char(const char* text_source);
char* convert_int_to_string(int value, char* str);


char **split_char(const char* frase, const char separador){
    int i, j, k, contsep = 0;

     for(i=0,contsep=0;i<strlen(frase);i++)
       if(frase[i] == separador)
          contsep++;

    char  aux[contsep][20];
    char **result = (char**)malloc(contsep*sizeof(char));
    
    if(contsep)
    {
        for(i=0; i<=contsep; i++ )
          *(result + i) = (char*)malloc(40*sizeof(char));
        
        for(i=0,k=0,j=0; i < strlen(frase); i++)
           if(frase[i] != separador)
           {
              aux[k][j] = frase[i];
              j++;
           }
           else
           {
              aux[k][j] = 0;
              k++;
              j=0;
           }
        aux[k][j] = 0;
        
        for(i=0;i<=contsep;i++)
          *(result+i) = strcpy(*(result+i), aux[i]);
        
        return result;
    }
    else{
    	printf("Nenhum Separador Encontrado");
    	free(result);
	}
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
