#ifndef CONFIG_H
#define CONFIG_H

/*Configurações Gerais*/
#define CLASSE_DA_MOCHILA 6 /* 0 = Classe Custom, 1 = Classe P1, 2 = Classe P2, 3 = Classe M1, 4 = Classe M2, 5 = Classe G1, 6 = Classe G2 */
#define MODO 3              /* 0 = Gera, 1 = Executa, 2 = Compila os registros gerais, 3 = Compila os csv*/
#define NUMERO_DE_CASOS 100
/// @warning Definir a classe da mochila desabilita a customização
/// @warning Para utilizar o modo 2 programa deve ter sido executado com UNICO_REGISTRO_POR_MOCHILA 1

/*Configurações de Geração*/
#if CLASSE_DA_MOCHILA == 0
#define CAPACIDADE_DA_MOCHILA 500
#define NUMERO_DE_ITEMS 20
#define TAMANHO_MIN 10
#define TAMANHO_MAX 200
#define PRIORIDADE_MIN 10
#define PRIORIDADE_MAX 100
#endif

/*Configurações de Execução*/
#define UNICO_REGISTRO_POR_MOCHILA 1 /* 1 = True, 0 = False*/
#define SHOW_ONLY_ANSWER 1           /* 1 = True, 0 = False, Se falso printa todos os casos testados tanto nos arquivos quanto no terminal*/
#define SHOW_ON_TERMINAL 0           /* 1 = True, 0 = False, printa no terminal se verdadeiro e se falso mostra uma barra de progresso*/
#define SHOW_LIMITANT 1              /* 1 = True, 0 = False, Se verdadeiro mostra a comparação do limitante , SHOW_ON_TERMINAL precisa ser verdadeiro para funcionar*/
#define METHOD_USE 0                 /* 0 = Todas exceto a Gulosa, 1 = MOPT, 2 = BranchBound, 3 = MOP, 4 = MOT, 5 = Gulosa*/
#define DELETE_DADOS 1               /* 1 = True, 0 = False, Deleta os dados.txt na compilação dos dados*/

/*Definições das classes das mochilas*/
#if CLASSE_DA_MOCHILA == 1
#define CAPACIDADE_DA_MOCHILA 500
#define NUMERO_DE_ITEMS 100
#define TAMANHO_MIN 10
#define TAMANHO_MAX 200
#define PRIORIDADE_MIN 10
#define PRIORIDADE_MAX 100
#elif CLASSE_DA_MOCHILA == 2
#define CAPACIDADE_DA_MOCHILA 500
#define NUMERO_DE_ITEMS 100
#define TAMANHO_MIN 200
#define TAMANHO_MAX 500
#define PRIORIDADE_MIN 10
#define PRIORIDADE_MAX 100
#elif CLASSE_DA_MOCHILA == 3
#define CAPACIDADE_DA_MOCHILA 500
#define NUMERO_DE_ITEMS 1000
#define TAMANHO_MIN 10
#define TAMANHO_MAX 200
#define PRIORIDADE_MIN 10
#define PRIORIDADE_MAX 100
#elif CLASSE_DA_MOCHILA == 4
#define CAPACIDADE_DA_MOCHILA 500
#define NUMERO_DE_ITEMS 1000
#define TAMANHO_MIN 200
#define TAMANHO_MAX 500
#define PRIORIDADE_MIN 10
#define PRIORIDADE_MAX 100
#elif CLASSE_DA_MOCHILA == 5
#define CAPACIDADE_DA_MOCHILA 500
#define NUMERO_DE_ITEMS 10000
#define TAMANHO_MIN 10
#define TAMANHO_MAX 200
#define PRIORIDADE_MIN 10
#define PRIORIDADE_MAX 100
#elif CLASSE_DA_MOCHILA == 6
#define CAPACIDADE_DA_MOCHILA 500
#define NUMERO_DE_ITEMS 10000
#define TAMANHO_MIN 200
#define TAMANHO_MAX 500
#define PRIORIDADE_MIN 10
#define PRIORIDADE_MAX 100
#endif

#endif