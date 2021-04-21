capsdir = ../caps/
CC = gcc
CFLAGS = -std=c18 \
  -Wall -Wconversion -Werror -Wextra -Wfatal-errors -Wpedantic -Wwrite-strings \
  -O2 \
  -I$(capsdir) -DCAPS_COMPAR_LEN=1
LDFLAGS =
VPATH = $(capsdir)
objects = $(capsdir)caps.o lcaps.o main.o
executable = main

all: $(executable)

clean:
	$(RM) $(objects) $(executable)

$(executable): $(objects)
	$(CC) $(objects) $(LDFLAGS) -o $(executable)

$(capsdir)caps.o: caps.c caps.h
lcaps.o: lcaps.c lcaps.h caps.h
main.o: main.c lcaps.h caps.h
