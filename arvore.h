#ifndef ARVORE_H
#define ARVORE_H

#define CAPACIDADE_DA_MOCHILA 400
#define NUMERO_DE_ITEMS 4

struct StElemento
{
    int Prioridade;
    int Tamanho;
    int MaxQntde;
};

typedef struct StElemento Elemento;

/**
 *  @brief Realiza os testes pelo método da Heuristica Gulosa
 * 
 *  @note Recomendado apenas para a elaboração de outros métodos por conta da sua ineficiência
 * 
 * */
void HeuristicaGulosa(Elemento Itens[], int Quantidades[]);

#endif