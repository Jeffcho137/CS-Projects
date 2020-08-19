# Sudoku Design Spec

The **sudoku** program creates and solves sudoku puzzles. It creates sudoku puzzle which have unique solutions and which are printed to stdout. It solves sudoku puzzles which may or may not have unique solutions and which are submitted via stdin.

### User interface

The sudoku program must always have one command-line argument.
* `sudoku create` to create a random sudoku puzzle
* `sudoku solve` to solve a sudoku puzzle that will be inputted via stdin

Sudoku puzzles inputted via stdin must consist of 9 lines, with each line containing exactly 9 integers from 0 to 9, separated by whitespace (0 represents a missing number). The grid represented by these 9 lines must be a valid sudoku grid (each number from 1 to 9 may appear at most once in every row, column, and 3x3 square region).

### Inputs and outputs

Input: See the User Interface above.

Output: If creating a sudoku puzzle, the program prints the created puzzle to stdout. If solving a sudoku puzzle, the program prints the solved puzzle to stdout.

### Functional decomposition into modules

We anticipate the following functions:

 1. *main*, which parses arguments and prints the puzzle to stdout
 2. *create_puzzle*, which creates a sudoku puzzle with a unique solution
 3. *solve_puzzle*, which solves a given sudoku puzzle
 4. *get_grid*, which prompts the user for input from stdin and stores the sudoku grid
 5. *valid_grid*, which checks if a grid is a valid sudoku puzzle
 6. *print_grid*, which prints a sudoku grid to stdout

### Pseudo code for logic/algorithmic flow

The sudoku program will run as follows:

1. execute from a command line as shown in the User Interface
2. parse the command line and validate parameters
3. if `create`, create a sudoku puzzle
4. if `solve`, get input from stdin, validate the input, and solve the sudoku puzzle
5. print the created/solved puzzle to stdout

### Dataflow through modules

 1. *main* parses parameters, either calls *create_puzzle* or calls *get_grid* and *solve_puzzle*, and lastly calls *print_grid* to print the result
 2. *create_puzzle* creates a sudoku puzzle and returns it to *main*
 3. *get_grid* gets input from stdin, stores the sudoku_grid, calls *valid_grid* to check that it is valid, and returns the sudoku grid to *main*
 4. *solve_puzzle* gets the sudoku grid created by *get_grid*, solves it, and returns the solved puzzle to *main*
 5. *print_grid* gets the sudoku grid returned by *create_puzzle* or *solve_puzzle* and prints it to stdout

### Major data structures

The following helper modules provide data structures:

 1. *grid* to store a sudoku grid

### Testing plan

0. Test the program with incorrect command-line arguments to ensure that its command-line parsing, and validation of those parameters, works correctly.

1. Test the program to create a sudoku puzzle. Check that the puzzle has a unique solution.

2. Test the program to solve sudoku puzzles inputted via stdin.
* a. Test with a grid inputted via stdin which has invalid syntax.
* b. Test with a grid inputted via stdin which is not a valid sudoku grid.
* c. Test with a valid sudoku grid which has a unique solution.
* d. Test with a valid sudoku grid which does not have a unique solution.