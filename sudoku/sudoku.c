/*
 * sudoku.c - A program to create and solve sudoku puzzles.
 *
 * usage: './sudoku create' or './sudoku solve'
 * 
 * input: takes command-line parameters (see usage above) and reads input
 * 		  sudoku puzzles to solve from stdin
 * output: outputs the created/solved sudoku puzzle to stdout
 * 
 * teamJST, CS 50
 * August 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../common/grid.h"
#include "../create/create.h"
#include "../solve/solve.h"

int main(const int argc, char *argv[])
{
  char* program = argv[0];  // program name

  // check that there is 1 arguments
  if (argc != 2) {
    fprintf(stderr, "usage: '%s create' or '%s solve'\n", program, program);
    return 1; 
  }

  // check that the parameter is either 'create' or 'solve'
  char* command = argv[1];
  if ((strcmp(command, "create") != 0) && (strcmp(command, "solve") != 0)) {
     fprintf(stderr, "usage: '%s create' or '%s solve'\n", program, program);
     return 2;
  }

  // create sudoku puzzle
  if (strcmp(command, "create") == 0) {
     grid_t grid = create_puzzle();
     grid_print(grid, stdout);
     grid_delete(grid);
  }

  // get sudoku puzzle and solve it
  if (strcmp(command, "create") == 0) {
    grid_t grid = load_grid(stdin);
    solver(grid);
    grid_print(grid, stdout);
    grid_delete(grid);
  }

  return 0;
}
