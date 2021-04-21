hashtabledir = ../hashtable/
holdalldir = ../holdall/
CC = gcc
CFLAGS = -std=c18 \
  -Wall -Wconversion -Werror -Wextra -Wfatal-errors -Wpedantic -Wwrite-strings \
  -O2 \
  -I$(hashtabledir) -I$(holdalldir)
LDFLAGS =
VPATH = $(hashtabledir):$(holdalldir)
objects = $(hashtabledir)hashtable.o $(holdalldir)holdall.o main.o
executable = main

all: $(executable)

clean:
	$(RM) $(objects) $(executable)

$(executable): $(objects)
	$(CC) $(objects) $(LDFLAGS) -o $(executable)

$(hashtabledir)hashtable.o: hashtable.c hashtable.h
$(holdalldir)holdall.o: holdall.c holdall.h
main.o: main.c hashtable.h holdall.h
