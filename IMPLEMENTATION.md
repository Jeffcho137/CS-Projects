# Sudoku Implementation Spec

### sudoku.c
`sudoku.c` is implemented as follows.
The `main` function first validates and parses parameters. If the parameter is `create`, it then calls `create_puzzle` to create a puzzle. If the parameter is `solve`, it then calls the grid module's `load_grid` function to get a sudoku puzzle from stdin, and it calls `solver` to solve the puzzle. Lastly, it calls `print_grid` to print the result.

### solve.c
`solve.c` is implemented as follows.
TODO

### create.c
`create.c` is implemented as follows.
TODO


## Modules used
`sudoku.c`, `solve.c`, and `create.c` all use the `grid` module, which is implemented in `common/grid.c`.

## Error handling
The `main` function in `sudoku.c` returns `0` if it executes successfully; otherwise, it prints an error message and returns with non-zero exit status.