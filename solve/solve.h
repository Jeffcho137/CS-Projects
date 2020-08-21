/*
 * solve.h - header file for solve module
 *
 * Team JST CS50 Summer 2020
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../grid/grid.h"

static bool solve_board(grid_t* grid, int pos);

int check_unique(grid_t* grid, int row, int col, int num);

int solver(grid_t* grid);

