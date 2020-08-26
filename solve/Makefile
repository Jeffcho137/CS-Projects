# Makefile for create
#
# Team JST CS50, Summer 2020

PROG = solvetest
OBJS = solvetest.o solve.o ../common/grid.o

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../common 
CC = gcc
MAKE = make

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

solvetest.o: solve.h ../common/grid.h 
solve.o: solve.h ../common/grid.h
grid.o: ../common/grid.h

.PHONY: test valgrind clean


test: $(PROG) 
	@./$(PROG) 

valgrind: $(PROG) 
	valgrind ./$(PROG)

clean:
	rm -rf *.dSYM 
	rm -f *~ *.o
	rm -f $(PROG)


