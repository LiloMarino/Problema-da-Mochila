#include "excel.h"
#include <xlsxwriter.h>

lxw_workbook* AbrirExcel(const char* filename) {
    lxw_workbook* workbook = workbook_new(filename);
    if (workbook == NULL) {
        printf("Erro ao abrir o arquivo de Excel.\n");
        return NULL;
    }
    return workbook;
}

char* GetCellValue(lxw_workbook* workbook, int planilha, int linha, int coluna){
    /* Obter a planilha pelo índice */
    lxw_worksheet* worksheet = workbook_get_worksheet_by_index(workbook, sheet_index);
    
    /* Obter a célula pela linha e coluna */
    lxw_cell* cell = worksheet->table[row][col];
    
    /* Verificar se a célula existe e se é uma célula de string */
    if (cell != NULL && cell->type == LXW_CELL_STRING) {
        /* Retornar o valor da célula */
        return cell->u.string;
    } else {
        /* Retornar NULL se a célula não existir ou não for uma célula de string */
        return NULL;
    }
}

void FechaExcel(lxw_workbook* workbook) {
    workbook_close(workbook);
}
