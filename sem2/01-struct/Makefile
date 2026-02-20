CC=gcc
CFLAGS=-Wall -Werror -Wextra
LDFLAGS=
SOURCES=struct.c main.c
OBJECTS=$(SOURCES:.c=.o)
HEADERS=struct.h
TARGET=program

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean
