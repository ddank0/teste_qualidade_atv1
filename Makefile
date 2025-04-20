CC = gcc
CFLAGS = -Wall -Wextra -g
INCLUDES = -I. -I./test/minunit
SRC_DIR = src
TEST_DIR = test
BIN_DIR = bin

# Regras para o programa principal
$(BIN_DIR)/ticket_system.exe: $(SRC_DIR)/main.c $(SRC_DIR)/ticketFunctions.h
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $<

# Regras para os testes
$(BIN_DIR)/test_ticketFunctions.exe: $(TEST_DIR)/test_ticketFunctions.c $(SRC_DIR)/ticketFunctions.h
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -DTESTING -o $@ $<

# Regras padrão
all: $(BIN_DIR)/ticket_system.exe

test: $(BIN_DIR)/test_ticketFunctions.exe
	@$(BIN_DIR)\test_ticketFunctions.exe

clean:
	@if exist $(BIN_DIR) rmdir /s /q $(BIN_DIR)

.PHONY: all test clean 