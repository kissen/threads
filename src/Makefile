CFLAGS = -std=c11 -Wall -g -Wconversion -Wsign-conversion -O0
CPPFLAGS = -D_XOPEN_SOURCE=700 -D_DEFAULT_SOURCE

OBJECTS = demo.o queue.o tcb.o threads.o

.PHONY: all clean

all: demo

demo: $(OBJECTS)
	$(CC) $(CFLAGS) -o demo $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -f countup demo
	rm -f $(OBJECTS)
