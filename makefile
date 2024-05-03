CC = gcc
AS = nasm
CFLAGS = -Wall -Wextra -std=c99
ASMFLAGS = -f elf64

all: generador

generador: generador.o main.o
	$(CC) $(CFLAGS) -no-pie -o generador generador.o main.o

generador.o: generador.asm
	$(AS) $(ASMFLAGS) -o generador.o generador.asm

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o generador

