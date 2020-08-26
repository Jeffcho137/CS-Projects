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
#include "create.h"
#include "grid.h"
#include "solve.h"

/* **************************************** */
int main() 
{
 // create puzzle
 printf("creating new puzzle\n");
 grid_t *grid = create_puzzle();

 // check whether the puzzle is valid
 bool valid = valid_grid(grid);
 
 if (valid) {
   printf("puzzle is valid\n");
 } else {
   printf("puzzle is not valid\n");
 }

 // check whether the puzzle has a unique solution
 int unique = check_unique(grid, 0, 0, 0);
 
 if (unique == 0) {  
   printf("puzzle has a unique solution\n");
 } else {
   printf("puzzle does not have a unique solution\n");
 }

 // print the puzzle
 printf("\nprinting the puzzle\n\n");
 grid_print(grid, stdout);


 
 
 // repeat with another puzzle
 printf("repeating process with another puzzle\n");
 grid_delete(grid);

 // create puzzle
 printf("creating new puzzle\n");
 grid = create_puzzle();

 // check whether the puzzle is valid
 valid = valid_grid(grid);

 if (valid) {
   printf("puzzle is valid\n");
 } else {
   printf("puzzle is not valid\n");
 }

 // check whether the puzzle has a unique solution
 unique = check_unique(grid, 0, 0, 0);

 if (unique == 0) {
   printf("puzzle has a unique solution\n");
 } else {
   printf("puzzle does not have a unique solution\n");
 }

 // print the puzzle
 printf("\nprinting the puzzle\n\n");
 grid_print(grid, stdout);
}
