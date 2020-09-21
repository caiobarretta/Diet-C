#include <stdio.h>
#include <stdlib.h>


void imprime_conversao(char* str, int valor){
	printf("A String %s foi convertida em %d\n", str, valor);
}

int main(){
	
	int valor = 0;
	
	char* um = "1";
	valor = atoi(um);
	imprime_conversao(um, valor);
	
	char dois[2];
	dois[0] = '2';
	dois[1] = '\0';
	valor = atoi(dois);
	imprime_conversao(dois, valor);
}
