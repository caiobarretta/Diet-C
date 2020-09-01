#include <stdio.h>
#include <locale.h>

void imprime_bem_vindo_perfil_nutricionista();

int main_perfil_nutricionista(){
	setlocale(LC_ALL, "Portuguese");
	imprime_bem_vindo_perfil_nutricionista();
	return 0;
}

void imprime_bem_vindo_perfil_nutricionista(){
	printf("===============================================================\n");
	printf("===================== BEM-VINDO AO DIET-C  ====================\n");
	printf("===================== PERFIL NUTRICIONISTA ====================\n");
	printf("===============================================================\n");
}
