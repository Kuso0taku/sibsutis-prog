CC=gcc
CFLAGS=-Wall -fexec-charset=UTF-8 -fextended-identifiers -finput-charset=UTF-8
LDFLAGS= -lm
SOURCES=task1.c task2.c task3.c task4.c task5.c task6.c task7.c task8.c task9.c task10.c task11.c task12.c task13.c task14.c task15.c task16.c 
OBJECTS=
EXECUTABLE=$(SOURCES:.c=)


all: $(EXECUTABLE)


$(EXECUTABLE): %: %.c
	$(CC) $(CFLAGS) $@.c $(LDFLAGS) -o $@


clean:
	rm -f $(EXECUTABLE)

.PHONY: all clean
