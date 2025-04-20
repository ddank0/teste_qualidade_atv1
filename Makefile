CC = gcc
CFLAGS = -Wall -Wextra -g
INCLUDES = -I. -I./test/minunit
SRC_DIR = src
TEST_DIR = test
BIN_DIR = bin

# Regras para o programa principal
$(BIN_DIR)/ticket_system: $(SRC_DIR)/main.c $(SRC_DIR)/ticketFunctions.h
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $<

# Regras para os testes
$(BIN_DIR)/test_ticketFunctions: $(TEST_DIR)/test_ticketFunctions.c $(SRC_DIR)/ticketFunctions.h
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -DTESTING -o $@ $<

# Regras padrão
all: $(BIN_DIR)/ticket_system

test: $(BIN_DIR)/test_ticketFunctions
	@./$(BIN_DIR)/test_ticketFunctions

clean:
	rm -rf $(BIN_DIR)

.PHONY: all test clean 