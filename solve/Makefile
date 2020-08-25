# Makefile
#
# Solve 
#
# Team JST CS50 Summer 2020
#
PROG = solvetest
OBGS = solvetest.o ../common/grid.o
LIBS =

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../common
CC = gcc
MAKE = make

.PHONY: test clean

# executable depends on object files
$(PROG): $(OBGS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $(PROG)


# object files depend on include files

solvetest.o: solve.h #-I../common/grid.h
	solve.o: solve.h
	#grid.o: grid.h
test: $(PROG)
	./$(PROG)

valgrind: $(PROG)
	valgrind ./$(PROG)

clean:
	rm -rf *.dSYM
	rm -f *~ *.o
	rm -f  $(PROG)
