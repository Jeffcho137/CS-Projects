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
#include "solve.h"
//#include <time.h>

/********** check_row **********/
/*
 * checks if a number exists in a row
 */

static bool check_row(grid_t grid, int row, int col, int value)
{
	for (int i = 0; i < 9; i++)
	{
		if (i == col)
			continue;
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
	for (int i = 0; i < 9; i ++)
	{
		if (i == row)
			continue;

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
	int beg_row = (int)(row/3) * 3;
	int beg_col = (int)(col/3) * 3;

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
int check_unique(grid_t grid, int row, int col, int num)
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
		if(!number_present(grid, row, col, i))
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
	

	while (number_present(grid, row, col, value) || !solve_board(grid, start_pos + 1))
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
int solver(grid_t grid)
{
	int sol = check_unique(grid, 0, 0, 0);
	solve_board(grid, 0);
	return sol;
}
