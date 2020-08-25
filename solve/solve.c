/*
 * solve.c - implementation for header solve.h
 *
 * Team JST CS50 Summer 2020
 */ 

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//#include "grid.h"
#include "../common/grid.h"
//#include <time.h>

/********** check_unique() **********/
/* see solve.h for more info */
int check_unique(grid_t *grid, int row, int col, int num)
{

	if (col == 9)
	{
		col = 0;
		if (++row == 9)
			return num + 1;
	}

	if (grid_get(grid, row, col) != 0)
		return check_unique(grid, row, col + 1, num);
	
	for (int i = 1; i <= 9 && num < 2; ++i)
	{
		if(!valid_num(grid, row, col))
		{
			grid_set(grid, row, col, i);
			num = check_unique(grid, row, col + 1, num);
		}
	}

	grid_set(grid, row, col, 0);
	return num;

}

/********** find_row **********/
/*
 * finds the row given location on grid (0 - 80)
 */
static int find_row(grid_t *grid, int loc)
{
	return (int)(loc / 9);
}

/********** find_col **********/
/*
 * finds the column given location on grid (0 - 80)
 */
static int find_col(grid_t *grid, int loc)
{
	return (int)(loc%9);
}

/********** solve_board() **********/
/* see solve.h for more info */
static bool solve_board(grid_t *grid, int start_pos)
{
	int zero = 0;
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

	int row = find_row(grid, start_pos);
	int col = find_col(grid, start_pos);

	// Ignore the places with numbers
	if (grid_get(grid, row, col))
	{
		return solve_board(grid, start_pos + 1);
	}

	int value = 1;
	

	while (valid_num(grid, row, col) || !solve_board(grid, start_pos + 1))
	{
		grid_set(grid, row, col, ++value); 
		//b->grid[row][col] = ++value;

		if (value > 9)
		{
			grid_set(grid, row, col, 0);
			//b->grid[row][col] = 0;
			return false;
		}
	}

	return true;
}

/********** solver() **********/
/* see solve.h for more info */
int solver(grid_t *grid)
{
	int sol = check_unique(grid, 0, 0, 0);
	solve_board(grid, 0);
	return sol;
}
