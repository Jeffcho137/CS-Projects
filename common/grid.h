/* 
 * grid.h - header file for sudoku grid module
 *
 * A suite of functions that implement the sudoku “grid” data structure;
 * this module also includes functions to get a grid from stdin
 * (used by solve.c), 
 */

#ifndef __GRID_H
#define __GRID_H

#include <stdio.h>
#include <stdbool.h>

/**************** global types ****************/
typedef int** grid_t;  // opaque to users of the module

/**************** functions ****************/

/**************** grid_new ****************/
/* Create a new (empty) grid.
 *
 * We return:
 *   pointer to a new grid, or NULL if error.
 * We guarantee:
 *   The grid is initialized with 0s.
 * Caller is responsible for:
 *   later calling grid_delete.
 */
grid_t grid_new();

/**************** grid_get ****************/
/* Return the number at the given row and column.
 *
 * Caller provides:
 *   valid pointer to grid, integers representing the row and column.
 * We return:
 *   the number at the given row and column if valid row and col;
 *   -1 if grid is NULL or row or col is not an integer from 0 to 8.
 * Notes:
 *   the grid is unchanged by this operation.
 */
int grid_get(grid_t grid, int row, int col);

/**************** grid_set ****************/
/* Sets the number at the given row and column to the given number.
 *
 * Caller provides:
 *   valid pointer to grid, integers representing the row and column.
 * We return:
 *   false if grid is NULL
 *   false if row or col is not an integer from 0 to 8,
 *   false if num is not an integer from 0 to 9,
 *   true iff new number was set.  
 */
bool grid_set(grid_t grid, int row, int col, int num);

/**************** grid_print ****************/
/* Print the whole table; provide the output file and func to print each item.
 * 
 * Caller provides:
 *   valid pointer to grid, 
 *   FILE open for writing.
 * We print:
 *   nothing, if NULL fp.
 *   "(null)" if NULL grid.
 *   otherwise, 9 lines representing the grid, with each line
 *   containing 9 integers separated by whitespace.
 * Note:
 *   the grid and its contents are not changed by this function,
 */
void grid_print(grid_t grid, FILE *fp);

/**************** grid_delete ****************/
/* Delete grid.
 *
 * Caller provides:
 *   valid grid pointer.
 * We do:
 *   if grid==NULL, do nothing.
 *   otherwise, free the grid.
 */
void grid_delete(grid_t grid);

/**************** valid_num ****************/
/* Determines if a number in the grid is valid.
 *
 * Caller provides:
 *   valid pointer to grid, integers representing the row and column.
 * We return:
 *   false, if grid==NULL.
 *   false, if row or col is not an integer from 0 to 8.
 *   false, if the number at the given row and column is found more
 *   than once in the its row, column, or 3x3 square region.
 *   true, if the number at the given row and column appears at most
 *   once in its row, column, and 3x3 square region.
 */
bool valid_num(grid_t grid, int row, int col);

/**************** valid_grid ****************/
/* Determines if a grid is a valid sudoku grid.
 *
 * Caller provides:
 *   valid grid pointer.
 * We do:
 *   if grid==NULL, do nothing.
 *   otherwise, check that each number from 1 to 9 appears at most
 *   once in every row, column, and 3x3 square region.
 * We return:
 *   false, if grid==NULL.
 *   false, if any number appears more than once in its row, column,
 *   or 3x3 square region.
 *   true, if each number from 1 to 9 appears at most once in every
 *   row, column, and 3x3 square region.
 */
bool valid_grid(grid_t grid);

/**************** load_grid ****************/
/* Loads a file and stores its contents in a new grid
 *
 * Caller provides:
 *   FILE open for reading.
 * We do:
 *   if filename==NULL, return NULL.
 *   otherwise, read the contents of the file and store it in a new grid.
 * We return:
 *   NULL if error.
 *   NULL if the contents of the file do not have valid syntax for
 *   a sudoku grid (must contain 9 lines, with each line containing
 *   exactly 9 integers from 0 to 9, separated by whitespace).
 *   NULL if the grid is not a valid sudoku grid (use valid_grid).
 *   otherwise, the pointer to the new grid.
 * Caller is responsible for:
 *   later calling grid_delete.
 */
grid_t load_grid(FILE *fp);

#endif // __GRID_H