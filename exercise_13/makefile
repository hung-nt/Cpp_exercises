CC = g++
CFLAGS = -std=c++11

all: main

main: main.o
	$(CC) $(CFLAGS) -o main main.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

run: main
	./main

clean:
	rm -f main *.o *.exe
