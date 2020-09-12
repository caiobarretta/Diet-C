#include <stdio.h>
#include <string.h>

#ifndef _REFEICOESUTIL_H
#define _REFEICOESUTIL_H

char* carrega_refeicoes_input();
char* convert_inteiro_em_refeicao(int dia_semana);
char* carrega_refeicoes_pelo_vetor(int vetor_refeicoes[6]);

//Cafe da manha|Brunch|Almoco|Lanche|Jantar|Sobremesa|Ceia|
char* carrega_refeicoes_input(){
	
	int vetor_refeicoes[6];
	memset(vetor_refeicoes, 0, sizeof(int)*7);
	setlocale(LC_ALL, "Portuguese");
	
	char* refeicoes_escolhidas;
	
	int opcao = -1;
	do{
		//Cafe da manha|Brunch|Almoco|Lanche|Jantar|Sobremesa|Ceia|
		refeicoes_escolhidas = carrega_refeicoes_pelo_vetor(vetor_refeicoes);
		printf("Dias da semanas escolhidos:%s.\n", refeicoes_escolhidas);
		printf("Entre com 1 para adicionar/remover Cafe da manha.\n");
		printf("Entre com 2 para adicionar/remover Brunch.\n");
		printf("Entre com 3 para adicionar/remover Almoco.\n");
		printf("Entre com 4 para adicionar/remover Jantar.\n");
		printf("Entre com 5 para adicionar/remover Sobremesa.\n");
		printf("Entre com 6 para adicionar/remover Ceia.\n");
		printf("Ou entre com 0 para voltar: ");
		scanf("%d", &opcao);
		system("cls");
		if(opcao >= 1 && opcao <= 6){
			if(vetor_refeicoes[opcao-1] == 0)
				vetor_refeicoes[opcao-1] = 1;
			else
				vetor_refeicoes[opcao-1] = 0;
		}
		else{
			if(opcao != 0){
				printf("Opção Inválida!\n");
				system("pause");
				system("cls");
			}
		}
	}while(opcao != 0);
	printf("Retornando......\n");
	system("pause");
	system("cls");
	return refeicoes_escolhidas;
}

char* convert_inteiro_em_refeicao(int dia_semana){
	//Cafe da manha|Brunch|Almoco|Lanche|Jantar|Sobremesa|Ceia|
	char* nome_dia_semana = (char*)malloc(sizeof(char)*4);
	switch(dia_semana){
		case 1:
			nome_dia_semana = "Cafe da manha|";
			break;
		case 2:
			nome_dia_semana = "Brunch|";
			break;
		case 3:
			nome_dia_semana = "Lanche|";
			break;
		case 4:
			nome_dia_semana = "Jantar|";
			break;
		case 5:
			nome_dia_semana = "Sobremesa|";
			break;
		case 6:
			nome_dia_semana = "Ceia|";
			break;
		default:
			printf("Opção Inválida!\n");
	}
}

char* carrega_refeicoes_pelo_vetor(int vetor_refeicoes[6]){
	int i =0, len_refeicoes=0;
	for(i=0; i<6; i++){
		if(vetor_refeicoes[i] == 1){
			char* refeicao = convert_inteiro_em_refeicao(i+1);
			len_refeicoes += strlen(refeicao);
		}
	}
	
	char* semanas_selecionadas = (char*)malloc(sizeof(char)*len_refeicoes);
	memset(semanas_selecionadas, 0, sizeof(char)*len_refeicoes);
	for(i=0; i<6; i++){
		if(vetor_refeicoes[i] == 1){
			char* nome_refeicao = convert_inteiro_em_refeicao(i+1);
			strcat(semanas_selecionadas, nome_refeicao);
		}
	}
	return semanas_selecionadas;
}

#endif /* _REFEICOESUTIL_H */
