# Makefile for 'sudoku'
# 
# teamJST, CS 50
# August 2020

############## default: make all libs and programs ##########
all: 
	make -C common
	make -C solve
	make -C create
	make -C sudoku all

############## test sudoku ##########
test: all
	make -C sudoku test

############## valgrind ##########
valgrind: all
	make -C sudoku valgrind

############## clean  ##########
clean:
	rm -f *~
	make -C common clean
	make -C solve clean
	make -C create clean
	make -C sudoku clean