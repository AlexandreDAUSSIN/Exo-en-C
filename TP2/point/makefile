sgdir = ../sg/
CC = gcc
CFLAGS = -std=c18 \
  -Wall -Wconversion -Werror -Wextra -Wpedantic -Wwrite-strings -O2 \
  -D_POSIX_C_SOURCE=200809L -I$(sgdir)
LDFLAGS = -lX11 -lm
VPATH = $(sgdir)
objects = point.o point_trial.o $(sgdir)sg.o
executable = point_trial

all: $(executable)

clean:
	$(RM) $(objects) $(executable)

$(executable): $(objects)
	$(CC) $(objects) $(LDFLAGS) -o $(executable)

point.o: point.c point.h sg.h
point_trial.o: point_trial.c point.h sg.h
$(sgdir)sg.o: sg.c sg.h
