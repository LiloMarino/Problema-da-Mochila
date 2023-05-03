#ifndef CONFIG_H
#define CONFIG_H

/*Configurações*/
#define CAPACIDADE_DA_MOCHILA 400
#define NUMERO_DE_ITEMS 20
#define GERAR 0 /* 1 = True, 0 = False*/
#define SHOW_ONLY_ANSWER 0 /* 1 = True, 0 = False, Ignora SHOW_ON_TERMINAL*/
#define SHOW_ON_TERMINAL 1 /* 1 = True, 0 = False*/
#define METHOD_USE 0 /* 0 = All, 1 = Gulosa, 2 = BranchBound*/

/**
 * @note Mudar a implementação recursiva em iterativa ou, se isso não for possível, 
 * otimizar sua função recursiva para reduzir o número de chamadas recursivas necessárias.
 * @note Refazer a função de geração para que esteja ligada ao NUMERO_DE_ITEMS e 
 * reduza a chance de ter uma prioridade altíssima com um tamanho pequeno por meio da geração individual dos números
 * 
 * */
#endif