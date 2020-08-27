# Sudoku Implementation Spec

### sudoku.c
`sudoku.c` is implemented as follows.
The `main` function first validates and parses parameters. If the parameter is `create`, it then calls `create_puzzle` to create a puzzle. If the parameter is `solve`, it then calls the grid module's `load_grid` function to get a sudoku puzzle from stdin, and it calls `solver` to solve the puzzle. Lastly, it calls `print_grid` to print the result.

### solve.c
`solve.c` is implemented as follows.

Solve is implemented by taking in a sudoku grid from input. It then procees by solving the sudoku grid by filling in empty cells and by backtracking when values are not able to be inserted. This process is recursive until the sudoku grid is fully solved. Then using `grid_print` the grid can be printed for the user using stdout. 

`Implementation`

1. Take in a grid from stdin
2. We then pass the grid to solver. 
3. Using `check_unqiue` we can check whether the grid has a unique solution 
4. `check_unique` returns 0 for no solutions, 1 for a unique solution, and 2 or more regarding how many total solutions exist. 
5. We then go through the entire grid through each row and col. 
6. We recursively check for empty row, col spaces (0). We then call `solve_board`. 
7. `solve_board` works by calling the `solve_board` starting from the first row, col in the grid. It then skips over the filled spaces until we reach the next empty place in the grid, which would have a value of 0.  
8. We start from a value of 1, and then we insert that value into the non-filled spcae.. 
9. We also check if the value is already present in its row, column, or 3x3 grid through `number_present`, or if the recursively call for `solve_board` for the next empty rol, col doesn't lead to a solved grid. 
10. We then increment the value of the number that is to be inserted and we repeat this process again
11. Now, we check if the grid has a unique solution. If so, we then print the solved grid to stdout, but if not, we return error and exit the process.
12. Lastly, we delete the board

### solve.c functions
* `static bool check_row(grid_t grid, int row, int col, int value)`
* `static bool check_col(grid_t grid, int row, int col, int value)`
* `static bool check_board(grid_t grid, int row, int col, int value)`
* `static bool number_present(grid_t grid, int row, int col, int value)`
* `int check_unique(grid_t grid, int row, int col)`
* `static int find_row(grid_t grid, int loc)`
* `static int find_col(grid_t grid, int loc)` 
* `bool solve_board(grid_t grid, int start_pos)`
* `int solver(grid_t grid)`

### create.c
`create.c` is implemented as follows.

`create_puzzle` takes no parameters and returns a valid sudoku puzzle with a unique solution. The puzzle is returned with 45 numbers removed. 

1. A grid is first created with grid_new() and srand is called with time(NULL) to seed random with the current time. 
2. The function then has a for loop which fills in the three matrices in the left diagonal. For each row within each matrix, an array is filled with the numbers 1-9 and the array is shuffled with `array_shuffle`. The value at each column is then set with a number from the array. If the number is not valid, then numbers are continuously tried until one is valid. 
3. After filling in the diagonal, each row and column is iterated through. If there is already a number at the position, then the loop continues. Otherwise each number from 1-9 is tried at the position until the number is valid and allows for one or more solutions. 
4. After the grid is filled, 45 numbers are deleted with `delete_numbers`, which loops through random row/column pairs and sets the number at the row/column to zero if there is still a unique solution after the deletion. 
5. After 45 numbers are deleted, the grid is returned.

### create.c functions
```c
grid_t create_puzzle();
static void array_shuffle(int nums[], int length);
static void delete_numbers(grid_t grid);
```

## Modules used
`sudoku.c`, `solve.c`, and `create.c` all use the `grid` module, which is implemented in `common/grid.c`.

## Error handling
The `main` function in `sudoku.c` returns `0` if it executes successfully; otherwise, it prints an error message and returns with non-zero exit status.
