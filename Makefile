CC=gcc
CFLAGS=-std=c99 -Wall -c -g
LDFLAGS=-g

SRC_DIR=src
SOURCES=main.c

OBJ_DIR=build/obj
OBJECTS=$(SOURCES:%.c=$(OBJ_DIR)/%.o)

BUILD_DIR=build
TARGET=main

.PHONY: all clean

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)
	rm -f $(BUILD_DIR)/$(TARGET)
