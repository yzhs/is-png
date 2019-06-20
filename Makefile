WARN=-Wall -Wextra -Wpedantic

all: is-png

is-png: main.c
	musl-gcc -static -Os $(WARN) -o $@ $^

clean:
	-rm is-png

.PHONY: all clean
