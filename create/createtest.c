/* 
 * createtest.c - test program for create
 *
 * usage: ./createtest
 * 
 * Team JST CS50, Summer 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "create.h"
#include "solve.h"

/* **************************************** */
int main() 
{ 
 // create puzzle
 printf("creating new puzzle\n");
 grid_t grid = create_puzzle(0);

 // check whether the puzzle is valid
 bool valid = valid_grid(grid);
 
 if (valid) {
   printf("puzzle is valid\n");
 } else {
   printf("puzzle is not valid\n");
 }

 // check whether the puzzle has a unique solution
 if (check_unique(grid, 0, 0) == 1) {  
   printf("puzzle has a unique solution\n");
 } else {
   printf("puzzle does not have a unique solution\n");
 }

 // print the puzzle
 printf("printing the puzzle\n\n");
 grid_print(grid, stdout);

 // delete the puzzle
 grid_delete(grid);

}
