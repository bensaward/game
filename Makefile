CC=gcc
CFLAGS=--std=c99
SOURCES=initialise.c loops.c main.c print.c prng.c
EXECUTABLE=game


all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)
	
clean:
	rm -r game *.o