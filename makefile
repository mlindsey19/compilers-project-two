#mitch Lindsey
#cs4280
#03-31-2019

CC = gcc
CFLAGS = -g -Wall
OBJ = main.o scanner.o parser.o

frontEnd: $(OBJ)
	$(CC)  $(CFLAGS) -o frontEnd $(OBJ)

%.o: %.c *.h
	$(CC) -c $(CFLAGS) $*.c -o $*.o

clean:
	rm frontEnd *.o 
