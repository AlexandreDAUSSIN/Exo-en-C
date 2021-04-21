holdalldir = ../holdall/
CC = gcc
CFLAGS = -std=c18 \
  -Wall -Wconversion -Werror -Wextra -Wfatal-errors -Wpedantic -Wwrite-strings \
  -O2 \
  -I$(holdalldir) -DMSETMIN
LDFLAGS =
VPATH = $(holdalldir)
objects = $(holdalldir)holdall.o main.o mset.o
executable = main

all: $(executable)

clean:
	$(RM) $(objects) $(executable)

$(executable): $(objects)
	$(CC) $(objects) $(LDFLAGS) -o $(executable)

$(holdalldir)holdall.o: holdall.c holdall.h
main.o: main.c holdall.h mset.h
mset.o: mset.c mset.h
