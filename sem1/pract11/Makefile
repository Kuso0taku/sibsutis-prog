CC=gcc
CFLAGS=-Wall -Wextra -fextended-identifiers -std=c11 -O2
LDFLAGS=
SOURCES=structfunc.c main.c
OBJECTS=$(SOURCES:.c=.o)
HEADERS=structfunc.h
TARGET=program

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean
