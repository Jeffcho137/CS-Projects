# CS50 Project - create
## Team JST CS50 Summer 2020

### create description and Usage
The create module is defined in `create.h` and implemented in `create.c`. `create.h` exports one function: `grid_t create_puzzle(int seed);` 

`create_puzzle` takes an int seed as a parameter and returns a valid sudoku puzzle with a unique solution. The puzzle is returned with 45 numbers removed.

### Implementation
*see IMPLEMENTATION.md within the main directory*

### Files
* `Makefile` - compilation procedure
* `create.h` - the interface
* `create.c` - the implentation
* `createtest.c` - test program

### Compilation
`make`

### Testing
`make test`
`make valgrind` - to check for memory leaks.

### Assumptions
If multiple sudoku puzzles are made within the same program, then a different int seed is passed to create_puzzle each time.
