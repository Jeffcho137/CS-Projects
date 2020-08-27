#!/bin/bash
#
# testing.sh: performs testing for the sudoku program, including:
#   - unit test for solve.c (solvetest.c)
#   - unit test of create.c (createtest.c)
#   - fuzz testing
#   - test create and solve for sudoku.c
#
# usage: bash testing.sh
#
# inputs: none
# output: prints the test outputs
#
# Team JST CS50 Summer 2020


# unit test for solve.c
printf "unit test for solver\n"
../solve/solvetest

# unit test for create.c
printf "\nunit test for creator\n"
../create/createtest

# fuzz testing
printf "\nfuzz testing\n"
./fuzztesting 10

# test sudoku create
printf "\ntesting sudoku create\n"
./sudoku create

# creating graphics file
printf "\ncreating input graphics file\n"
./sudoku create > input.txt
cat input.txt | ./sudoku solve > output.txt
cd ..
mv sudoku/input.txt graphics/input.txt
mv sudoku/output.txt graphics/output.txt
cd sudoku

# test sudoku solve
printf "\ntesting sudoku solve\n"
echo "0 0 0 2 6 0 7 0 1" > testpuzzle
echo "6 8 0 0 7 0 0 9 0" >> testpuzzle
echo "1 9 0 0 0 4 5 0 0" >> testpuzzle
echo "8 2 0 1 0 0 0 4 0" >> testpuzzle
echo "0 0 4 6 0 2 9 0 0" >> testpuzzle
echo "0 5 0 0 0 3 0 2 8" >> testpuzzle 
echo "0 0 9 3 0 0 0 7 4" >> testpuzzle
echo "0 4 0 0 5 0 0 3 6" >> testpuzzle
echo "7 0 3 0 1 8 0 0 0" >> testpuzzle
./sudoku solve < testpuzzle

exit 0
