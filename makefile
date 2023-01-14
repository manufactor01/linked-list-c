CC = gcc
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror
VFLAGS = --leak-check=full --show-reachable=yes --track-origins=yes
GFLAGS = -tui
EXEC = pruebas 
OBJFILES = testing.o lista.o pruebas_alumno.o main.o

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

$(EXEC): $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -o $(EXEC)

all: $(EXEC)

run: all clear
	./$(EXEC)

clear:
	clear
valgrind: all
	valgrind $(VFLAGS) ./pruebas

zip: lista.c pruebas_alumno.c
	zip lista.zip lista.h lista.c pruebas_alumno.c

free: $(OBJFILES)
	rm -f pruebas *.o
gdb: all clear
	gdb -tui ./pruebas