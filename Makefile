# Makefile for 'sudoku'
# 
# teamJST, CS 50
# August 2020

PROG = sudoku
OBJS = sudoku.o create.o solve.o grid.o
LIBS =

# uncomment the following to turn on verbose memory logging
#TESTING=-DMEMTEST

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../lib
CC = gcc
MAKE = make

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

sudoku.o: create.h solve.h grid.h
create.o: grid.h
solve.o: grid.h

.PHONY: test valgrind clean

test: $(PROG)
	bash testing.sh &> testing.out

valgrind: $(PROG)
	valgrind ./$(PROG)

clean:
	rm -rf *.dSYM  # MacOS debugger info
	rm -f *~ *.o
	rm -f $(PROG)