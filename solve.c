/*
 * solve.c - implementation for header solve.h
 *
 *
 */ 

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <grid.h>
//#include <time.h>

int check_unique(grid_t *grid, int row, int col, int num)
{
// i = row
// j = col
	if (col == 9)
	{
		col = 0;
		if (++row == 9)
			return num + 1;
	}

	if (b->grid[row][col] != 0)
		return check_unique(grid, row, col + 1, num);
	
	for (int i = 1; i <= 9 && num < 2; ++i)
	{
		if(!check_num(grid, row, col, i))
		{
			b->grid[row][col] = i;
			num = check_unique(grid, row, col + 1, num);
		}
	}

	b->grid[row][col] = 0;
	return num;

}

static bool check_num(grid_t *grid, int row, int col, int value)
{
	if (check_row(grid, row, col, value))
		return true;
	if (check_col(grid, row, col, value))
		return true;
	if (check_grid(grid, row, col, value))
		return true;
	return false;	
}

static bool check_row(grid_t *grid, int row, int col, int value)
{
	for (int i = 0; i < 9; i++)
	{
		if (i == col)
			continue;
		if (b->grid[row][i] == value)
		{
			return true;
		}
	}
	return false;
}

static bool check_col(grid_t *grid, int row, int col, int value)
{
	for (int i = 0; i < 9; i++)
	{
		if (i == row)
			continue;
		if (b->grid[i][col] == value)
			return true;
	}
	return false;
}

static bool check_grid(grid_t *grid, int row, int col, int value)
{
	// assign the beginning row and column positions
	int beg_row = (int)(row/3) * 3; 
	int beg_col = (int)(col/3) * 3;

	for (int i = beg_row; i < beg_row + 3; i++)
	{
		for (int j = beg_col; j < beg_col + 3; j++)
		{
			if (j == col && i == row)
			{
				continue;
			}

			if (b->grid[i][j] == value)
				return true;
		}
	}

	return false;

}

static int find_row(grid_t *grid, int loc)
{
	return (int)(loc / 9);
}

static int find_col(grid_t *grid, int loc)
{
	return (int)(loc%9);
}

static bool solve_board(grid_t *grid, int start_pos)
{
	int zero = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (!b->grid[i][j])
			{
				zero++;
			}
		}
	}

	//Base case
	if (!zeros)
		return true;

	int row = find_row(grid, start_pos);
	int col = find_col(grid, start_pos);

	// Ignore the places with numbers
	if (b->grid[row][col])
	{
		return solve_board(grid, start_pos + 1);
	}

	int value = 1;
	b->grid[r][c] = value;

	while (check_num(grid, row, col, value) || !solve_board(grid, start_pos + 1))
	{
		b->grid[row][col] = ++value;

		if (value > 9)
		{
			b->grid[row][col] = 0;
			return false;
		}
	}

	return true;
}

int solver(grid_t *grid)
{
	int sol = check_unique(grid, 0, 0, 0);
	solve_board(grid, 0);
	return int sol;
}
