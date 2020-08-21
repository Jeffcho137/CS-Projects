/*
 * solve.h - header file for solve module
 *
 * Team JST CS50 Summer 2020
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grid.h"

static bool solve_board(grid_t grid, pos);

int check_unique(grid_t grid, row, col, num);

int solver(grid_t, grid);

