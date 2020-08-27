# CS50 Sudoku Project, Summer 2020
## Jeffrey Cho, Samuel Wang, Tanli Su

### sudoku

The `sudoku` program creates and solves sudoku puzzles. It creates sudoku puzzle which have unique solutions and which are printed to stdout. It solves sudoku puzzles which may or may not have unique solutions and which are submitted via stdin.

### Usage

The sudoku program must always have one command-line argument.
* `sudoku create` to create a random sudoku puzzle
* `sudoku solve` to solve a sudoku puzzle that will be inputted via stdin

Sudoku puzzles inputted via stdin must consist of 9 lines, with each line containing exactly 9 integers from 0 to 9, separated by whitespace (0 represents a missing number). The grid represented by these 9 lines must be a valid sudoku grid (each number from 1 to 9 may appear at most once in every row, column, and 3x3 square region). For example:

```
0 0 0 2 6 0 7 0 1
6 8 0 0 7 0 0 9 0
1 9 0 0 0 4 5 0 0
8 2 0 1 0 0 0 4 0
0 0 4 6 0 2 9 0 0
0 5 0 0 0 3 0 2 8
0 0 9 3 0 0 0 7 4
0 4 0 0 5 0 0 3 6
7 0 3 0 1 8 0 0 0
```

### Implementation

See IMPLEMENTATION.md

### Assumptions

If multiple sudoku puzzles are made within the same program, then a different int seed is passed to create_puzzle each time.

### Files

* `Makefile` - compilation procedure
* `sudoku/sudoku.c` - the implementation of the sudoku program
* `create/create.c` - the implementation of the sudoku creator
* `sole/solve.c` - the implementation of the sudoku solver
* `common/grid.c` - the implementation of the sudoku grid module

### Compilation

To compile everything, simply run `make` in the top-level directory. To run the testing shell script, run `make test`.

### Exit

exit codes for `sudoku.c`
* 0: successfully created/solved a sudoku puzzle
* 1: invalid number of arguments (there must be exactly 1)
* 2: invalid argument (it must be either 'create' or 'solve)
* 3: invalid sudoku puzzle from stdin (either invalid syntax or the puzzle does not follow the rules of sudoku)

### Testing

See TESTING.md
