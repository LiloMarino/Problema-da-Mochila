# Nome do projeto
PROJETO = mochila

# Arquivos fonte
FONTES = main.c arvore.c Bibliotecas/learquivo.c Bibliotecas/efficiency.c Bibliotecas/geradores.c Bibliotecas/utilities.c

# Pasta de saída
OUTPUT = output/
LOGS = logs/

# Cria a pasta de saída se ela não existir
$(shell mkdir -p $(OUTPUT) $(OUTPUT)Bibliotecas)
$(shell mkdir -p $(LOGS))

# Arquivos objeto na pasta de saída
OBJETOS = $(addprefix $(OUTPUT), $(FONTES:.c=.o))

# Compilador e opções de compilação
CC = gcc
CFLAGS = -Wall -Wextra -pedantic-errors -g -O3

# Regra padrão
all: $(OUTPUT)$(PROJETO)

# Regra para compilar o projeto
$(OUTPUT)$(PROJETO): $(OBJETOS)
	$(CC) $(OBJETOS) -o $@ -lm

# Regra para criar os arquivos objeto
$(OUTPUT)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -MMD -MP

# Inclui as dependências dos arquivos objeto
-include $(OBJETOS:.o=.d)

# Regra para limpar os arquivos objeto e o executável
clean:
	rm -rf $(OUTPUT) $(PROJETO)

# Regra para executar o programa com o Valgrind
run:
	valgrind --leak-check=full --show-leak-kinds=all --main-stacksize=16777216 $(OUTPUT)$(PROJETO)

.PHONY: all clean