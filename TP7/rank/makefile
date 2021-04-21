stackdir = ../stack/
CC = gcc
CFLAGS = -std=c18 -Wall -Wconversion -Werror -Wextra -Wpedantic -Wwrite-strings -O2 -I$(stackdir)
LDFLAGS =
VPATH = $(stackdir)
objects = main.o rank.o $(stackdir)stack.o
executable = rank

all: $(executable)

clean:
	$(RM) $(objects) $(executable)

$(executable): $(objects)
	$(CC) $(objects) $(LDFLAGS) -o $(executable)

main.o: main.c rank.h stack.h
rank.o: rank.c rank.h stack.h
stack.o: stack.c stack.h
