pointdir = ../point/
sgdir = ../sg/
CC = gcc
CFLAGS = -std=c18 \
  -Wall -Wconversion -Werror -Wextra -Wfatal-errors -Wpedantic -Wwrite-strings \
  -O2 \
  -D_POSIX_C_SOURCE=200809L -I$(pointdir) -I$(sgdir)
LDFLAGS = -lX11 -lm
VPATH = $(pointdir):$(sgdir)
objects = fractal.o main.o $(pointdir)point.o $(sgdir)sg.o
executable = fractal

all: $(executable)

clean:
	$(RM) $(objects) $(executable)

$(executable): $(objects)
	$(CC) $(objects) $(LDFLAGS) -o $(executable)

fractal.o: fractal.c point.h sg.h fractal.h
main.o: main.c sg.h fractal.h
$(pointdir)point.o: point.c point.h
$(sgdir)sg.o: sg.c sg.h
