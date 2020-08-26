/* 
 * grid.c - sudoku 'grid' module
 * see grid.h for more information.
 */

#include <stdio.h>
#include <stdlib.h>
#include "grid.h"

/**************** file-local global variables ****************/
/* none */

/**************** global types ****************/
typedef int** grid_t;   // 2D array representing 9 rows of 9 integers

/*
 * SUGGESTION
 */
/*
 * typedef struct grid{
 * 	int** board;
 * }grid_t*
 *
 *
 */

// WE WOULD BASICALLY CHANGE ALL GRID[ROW][COL] TO GRID->BOARD[ROW][COL]

/**************** global functions ****************/
/* that is, visible outside this file */
/* see grid.h for comments about exported functions */

/**************** local functions ****************/
/* none */

/**************** grid_new() ****************/
/* see grid.h for description */
grid_t *
grid_new()
{
  grid_t* grid = malloc(9 * 9 * sizeof(int *));
  if (grid == NULL) {
    return NULL;              // error allocating grid
  }

  // initialize the contents of each row
  for (int i = 0; i < 9; i++) {
    grid[i] = malloc(9 * sizeof(int *));
    if (grid[i] == NULL) {
        return NULL;          // error allocating grid
    }

    // fill row with 0s
    for (int j = 0; j < 9; j++) {
        grid[i][j] = 0;
    }
  }

  return grid;
}

/**************** grid_get() ****************/
/* see grid.h for description */
int
grid_get(grid_t* grid, int row, int col)
{
  if (grid == NULL) { // bad grid
    return -1;
  } else if (row < 0 || col < 0 || row > 8 || col > 8) { // bad row/col
    return -1;
  } else {
    return *grid[row][col];
  }
}

/**************** grid_set() ****************/
/* see grid.h for description */
bool
grid_set(grid_t* grid, int row, int col, int num)
{
  if (grid == NULL) { // bad grid
    return false;
  } else if (row < 0 || col < 0 || row > 8 || col > 8) { // bad row/col
    return false;
  } else if (num < 0 || num > 9) { // bad num
    return false;
  } else {
    grid[row][col] = &num;
    return true;
  }
}



/**************** grid_print() ****************/
/* see grid.h for description */
void
grid_print(grid_t* grid, FILE *fp)
{
  if (fp != NULL) {
    if (grid != NULL) {
      for (int i = 0; i < 9; i++) {
        // print this row
        for (int j = 0; j < 8; j++) {
            fprintf(fp, "%d ", *grid[i][j]);
        }
        fprintf(fp, "%d\n", *grid[i][9]);
      }
    } else {
      fprintf(fp, "(null)");
    }
  }
}

/**************** grid_delete() ****************/
/* see grid.h for description */
void 
grid_delete(grid_t* grid)
{
  if (grid != NULL) {
    for (int i = 0; i < 9; i++) {
      free(grid[i]);
    }
    free(grid);
  }
}

/**************** valid_num() ****************/
/* see grid.h for description */
bool
valid_num(grid_t* grid, int row, int col)
{
  if (grid == NULL) { // bad grid
    return false;
  } else if (row < 0 || col < 0 || row > 8 || col > 8) { // bad row/col
    return false;
  }

  int num = *grid[row][col];
  for (int i = 0; i < 9; i++) {
    // check its row
    if (i != col && *grid[row][i] == num) {
      return false;
    }
    // check its column
    if (i != row && *grid[i][col] == num) {
      return false;
    }
  }
  // check its 3x3 square
  for (int i = row - (row % 3); i < i + 3; i++) {
    for (int j = col - (col % 3); j < j + 3; j++) {
      if (!(i == row && j == col) && *grid[i][j] == num) {
        return false;
      }
    }
  }

  return true;
}

/**************** valid_grid() ****************/
/* see grid.h for description */
bool
valid_grid(grid_t* grid)
{
  if (grid != NULL) {
    // check that each row is valid
    for (int i = 0; i < 9; i++) {
        // keep track of numbers that have been found
        bool found_num[9];
        for (int j = 0; j < 9; j++) {
            found_num[j] = false;
        }
        // check each number in the row
        for (int j = 0; j < 9; j++) {
            int num = *grid[i][j];
            if (num != 0) {
                if (found_num[num]) {
                    return false;
                }
                found_num[num] = true;
            }
        }
    }

    // check that each column is valid
    for (int i = 0; i < 9; i++) {
        // keep track of numbers that have been found
        bool found_num[9];
        for (int j = 0; j < 9; j++) {
            found_num[j] = false;
        }
        // check each number in the column
        for (int j = 0; j < 9; j++) {
            int num = *grid[j][i];
            if (num != 0) {
                if (found_num[num]) {
                    return false;
                }
                found_num[num] = true;
            }
        }
    }

    // check that each 3x3 square is valid
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // keep track of numbers that have been found
            bool found_num[9];
            for (int k = 0; k < 9; k++) {
                found_num[k] = false;
            }
            // check each number in the grid
            for (int row = 3 * i + 1; row < 3 * i + 4; row++) {
                for (int col = 3 * j + 1; row < 3 * i + 4; row++) {
                    int num = *grid[row][col];
                    if (num != 0) {
                        if (found_num[num]) {
                            return false;
                        }
                        found_num[num] = true;
                    }
                }
            }
        }
    }

    return true;
  }

  return false;
}

/**************** load_grid() ****************/
/* see grid.h for description */
grid_t *
load_grid(FILE *fp)
{
  if (fp == NULL) {
      return NULL;
  }

  grid_t* grid = grid_new();
  if (grid != NULL) {
    // read in each row
    for (int i = 0; i < 9; i++) {
        if (fscanf(fp, "%d %d %d %d %d %d %d %d %d",
            grid[i][0], grid[i][1], grid[i][2],
            grid[i][3], grid[i][4], grid[i][5],
            grid[i][6], grid[i][7], grid[i][8])
            != 9) {
            return NULL; // the row has invalid syntax
        }
    }
    // check that the sudoku grid is valid
    if (!valid_grid(grid)) {
        return NULL;
    }
  }

  return grid;
}
