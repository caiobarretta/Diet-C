#ifndef _DEFINICOES_H
#define _DEFINICOES_H

#define CODIGO_PERFIL_NUTRICIONISTA "N"
#define CODIGO_PERFIL_PACIENTE "P"

#define CARACTER_MASCARA_SENHA '*'
#define CARACTER_SEPARACAO ','
#define CARACTER_FINAL_DE_LINHA "\n"
#define CARACTER_SEPARADOR_SELECAO '|'
#define CARACTER_SEPARADOR_INTERNO_MULTI_SELECAO '-'

#define TAMANHO_MAXIMO_CARACTERES_LINHA 1000
#define TAMANHO_MAXIMO_CARACTERES_USUARIO 100
#define TAMANHO_MAXIMO_CARACTERES_SENHA 100

#define TAMANHO_MAXIMO_CARACTERES_CODIGO 10
#define TAMANHO_MAXIMO_CARACTERES_NOME 100
#define TAMANHO_MAXIMO_CARACTERES_DESCRICAO 200
#define TAMANHO_MAXIMO_CARACTERES_PESQUISA 200
#define TAMANHO_MAXIMO_PAGINACAO_TABELAS 10

#define QTD_ITENS_PESQUISA_PADRAO 3
//dom|seg|ter|qua|qui|sex|sab|
#define QTD_DIAS_DA_SEMANA 7
//Cafe da manha|Brunch|Almoco|Lanche|Jantar|Sobremesa|Ceia|
#define QTD_REFEICOES 7

#define VALOR_SELECAO_VAZIA "Nenhum"

#define CAMIMNHO_ARQUIVO_USUARIO "db\\Usuarios.txt"
#define CAMIMNHO_ARQUIVO_PORCAO_ALIMENTO "db\\PorcaoAlimento.txt"
#define CAMIMNHO_ARQUIVO_DIETA "db\\Dieta.txt"
#define CAMIMNHO_ARQUIVO_PACIENTE "db\\Paciente.txt"

#endif /* _DEFINICOES_H */
