CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
BUILD_DIR = ../build
SRC_DIR = src

all: door_struct list_test stack_test print_module documentation_module bst_create_test bst_insert_test bst_traverse_test

door_struct:
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/dmanager_module.c -o $(BUILD_DIR)/Quest_1

list_test:
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/list_test.c $(SRC_DIR)/list.c -o $(BUILD_DIR)/Quest_2

stack_test:
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/stack_test.c $(SRC_DIR)/stack.c -o $(BUILD_DIR)/Quest_3

print_module:
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/main_module_entry_point.c $(SRC_DIR)/print_module.c -o $(BUILD_DIR)/Quest_4

documentation_module:
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/main_module_entry_point.c $(SRC_DIR)/print_module.c $(SRC_DIR)/documentation_module.c -o $(BUILD_DIR)/Quest_5

bst_create_test:
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/bst_create_test.c $(SRC_DIR)/bst.c -o $(BUILD_DIR)/Quest_6

bst_insert_test:
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/bst_insert_test.c $(SRC_DIR)/bst.c -o $(BUILD_DIR)/Quest_7

bst_traverse_test:
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/bst_traverse_test.c $(SRC_DIR)/bst.c -o $(BUILD_DIR)/Quest_8

clean:
	rm -f $(BUILD_DIR)/Quest_1 $(BUILD_DIR)/Quest_2 $(BUILD_DIR)/Quest_3 $(BUILD_DIR)/Quest_4 $(BUILD_DIR)/Quest_5 $(BUILD_DIR)/Quest_6 $(BUILD_DIR)/Quest_7 $(BUILD_DIR)/Quest_8

rebuild: clean all

.PHONY: all clean rebuild door_struct list_test stack_test print_module documentation_module bst_create_test bst_insert_test bst_traverse_test