# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
LDFLAGS = -lm

# Директории
SRC_DIR = .
DATA_LIBS_DIR = ../data_libs
DATA_MODULE_DIR = ../data_module
DECISION_MODULE_DIR = ../yet_another_decision_module
BUILD_DIR = ../../build

# Исходные файлы
SRCS = $(SRC_DIR)/main_executable_module.c \
       $(SRC_DIR)/data_sort.c \
       $(DATA_LIBS_DIR)/data_io.c \
       $(DATA_LIBS_DIR)/data_stat.c \
       $(DATA_MODULE_DIR)/data_process.c \
       $(DECISION_MODULE_DIR)/decision.c

# Заголовочные файлы
INCLUDES = -I$(DATA_LIBS_DIR) \
           -I$(DATA_MODULE_DIR) \
           -I$(DECISION_MODULE_DIR) \
           -I$(SRC_DIR)

# Объектные файлы
OBJS = $(SRCS:.c=.o)

# Имя исполняемого файла
TARGET = $(BUILD_DIR)/Quest_3

# Основная цель
all: $(BUILD_DIR) $(TARGET)

# Создание директории build
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Линковка
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Компиляция
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Очистка
clean:
	rm -f $(OBJS) $(TARGET)
	rm -rf $(BUILD_DIR)

# Пересборка
rebuild: clean all

# Псевдо-цели
.PHONY: all clean rebuild