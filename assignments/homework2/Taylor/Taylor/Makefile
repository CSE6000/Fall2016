CC = gcc
SOURCES = $(wildcard *.c)
OBJECTS = $(subst .c,.o,$(SOURCES))

.PHONY: clean

TaylorMain.out: $(OBJECTS)
	$(CC) $(OBJECTS) -o TaylorMain.out

%.o: %.c
	$(CC) -c $<

clean:
	rm -f $(OBJECTS) TaylorMain.out output1.txt output2.txt
