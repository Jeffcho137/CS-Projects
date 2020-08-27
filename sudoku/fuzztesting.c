/* 
 * fuzztesting.c - generates n puzzles, checks if solution is valid, and checks if unique solution
 *
 * usage: ./fuzztesting n
 * 
 * Team JST CS50, Summer 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "create.h"
#include "grid.h"
#include "solve.h"

/**************** main() ****************/
int main(const int argc, char *argv[])
{
  // check if number of command line arguments equals 2
  if (argc != 2) {
    fprintf(stderr, "Invalid number of arguments. Usage: ./fuzztesting n\n");
    return 1;
  }

  // check if n is an integer and greater than 0
  int n;
  char extra;
  if (sscanf(argv[1], "%d%c",&n, &extra) != 1) {
    fprintf(stderr, "Please provide n as an integer\n");
    return 2;
  }

  // check if n is greater than 0
  if (n < 1) {
    fprintf(stderr, "n must be greater than 0\n");
    return 3;
  }

  // generate n puzzles, checks if each puzzle is valid, and checks if unique solution
  int invalid = 0;
  int notUnique = 0;
  
  for (int i = 1; i <= n; i++) {
    // generate puzzle
    grid_t grid = create_puzzle(i);
    printf("creating puzzle %d\n", i);
    
    // check for valid puzzle
    if (valid_grid(grid)) {
      printf("puzzle %d is valid\n", i);
    } else {
      printf("puzzle %d is invalid\n", i);
      invalid++;
    }

    // check for unique solution
    if (check_unique(grid, 0, 0, 0) == 1) {
      printf("puzzle %d has a unique solution\n", i);
    } else {
      printf("puzzle %d does not have a unique solution\n", i);
      notUnique++;
    }

    // printing puzzle
    printf("printing puzzle %d\n", i);
    grid_print(grid,stdout);
    printf("\n--------------------------------------------------------------\n");

    grid_delete(grid);

  }


  printf("\nOut of %d puzzles, %d were invalid and %d were not unique\n", n, invalid, notUnique);

  return 0;


}
