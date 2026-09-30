CC      = gcc
CFLAGS  = -Wall -Wextra -Iinclude
LDLIBS  = -lm
SRC     = src/main.c src/wav.c src/tone.c
TARGET  = tone

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC) $(LDLIBS)

clean:
	rm -f $(TARGET) *.wav

.PHONY: all clean
