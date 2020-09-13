
#ifndef _STRUCTUTIL_H
#define _STRUCTUTIL_H

struct Login{
	int codigo_usuario;
	char* usuario;
	char* senha;
	char* codigo_perfil;
};

struct Pesquisa{
	int opcao;
	char* nome_opcao;
	int coluna_arquivo;
};

struct PorcaoAlimento{
	int codigo_porcao_alimento;
	char* nome;
	char* descricao;
	char* dia_da_semana;
	char* refeicoes;
};

#endif /* _STRUCTUTIL_H */
