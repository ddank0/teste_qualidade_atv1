CC = gcc
CFLAGS = -Wall -Wextra -g
SRC_DIR = src
TEST_DIR = test
BIN_DIR = bin

all: $(BIN_DIR)/test_ticketFunctions

$(BIN_DIR)/test_ticketFunctions: $(TEST_DIR)/test_ticketFunctions.c $(SRC_DIR)/ticketFunctions.h
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $<

test: $(BIN_DIR)/test_ticketFunctions
	@./$(BIN_DIR)/test_ticketFunctions

clean:
	rm -rf $(BIN_DIR)

.PHONY: all test clean 