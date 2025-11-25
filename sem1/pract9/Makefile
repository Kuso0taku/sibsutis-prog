CC=gcc
CFLAGS=-Wall -Wextra -fexec-charset=UTF-8 -fextended-identifiers -finput-charset=UTF-8 -std=c11
LDFLAGS=
SOURCES=matrixfunc.c main.c
OBJECTS=$(SOURCES:.c=.o)
HEADERS=myarrfunc.h
TARGET=program

all: $(TARGET)
	$(CC) $(CFLAGS) $(LDFLAGS) rand_matrix.c -o rand_matrix
	rand_matrix > matrix.txt

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS) rand_matrix matrix.txt

.PHONY: all clean
