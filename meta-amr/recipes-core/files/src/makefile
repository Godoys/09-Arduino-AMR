PROJECT_DIR := $(shell pwd)
CFLAGS := -I$(PROJECT_DIR)/include/map-lib/
OBJ_DIR := obj

main: $(PROJECT_DIR)/main.c
	gcc $(CFLAGS) $(PROJECT_DIR)/lib/map-lib/map.c $(PROJECT_DIR)/lib/map-lib/map_stream.c $(PROJECT_DIR)/main.c -o main
