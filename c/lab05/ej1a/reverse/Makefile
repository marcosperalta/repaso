CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g -I$(HEADERS)
SOURCES = ../stack.c reverse.c array_helpers.c
HEADERS = inc
OBJECTS = $(SOURCES:.c=.o)
TARGET = reverse
BIN = bin


all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $(BIN)/$(TARGET) $(OBJECTS)

%.o : %.c
	mkdir -p bin
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY: clean

clean:
	$(RM) -r $(OBJECTS) $(TARGET) bin
