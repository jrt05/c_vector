
CC=clang
#CCFLAGS=-Wall -Werror -g
#CCLINK=
OPT=
CCFLAGS=-Wall -Werror -Wextra -Wpedantic -g -fsanitize=address -fsanitize=undefined
CCLINK=-fsanitize=address -fsanitize=undefined

all: run

run: main.o vector.o
	$(CC) $(CCLINK) -o run main.o vector.o

main.o: main.c vector.h
	$(CC) $(OPT) $(CCFLAGS) -c -o main.o main.c

vector.o: vector.c vector.h
	$(CC) $(OPT) $(CCFLAGS) -c -o vector.o vector.c

clean:
	rm run *.o
