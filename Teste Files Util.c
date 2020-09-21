#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <locale.h>
#include "lib/structutil.h"
#include "lib/definicoes.h"
#include "lib/strutil.h"
#include "lib/fileutil.h"
#include "lib/usuario.h"

#define CODIGO_PERFIL_NUTRICIONISTA "N"

void main(){
	setlocale(LC_ALL, "Portuguese");
	int usuario_senha_valida = autenticacao_usuario(CODIGO_PERFIL_NUTRICIONISTA);
	
	int max_codigo_porcao_alimento = retorna_last_id_file(CAMIMNHO_ARQUIVO_PORCAO_ALIMENTO);
	printf("max_codigo_porcao_alimento:%d\n", max_codigo_porcao_alimento);
}

