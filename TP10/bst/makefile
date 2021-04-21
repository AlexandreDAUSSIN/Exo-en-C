addrdir = ../addr/
opstructdir = ../opstruct/
CC = gcc
CFLAGS = -std=c18 \
  -Wall -Wconversion -Werror -Wextra -Wfatal-errors -Wpedantic -Wwrite-strings \
  -O2 -I$(addrdir) -I$(opstructdir)
LDFLAGS =
VPATH = $(addrdir):$(opstructdir)
objects = bst.o main.o $(opstructdir)opstruct.o
executable = bstgame

all: $(executable)

clean:
	$(RM) $(objects) $(executable)

$(executable): $(objects) $(objects)
	$(CC) $(objects) $(LDFLAGS) -o $(executable)

bst.o: bst.c bst.h
main.o: main.c addr.h opstruct.h bst.h
$(opstructdir)opstruct.o: opstruct.c opstruct.h
