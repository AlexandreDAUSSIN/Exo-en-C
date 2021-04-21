CC = gcc
CFLAGS = -std=c18 \
  -Wall -Wconversion -Werror -Wextra -Wpedantic -Wwrite-strings -O2 \
  -D_POSIX_C_SOURCE=200809L
LDFLAGS = -lX11
objects = sg.o sg_trial.o
executable = sg_trial

all: $(executable)

clean:
	$(RM) $(objects) $(executable)

$(executable): $(objects)
	$(CC) $(objects) $(LDFLAGS) -o $(executable)

sg.o: sg.c sg.h
sg_trial.o: sg_trial.c sg.h
