/*
 * solve.h - header file for solve module
 *
 * Team JST CS50 Summer 2020
 */ 

#ifndef __SOLVE_H
#define __SOLVE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grid.h"

/********** solve_board() **********/
/*
 * solve_board() - boolean that solves the board and returns whether the board has been solved. Uses the start position to solve the board
 * 
 * Input: the grid (sudoku) to be solved, the starting position (default 0) (from 0 to 80) 
 * 
 * Output: true or false
 * false if grid is not solved
 * true if grid is solved
 * 
 */

bool solve_board(grid_t grid, int start_pos);

/********** check_unique() **********/
/*
 * check_unique() -  returns the number of solutions for the grid
 *
 * Input: grid, the starting row (0), the starting column (0), the starting value of the variable to count number of solutions 
 *
 * Output: 0, 1, or more. Depends on how many solutions. 0 means no solutions, 1 means unique solution, more indicates more than one solution.
 *
 * References: https://stackoverflow.com/questions/24343214/determine-whether-a-sudoku-has-a-unique-solution
 *
 */

int check_unique(grid_t grid, int row, int col, int num);

/********** solver() **********/
/*
 * solver() - solves the board and returns whether the grid is unique
 * 
 * Input: sudoku grid
 * 
 * Output: returns if the paramteter grid is unique
 *
 */

int solver(grid_t grid);

#endif  // __SOLVE_H
