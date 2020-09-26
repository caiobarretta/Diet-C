
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

struct Selecao{
	int codigo_selecao;
	char* conteudo_selecao;
	char* conteudo_exibicao_selecao;
};

struct PorcaoAlimento{
	int codigo_porcao_alimento;
	char* nome;
	char* descricao;
	char* dia_da_semana;
	char* refeicoes;
};

struct Dieta{
	int codigo_dieta;
	char* nome;
	char* descricao;
	char* porcoes;
};

struct Paciente{
	int codigo_paciente;
	char* nome;
	char* descricao;
	char* dietas;
	int codigo_usuario;
	struct Login login;
};

#endif /* _STRUCTUTIL_H */
