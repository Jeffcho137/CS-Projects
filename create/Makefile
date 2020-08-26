# Makefile for create
#
# Team JST CS50, Summer 2020

PROG = createtest
OBJS = createtest.o create.o ../common/grid.o ../solve/solve.o

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../common -I../solve
CC = gcc
MAKE = make

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

createtest.o: create.h ../common/grid.h 
create.o: create.h ../common/grid.h
grid.o: ../common/grid.h
solve.o: ../solve/solve.h

.PHONY: test valgrind clean


test: $(PROG) 
	@./$(PROG) 

valgrind: $(PROG) 
	valgrind ./$(PROG)

clean:
	rm -rf *.dSYM 
	rm -f *~ *.o
	rm -f $(PROG)

