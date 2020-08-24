# Makefile for 'sudoku'

PROG = sudoku
OBJS = sudoku.o
LIBS = ../common/common.a

# uncomment the following to turn on verbose memory logging
#TESTING=-DMEMTEST

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../lib
CC = gcc
MAKE = make

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

sudoku.o: ../create/create.h ../solve/solve.h ../common/grid.h

.PHONY: test valgrind clean

test: $(PROG)
	bash testing.sh &> testing.out

valgrind: $(PROG)
	valgrind ./$(PROG)

clean:
	rm -rf *.dSYM  # MacOS debugger info
	rm -f *~ *.o
	rm -f $(PROG)
