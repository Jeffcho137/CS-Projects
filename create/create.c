/* 
 * create.c - see create.h for more information
 *
 * team jst, CS50 summer 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "create.h"
#include "grid.h"
#include "solve.h"

/**************** local functions ****************/
static void array_shuffle(int nums[], int length);
static void delete_numbers(grid_t grid);


/**************** create_puzzle() ****************/
/* see create.h for more information */
grid_t 
create_puzzle()
{
  // new grid to be returned
  grid_t grid = grid_new();
  if (grid == NULL) {
    fprintf(stderr, "Error when creating new grid\n");
    return NULL;
  }

  srand(time(NULL));

  // first fill in three matrices in left diagonal
  for (int i = 0; i < 9; i+=3) {
    
    for (int row = i; row < i + 3; row++) {
      // reset numbers array for each row and shuffle to maintain randomness
      int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
      array_shuffle(nums, 9);
      int pos = 0;

      for (int col = i; col < i + 3; col++) {
        // skip past 0s in nums array
        while (nums[pos] == 0) {
          pos = ((pos + 1) % 9);
        }

        // set number at the current row/col as the number at current pos of nums
        grid_set(grid, row, col, nums[pos]);
        pos = ((pos + 1) % 9);
     
        // check if grid has non-zero solutions, if zero solutions, then try another number
        while (!valid_num(grid, row, col)) {
	  // skip over zeros in array
	  while (nums[pos] == 0) {
            pos = ((pos + 1) % 9);
          }

          grid_set(grid, row, col, nums[pos]);
	  pos = ((pos + 1) % 9);
        }
     
        // set number to zero so it is not used again
        if (pos == 0) {
          nums[8] = 0;
        } else {
          nums[pos - 1] = 0;
        } 
      } 
    }
  }
   
  // after filling in diagonal, fill in remaining cells
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
       // continue if already number at the position
       if (grid_get(grid, row, col) != 0) { 
         continue;
       }

       // try each number at the position
       for (int i = 1; i <= 9; i++) {
         grid_set(grid, row, col, i);
     
	 // if valid, then break
         if (valid_num(grid, row, col) && check_unique(grid, 0, 0, 0) != 0) {
           break;
         }
       }
    } 
  }
  
  delete_numbers(grid);

  return grid;
}


/**************** array_shuffle() ****************/
/* takes an int array and int length and shuffles the array */
static void
array_shuffle(int nums[], int length)
{
  // swap each array element with a random element
  for (int i = 0; i < length; i++) {
    int randomPos = rand() % 9;
    
    int temp = nums[i];
    nums[i] = nums[randomPos];
    nums[randomPos] = temp;

  }
}


/**************** delete_numbers() ****************/
/* deletes 45 numbers from grid */
static void
delete_numbers(grid_t grid)
{
  int deletions = 45;

  // randomly select numbers to delete until numbers deleted equals deletions
  while (deletions > 0) {
    int randomRow = rand() % 9;
    int randomCol = rand() % 9;

    int num = grid_get(grid, randomRow, randomCol);
    if (num != 0) {
      grid_set(grid, randomRow, randomCol, 0);

      // set the num at row and col to 0 if there is still a unique solution after doing so
      if (check_unique(grid, 0, 0, 0) == 1) {
        deletions--;
     
      // else set the num back to the original num, but do not count it as a deletion
      } else {
        grid_set(grid, randomRow, randomCol, num);
      }
    }
  }
}


