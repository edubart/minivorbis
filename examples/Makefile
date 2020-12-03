CC=gcc
CFLAGS=-O2
LDFLAGS=-ldl -lm -lpthread

all: example playback playback2

example: example.c ../minivorbis.h
	$(CC) $(CFLAGS) -o example example.c $(LDFLAGS)

playback: playback.c ../minivorbis.h ../miniaudio_vorbis.h ../miniaudio.h
	$(CC) $(CFLAGS) -o playback playback.c $(LDFLAGS)

playback2: playback2.c ../minivorbis.h ../miniaudio_vorbis.h ../miniaudio_engine.h ../miniaudio.h
	$(CC) $(CFLAGS) -o playback2 playback2.c $(LDFLAGS)

test: all
	./example

clean:
	rm -f example playback playback2 *.exe
