/*
 * solvetest.c - implements a test for the solve module
 *
 * Team JST CS50 Summer 2020
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "../common/grid.h"
#include "solve.h"
//#include "create.h"

/*
 * test grid:
 * 0 0 0 3 9 0 0 1 0 
 * 5 0 1 0 0 0 0 4 0
 * 9 0 0 7 0 0 5 0 0 
 * 6 0 2 5 3 0 0 7 0 
 * 0 0 0 0 7 0 0 0 8
 * 7 0 0 8 0 0 9 0 3
 * 8 0 3 0 1 0 0 9 0
 * 0 9 0 2 0 6 0 0 7
 * 4 0 0 0 0 3 0 6 1
 *
 * test grid taken from:
 * https://www.sudokukingdom.com/rules.php
 */

/*
 * test grid: (unique solution) & soluions
 *
 * 2 4 8 3 9 5 7 1 6
 * 5 7 1 6 2 8 3 4 9 
 * 9 3 6 7 4 1 5 8 2 
 * 6 8 2 5 3 9 1 7 4 
 * 3 5 9 1 7 4 6 2 8 
 * 7 1 4 8 6 2 9 5 3 
 * 8 6 3 4 1 7 2 9 5 
 * 1 9 5 2 8 6 4 3 7 
 * 4 2 7 9 5 3 8 6 1 
 *
 */

int main(){
	
	// defining the test grid
	grid_t grid = grid_new();
	grid_set(grid, 0, 3, 3);
	grid_set(grid, 0, 4, 9);
	grid_set(grid, 0, 7, 1);
	grid_set(grid, 1, 0, 5);
	grid_set(grid, 1, 2, 1);
	grid_set(grid, 1, 7, 4);
	grid_set(grid, 2, 0, 9);
	grid_set(grid, 2, 3, 7);
	grid_set(grid, 2, 6, 5);
	grid_set(grid, 3, 0, 6);
	grid_set(grid, 3, 2, 2);
	grid_set(grid, 3, 3, 5);
	grid_set(grid, 3, 4, 3);
	grid_set(grid, 3, 7, 7);
	grid_set(grid, 4, 4, 7);
	grid_set(grid, 4, 8, 8);
	grid_set(grid, 5, 0, 7);
	grid_set(grid, 5, 3, 8);
	grid_set(grid, 5, 6, 9);
	grid_set(grid, 5, 8, 3);
	grid_set(grid, 6, 0, 8);
	grid_set(grid, 6, 2, 3);
	grid_set(grid, 6, 4, 1);
	grid_set(grid, 6, 7, 9);
	grid_set(grid, 7, 1, 9);
	grid_set(grid, 7, 3, 2);
	grid_set(grid, 7, 5, 6);
	grid_set(grid, 7, 8, 7);
	grid_set(grid, 8, 0, 4);
	grid_set(grid, 8, 5, 3);
	grid_set(grid, 8, 7, 6);
	grid_set(grid, 8, 8, 1);

	// print the grid
	grid_print(grid, stdout);

	// testing solve_board
	printf("\n");
	printf("..... testing solve_board .....\n");
	if (solve_board(grid, 0))
	{
		
		printf("Grid solved\n");
 
	}
	else{
		printf("Grid not solved\n");
	}

	// print the resulting grid
	grid_print(grid, stdout);

	// testing solver
	printf("\n");
	printf("..... testing solver .....\n");


	if (solver(grid))
	{
		printf("Unique Grid\n");

	}

	else{
		printf("Not unique grid\n");
	}

	// printing the resulting grid
	grid_print(grid, stdout);	

	// testing check_unique
	printf("\n");
	printf("..... testing check_unique .....\n");
	int solutions = check_unique(grid, 0, 0, 0);

	printf("This grid has %d solution(s) \n", solutions);

	// print the resulting grid
	grid_print(grid, stdout);

	// delete the grid
	grid_delete(grid);

}


