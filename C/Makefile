
CC=gcc
CFLAGS=-Wall -Wextra -O3 -std=c99

all: matrix-multiplier matrix-multiplier-v2

matrix-multiplier: matrix-multiplier.o
		$(CC) $(CFLAGS) -o matrix-multiplier matrix-multiplier.o

matrix-multiplier-v2: matrix-multiplier-v2.o
		$(CC) $(CFLAGS) -o matrix-multiplier-v2 matrix-multiplier-v2.o


matrix-multiplier.o: matrix-multiplier.c
		$(CC) $(CFLAGS) -c matrix-multiplier.c

matrix-multiplier-v2.o: matrix-multiplier-v2.c
		$(CC) $(CFLAGS) -c matrix-multiplier-v2.c

clean:
		rm -f *.o matrix-multiplier matrix-multiplier-v2
		
