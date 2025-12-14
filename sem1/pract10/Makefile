CC=gcc
CFLAGS=-Wall -Wextra -fextended-identifiers -std=c11
LDFLAGS=
SOURCES=stringfunc.c main.c
OBJECTS=$(SOURCES:.c=.o)
HEADERS=stringfunc.h
TARGET=program

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean
