CC=gcc
CFLAGS=-Wall -Werror -Wextra
LDFLAGS=
SOURCES=matrix2d.c main.c
OBJECTS=$(SOURCES:.c=.o)
HEADERS=matrix2d.h
TARGET=program

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean
