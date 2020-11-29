CC=gcc
CFLAGS=-O2
LDFLAGS=-ldl -lm

all: example

example: example.c ../minivorbis.h
    $(CC) $(CFLAGS) -o example example.c $(LDFLAGS)

test: all
    ./example

clean:
    rm -f example *.exe
