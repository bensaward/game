CC=gcc
WD=$(shell pwd)
CFLAGS=--std=c99 -I$(WD)
SOURCES=initialise.c loops.c main.c print.c prng.c
L_SOURCES=launcher.c
LAUNCHER=launcher
EXECUTABLE=game


all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)
	$(CC) $(CFLAGS) $(L_SOURCES) -o $(LAUNCHER)
	
launcher:
	$(CC) $(CFLAGS) $(L_SOURCES) -o $(LAUNCHER)
	
program:
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)
	
clean:
	rm -r $(EXECUTABLE) $(LAUNCHER)