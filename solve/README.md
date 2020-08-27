# CS50 Project - solve
## Team JST CS50 Summer 2020

### create description and Usage
The solve module is defined in `solve.h` and implemented in `solve.c`. 

### Functions in solve module
* `static bool check_row(grid_t grid, int row, int col, int value)`
* `static bool check_col(grid_t grid, int row, int col, int value)`
* `static bool check_board(grid_t grid, int row, int col, int value)`
* `static bool number_present(grid_t grid, int row, int col, int value)`
* `int check_unique(grid_t grid, int row, int col)`
* `static int find_row(grid_t grid, int loc)`
* `static int find_col(grid_t grid, int loc)`
* `bool solve_board(grid_t grid, int start_pos)`
* `int solver(grid_t grid)`

### Implementation
*see IMPLEMENTATION.md within the main directory*

### Files
* `Makefile` - compilation procedure
* `solve.h` - the interface
* `solve.c` - the implentation
* `createtest.c` - test program

### Compilation
`make`

### Testing
`make test`
`make valgrind` - to check for memory leaks.

### Assumptions
There are no assumptions otherwise specified in the DESIGN.md or master branch README.md file
