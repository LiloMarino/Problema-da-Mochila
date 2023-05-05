#ifndef CONFIG_H
#define CONFIG_H

/*Configurações Gerais*/
#define CAPACIDADE_DA_MOCHILA 500
#define NUMERO_DE_ITEMS 20

/*Configurações de Geração*/
#define GERAR 1 /* 1 = True, 0 = False*/
#define NUMERO_DE_CASOS 100
#define TAMANHO_MIN 10
#define TAMANHO_MAX 200
#define PRIORIDADE_MIN 10
#define PRIORIDADE_MAX 100

/*Configurações de Execução*/
#define SHOW_ONLY_ANSWER 0 /* 1 = True, 0 = False, Ignora SHOW_ON_TERMINAL*/
#define SHOW_ON_TERMINAL 1 /* 1 = True, 0 = False*/
#define METHOD_USE 0 /* 0 = All, 1 = Gulosa, 2 = BranchBound*/

#endif