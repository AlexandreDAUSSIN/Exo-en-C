CC = gcc
CFLAGS = -std=c18 \
  -Wall -Wconversion -Werror -Wextra -Wpedantic -Wwrite-strings -O2
LDFLAGS =
objects = main.o nat.o nat_io.o nat_op.o
executable = main

all: $(executable)

clean:
	$(RM) $(objects) $(executable)

$(executable): $(objects)
	$(CC) $(objects) $(LDFLAGS) -o $(executable)

main.o: main.c nat_io.h nat.h nat_op.h
nat.o: nat.c nat.h
nat_io.o: nat_io.c nat_io.h nat.h
nat_op.o: nat_op.c nat_op.h nat.h
