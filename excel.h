#ifndef EXCEL_H
#define EXCEL_H
#include <xlsxwriter.h>

/**
 * @brief Abre um arquivo de Excel para leitura.
 * 
 * @param filename Nome do arquivo de Excel a ser aberto.
 * @return Ponteiro para a estrutura de dados do arquivo de Excel, ou NULL se ocorrer um erro.
 * 
 * Esta função recebe o nome do arquivo de Excel a ser aberto e retorna um ponteiro para a estrutura de dados do arquivo de Excel, ou NULL se ocorrer um erro.
 * 
 * @note Esta função assume que o arquivo de Excel existe e pode ser aberto para leitura.
 */
lxw_workbook* AbrirExcel(const char* filename);

/**
 * @brief Retorna o valor de uma célula em uma planilha de um arquivo de Excel.
 * 
 * @param workbook Ponteiro para o arquivo de Excel aberto.
 * @param planilha Índice da planilha (começa em 0).
 * @param linha Número da linha da célula a ser lida (começa em 0).
 * @param coluna Número da coluna da célula a ser lida (começa em 0).
 * @return Ponteiro para uma string contendo o valor da célula, ou NULL se a célula não existir ou não for uma célula de string.
 * 
 * Esta função recebe um ponteiro para o arquivo de Excel previamente aberto, o índice da planilha, a linha e a coluna da célula a ser lida.
 * A função retorna um ponteiro para uma string contendo o valor da célula se a célula existir e for uma célula de string, e NULL caso contrário.
 * 
 * @note Esta função assume que o arquivo de Excel foi aberto com a biblioteca libxlsxwriter.
 */
char* GetCellValue(lxw_workbook* workbook, int planilha, int linha, int coluna);

/**
 * @brief Fecha um arquivo de Excel previamente aberto.
 * 
 * @param workbook Ponteiro para a estrutura de dados do arquivo de Excel.
 * 
 * Esta função recebe um ponteiro para a estrutura de dados do arquivo de Excel previamente aberto e o fecha.
 * 
 * @note Esta função deve ser chamada para cada arquivo de Excel aberto com a função open_excel_file() para liberar recursos.
 */
void FechaExcel(lxw_workbook* workbook);

#endif
