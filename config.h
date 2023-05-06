#ifndef CONFIG_H
#define CONFIG_H

/*Configurações Gerais*/
#define CAPACIDADE_DA_MOCHILA 500
#define NUMERO_DE_ITEMS 20

/*Configurações de Geração*/
#define GERAR 0 /* 1 = True, 0 = False*/
#define NUMERO_DE_CASOS 10
#define TAMANHO_MIN 10
#define TAMANHO_MAX 200
#define PRIORIDADE_MIN 10
#define PRIORIDADE_MAX 100

/*Configurações de Execução*/
#define SHOW_ONLY_ANSWER 1 /* 1 = True, 0 = False,*/
#define SHOW_ON_TERMINAL 0 /* 1 = True, 0 = False, printa no terminal se verdadeiro e se falso mostra uma barra de progresso*/
#define METHOD_USE 0 /* 0 = All, 1 = Gulosa, 2 = BranchBound*/

#endif