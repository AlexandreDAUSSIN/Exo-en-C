capsdir = ../caps/
CC = gcc
CFLAGS = -std=c18 \
  -Wall -Wconversion -Werror -Wextra -Wfatal-errors -Wpedantic -Wwrite-strings \
  -O2 \
  -I$(capsdir) -DCAPS_COMPAR_LEN=2
LDFLAGS =
VPATH = $(capsdir)
objects = $(capsdir)caps.o caps_trial.o
executable = caps_trial

all: $(executable)

clean:
	$(RM) $(objects) $(executable)

$(executable): $(objects)
	$(CC) $(objects) $(LDFLAGS) -o $(executable)

caps.o: caps.c caps.h
caps_trial.o: caps_trial.c caps.h
