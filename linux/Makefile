CC=gcc
WD=$(shell pwd)
CFLAGS=--std=c99 -I$(WD) `pkg-config --cflags --libs gtk+-2.0`
SOURCES=initialise.c loops.c main.c print.c prng.c keys.c console_interpreter.c
L_FOLDER=launcher_src/
L_SOURCES=$(L_FOLDER)launcher_main.c $(L_FOLDER)launcher_initialise.c $(L_FOLDER)launcher_window.c
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
	
all_debug:
	$(CC) $(CFLAGS) -ggdb $(SOURCES) -o $(EXECUTABLE)
	$(CC) $(CFLAGS) -ggdb $(L_SOURCES) -o $(LAUNCHER)
	