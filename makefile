DIRO = ./output
DIRI = ./src
CC= gcc
CFLAGS = -g -msse3

all: borrar crear

crear: 
	mkdir -p $(DIRO)
	$(CC) $(CFLAGS)  $(DIRI)/main.c -o $(DIRO)/laberinto

borrar:
	rm -rf $(DIRO)/*
