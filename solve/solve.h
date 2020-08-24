/*
 * solve.h - header file for solve module
 *
 * Team JST CS50 Summer 2020
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grid.h"

/********** solve_board() **********/
/*
 * solve_board() - boolean that solves the board and returns whether the board has been solved. Uses the start position to solve the board
 * 
 * Input: 
 * 
 * Output: 
 * 
 */

static bool solve_board(grid_t grid, pos);

/********** check_unique() **********/
/*
 * check_unique() -  
 *
 * Input: 
 *
 * Output: 
 *
 */

int check_unique(grid_t grid, row, col, num);

/********** solver() **********/
/*
 * solver() - 
 * 
 * Input: 
 * 
 * Output: 
 *
 */

int solver(grid_t, grid);

