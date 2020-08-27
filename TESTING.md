# Testing for the sudoku program

Unit tests for the creator and the solver are provided in `create/createtest.c` and `solve/solvetest.c`. The unit test for the creator creates 2 sudoku puzzles, checks if they're valid, and checks if they have unique solutions. The unit test for the solver tests the local functions used by the solver and tests the solver on a manually generated sudoku puzzle.

Fuzz testing is provided in `sudoku/fuzztesting.c`. The fuzz test takes a number `n` as a command-line argument, generates `n` puzzles, and checks if each puzzle is valid and has a unique solution.

The `sudoku/testing.sh` program performs the unit tests and the fuzz test, and it also tests the`sudoku.c` program. Testing using `make test` will produce testing output in `testing.out`. The output of `testing.sh` is shown below:

TODO