#ifndef CONFIG_H
#define CONFIG_H

/*Configurações Gerais*/
#define CLASSE_DA_MOCHILA 0      /* 0 = Classe Custom, 1 = Classe P1, 2 = Classe P2, 3 = Classe M1, 4 = Classe M2, 5 = Classe G1, 6 = Classe G2 */
#define GERAR 1                  /* 1 = True, 0 = False*/
#define COMPILA_REGISTRO_GERAL 1 /* 1 = True, 0 = False*/
#define NUMERO_DE_CASOS 100
/// @warning Definir a classe da mochila desabilita a customização

/*Configurações de Geração*/
#define CAPACIDADE_DA_MOCHILA 500
#define NUMERO_DE_ITEMS 20
#define TAMANHO_MIN 10
#define TAMANHO_MAX 200
#define PRIORIDADE_MIN 10
#define PRIORIDADE_MAX 100

/*Configurações de Execução*/
#define UNICO_REGISTRO_POR_MOCHILA 1 /* 1 = True, 0 = False,*/
#define SHOW_ONLY_ANSWER 1           /* 1 = True, 0 = False,*/
#define SHOW_ON_TERMINAL 0           /* 1 = True, 0 = False, printa no terminal se verdadeiro e se falso mostra uma barra de progresso*/
#define METHOD_USE 0                 /* 0 = Todas exceto a Gulosa, 1 = MOPT, 2 = BranchBound, 3 = MOP, 4 = MOT, 5 = Gulosa*/

#endif