# Makefile for 'common' library

OBJS = grid.o
LIBS = common.a

FLAGS = # -DMEMTEST

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(FLAGS)
CC = gcc

$(LIB): $(OBJS)
	ar cr $(LIB) $(OBJS)

grid.o: grid.h

.PHONY: clean

clean:
	rm -f core
	rm -f $(LIB) *~ *.o
