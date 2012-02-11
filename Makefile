CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=sudoku
SRC= $(wildcard *.cpp)
OBJS= $(SRC:.cpp=.o)

all: $(EXEC)

sudoku: $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean distclean

clean:
	rm *.o

distclean: clean
	rm $(EXEC)
