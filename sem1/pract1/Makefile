CC=gcc
CFLAGS=-Wall -fexec-charset=UTF-8 -fextended-identifiers -finput-charset=UTF-8
LDFLAGS=
SOURCES=task1.c task2.c task3.c task4.c task5.c task6.c task7.c task8.c
OBJECTS=
EXECUTABLE=$(SOURCES:.c=)


all: $(EXECUTABLE)


$(EXECUTABLE): %: %.c
	$(CC) $(CFLAGS) $@.c $(LDFLAGS) -o $@


clean:
	rm -f $(EXECUTABLE)

.PHONY: all clean
