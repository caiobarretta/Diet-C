#include <stdio.h>
#include <string.h>

#ifndef _DIASEMANAUTIL_H
#define _DIASEMANAUTIL_H

char* carrega_dias_da_semana_input();
char* convert_inteiro_em_dia_da_semana(int dia_semana);
char* carrega_dias_da_semana_pelo_vetor(int vetor_dias_da_semana[7]);

//dom|seg|ter|qua|qui|sex|sab|
char* carrega_dias_da_semana_input(){
	
	int vetor_dias_da_semana[7];
	memset(vetor_dias_da_semana, 0, sizeof(int)*7);
	setlocale(LC_ALL, "Portuguese");
	
	char* dias_da_semanas_escolhidos;
	
	int opcao = -1;
	do{
		dias_da_semanas_escolhidos = carrega_dias_da_semana_pelo_vetor(vetor_dias_da_semana);
		printf("Dias da semanas escolhidos:%s.\n", dias_da_semanas_escolhidos);
		printf("Entre com 1 para adicionar/remover domingo.\n");
		printf("Entre com 2 para adicionar/remover segunda-feira.\n");
		printf("Entre com 3 para adicionar/remover terça-feira.\n");
		printf("Entre com 4 para adicionar/remover quarta-feira.\n");
		printf("Entre com 5 para adicionar/remover quinta-feira.\n");
		printf("Entre com 6 para adicionar/remover sexta-feira.\n");
		printf("Entre com 7 para adicionar/remover sábado.\n");
		printf("Ou entre com 0 para voltar: ");
		scanf("%d", &opcao);
		system("cls");
		if(opcao >= 1 && opcao <= 7){
			if(vetor_dias_da_semana[opcao-1] == 0)
				vetor_dias_da_semana[opcao-1] = 1;
			else
				vetor_dias_da_semana[opcao-1] = 0;
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
	return dias_da_semanas_escolhidos;
}

char* convert_inteiro_em_dia_da_semana(int dia_semana){
	//dom|seg|ter|qua|qui|sex|sab|
	char* nome_dia_semana = (char*)malloc(sizeof(char)*4);
	switch(dia_semana){
		case 1:
			nome_dia_semana = "dom|";
			break;
		case 2:
			nome_dia_semana = "seg|";
			break;
		case 3:
			nome_dia_semana = "ter|";
			break;
		case 4:
			nome_dia_semana = "qua|";
			break;
		case 5:
			nome_dia_semana = "qui|";
			break;
		case 6:
			nome_dia_semana = "sex|";
			break;
		case 7:
			nome_dia_semana = "sab|";
			break;
		default:
			printf("Opção Inválida!\n");
	}
}

char* carrega_dias_da_semana_pelo_vetor(int vetor_dias_da_semana[7]){
	int i =0, count_dias=0;
	for(i=0; i<7; i++){
		if(vetor_dias_da_semana[i] == 1){
			count_dias++;
		}
	}
		
	char* semanas_selecionadas = (char*)malloc(sizeof(char)*4*count_dias);
	memset(semanas_selecionadas, 0, sizeof(char)*4*count_dias);
	for(i=0; i<7; i++){
		if(vetor_dias_da_semana[i] == 1){
			char* nome_dia_da_semana = convert_inteiro_em_dia_da_semana(i+1);
			strcat(semanas_selecionadas, nome_dia_da_semana);
		}
	}
	return semanas_selecionadas;
}

#endif /* _DIASEMANAUTIL_H */
