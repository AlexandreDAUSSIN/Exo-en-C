stackdir = ../stack/
CC = gcc
CFLAGS = -std=c18 -Wall -Wconversion -Werror -Wextra -Wpedantic -Wwrite-strings -O2 -I$(stackdir)
LDFLAGS =
VPATH = $(stackdir)
objects = main.o $(stackdir)stack.o
executable = sortwords

all: $(executable)

clean:
	$(RM) $(objects) $(executable)

$(executable): $(objects)
	$(CC) $(objects) $(LDFLAGS) -o $(executable)

main.o: main.c stack.h
stack.o: stack.c stack.h
