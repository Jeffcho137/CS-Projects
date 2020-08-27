/*
 * solve.c - implementation for header solve.h
 *
 * Team JST CS50 Summer 2020
 */ 

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../common/grid.h"
#include "solve.h"


/********** check_row **********/
/*
 * checks if a number exists in a row
 */
static bool check_row(grid_t grid, int row, int col, int value)
{
  // loop over each col
  for (int i = 0; i < 9; i++)
  {
    if (i == col)
      continue;
		
  // check for the value 
  if (grid_get(grid, row, i) == value)
    return true;
  }

  return false;
}

/********** check_col **********/
/*
 * checks if a number exists in a column
 */
static bool check_col(grid_t grid, int row, int col, int value)
{
  // loop over each row
  for (int i = 0; i < 9; i++)
  {
    if (i == row)
	continue;
		
    // checking for the value
    if (grid_get(grid, i, col) == value)
	return true;
  }

  return false;
}

/********** check_board **********/
/*
 * checks if a number exists in a smaller divided board (9 X 9) --> (3 X 3)
 */
static bool check_board(grid_t grid, int row, int col, int value)
{
  // obtain the beginning row and column position of the value
  int beg_row = (int)(row/3) * 3;
  int beg_col = (int)(col/3) * 3;
	
  // loop over both row and col
  for (int i = beg_row; i < beg_row + 3; i++)
  {
    for (int j = beg_col; j < beg_col + 3; j++)
    {
      if (i == row && j == col)
	continue;

      if (grid_get(grid, i, j) == value)
	return true;
    }
	
  }

  return false;
}


/********** number_present **********/
/*
 * tries to see if a number already exists in a cell
 */

static bool number_present(grid_t grid, int row, int col, int value)
{

  // checking 
  if (check_row(grid, row, col, value))
    return true;
  if (check_col(grid, row, col, value))
    return true;
  if (check_board(grid, row, col, value))
    return true;
    
  return false;
}

/********** check_unique() **********/
/* see solve.h for more info */
int check_unique(grid_t grid, int row, int col)
{
  // if row equals nine, then reached of board and return 1
  if (row == 9) {
    return 1;
  }

  // if col equals nine, go to next row
  if (col == 9) {
    return check_unique(grid, row + 1, 0);
  }

  // if number at the position is non-zero, go to next col
  if (grid_get(grid, row, col) != 0) {
    return check_unique(grid, row, col + 1);
  }

  // iterate through each number 1-9 and attempt to set it at the position
  int total = 0;
  for (int i = 1; i <= 9; i++) {
    grid_set(grid, row, col, i);
   
    // if its valid, recurse with next row and add number of solutions for it
    if (!number_present(grid, row, col, i)) {
      total += check_unique(grid, row, col + 1);
      
      // if total solutions is greater than 1, break because multiple solutions
      if (total > 1) {
        grid_set(grid, row, col, 0);
        return total;
      }  
    }
  }

  // reset number at position to 0
  grid_set(grid, row, col, 0);

  return total;

}

/********* find_row ********/
/*
 * finds the row given location on grid (0 - 80)
 */
static int find_row(grid_t grid, int loc)
{
  return (int)(loc / 9);
}

/********** find_col **********/
/*
 * finds the column given location on grid (0 - 80)
 */
static int find_col(grid_t grid, int loc)
{
  return (int)(loc%9);
}

/********** solve_board() **********/
/* see solve.h for more info */
bool solve_board(grid_t grid, int start_pos)
{
  // define varaible to track count of zeros
  int zero = 0;

  // loop over the whole grid
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      if (!grid_get(grid, i, j))
      {
	zero++;
      }
    }
  }

  //Base case
  if (!zero)
    return true;
 
  // given the position, what are the row and col
  int row = find_row(grid, start_pos);
  int col = find_col(grid, start_pos);

  // Ignore the places with numbers
  if (grid_get(grid, row, col))
  {
    // recursive call
    return solve_board(grid, start_pos + 1);
  }

  // assigning number that we are going to put inside grid
  int value = 1;
  grid_set(grid, row, col, value);
	
  // checking conditions
  while (number_present(grid, row, col, value) || !solve_board(grid, start_pos + 1))
  {

     grid_set(grid, row, col, ++value); 
		
     // check value does not exceed 9
     if (value > 9)
     {
	grid_set(grid, row, col, 0);
	return false;
     }
   }

  return true;
}

/********** solver() **********/
/* see solve.h for more info */
int solver(grid_t grid)
{
  // get the number of solutions
  int sol = check_unique(grid, 0, 0);
  solve_board(grid, 0);
  return sol;
}
