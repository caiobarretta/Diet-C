#include <stdio.h>
#include <locale.h>

void imprime_bem_vindo_perfil_paciente();

int main_perfil_paciente(){
	setlocale(LC_ALL, "Portuguese");
	imprime_bem_vindo_perfil_paciente();
	return 0;
}

void imprime_bem_vindo_perfil_paciente(){
	printf("===============================================================\n");
	printf("===================== BEM-VINDO AO DIET-C  ====================\n");
	printf("===================== PERFIL PACIENTE =========================\n");
	printf("===============================================================\n");
}
