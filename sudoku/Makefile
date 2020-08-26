# Makefile for 'sudoku'

PROG = sudoku
OBJS = sudoku.o ../create/create.o ../solve/solve.o ../common/grid.o
FUZZ = fuzztesting
FUZZOBJS = fuzztesting.o ../create/create.o ../solve/solve.o ../common/grid.o
LIBS = 

# uncomment the following to turn on verbose memory logging
#TESTING=-DMEMTEST

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../common -I../create -I../solve
CC = gcc
MAKE = make

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

$(FUZZ): $(FUZZOBJS) $(LLIBS)
	$(CC) $(CFLAGS) $^ -o $@
	
sudoku.o: ../create/create.h ../solve/solve.h ../common/grid.h
create.o: ../create/create.h
solve.o:  ../solve/solve.h
grid.o: ../common/grid.h
fuzzquery.o: fuzzquery.c

.PHONY: test valgrind clean

test: $(PROG) $(FUZZ)
	bash testing.sh &> testing.out

valgrind: $(PROG)
	valgrind ./$(PROG)

clean:
	rm -rf *.dSYM  # MacOS debugger info
	rm -f *~ *.o
	rm -f $(PROG)
