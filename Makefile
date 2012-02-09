CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=sudoku
SRC= $(wildcard *.cpp)
OBJS= $(SRC:.cpp=.o)

all: $(EXEC)

sudoku: $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

#main.o: Box.h Grid.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm *.o

mrproper: clean
	rm $(EXEC)
