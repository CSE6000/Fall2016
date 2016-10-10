CC = gcc
OBJECTS = HelloWorld.o
.PHONY: clean

HelloWorld.txt: HelloWorld.exe
	./HelloWorld.exe > HelloWorld.txt

HelloWorld.exe: $(OBJECTS)
	$(CC) $(OBJECTS) -o HelloWorld.exe

%.o: %.c
	$(CC) -c $<

clean:
	rm -f $(OBJECTS) HelloWorld.exe HelloWorld.txt hw1_grade_result.txt
