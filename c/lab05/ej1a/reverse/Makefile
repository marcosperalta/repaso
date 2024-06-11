CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g -I$(HEADERS)
SOURCES = ../TADstack/stack.c reverse.c array_helpers.c
HEADERS = includes
OBJECTS = $(SOURCES:.c=.o)
TARGET  = reverse
SRC_DIR = source
BIN_DIR = binnary	
OBJ_DIR = objects


all : $(TARGET)

$(TARGET) : $(OBJECTS)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o binnary/$(TARGET) $(OBJ_DIR)/*.o

%.o : $(SRC_DIR)/%.c $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

.PHONY: clean

clean:
	@$(RM) -r $(OBJECTS) $(TARGET) binnary objects stack.o
