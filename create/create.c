/* 
 * create.c - see create.h for more information
 *
 * team jst, CS50 summer 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../common/grid.h"
// #include "../solve/solve.h"

/**************** local functions ****************/
static void array_shuffle(int nums[], int length);
static void delete_numbers(grid_t *grid, char* difficulty);

/**************** create_puzzle() ****************/
/* see create.h for more information */
grid_t * 
create_puzzle(char *difficulty)
{
  // new grid to be returned
  grid_t *grid = grid_new();
  if (grid == NULL) {
    fprintf(stderr, "Error when creating new grid\n");
    return NULL;
  }

  srand(time(NULL));

  for (int i = 0; i < 9; i++) {
    
    // reset numbers array for each row and shuffle to maintain randomness
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    arrays_shuffle(nums, 9);
    int pos = 0;
    
    for (int x = 0; x < 9; x++) {
      // skip past 0s in nums array
      while (nums[pos] == 0) {
        pos++;
      }

      // set number at the current row/col as the number at current pos of nums
      grid_set(grid, i, x, nums[pos]);
      pos++;

      // check if grid has non-zero solutions, if zero solutions, then try another number
      while (check_unique(grid, 0, 0, 0) != 0) {
        grid_set(grid, i, x, nums[pos]);
	      pos++;
      } 

      // set number used to 0 so that it is not used again
      nums[pos - 1] = 0; 
    }
  }

  if (difficulty == NULL) {
    delete_numbers(grid, "medium");
  
  } else {
    delete_numbers(grid, difficulty);
  }

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
/* depending on user-selected difficulty, delete numbers at random places (default difficulty is medium) */
static void
delete_numbers(grid_t *grid, char *difficulty)
{
  int deletions;

  if (strcmp(difficulty, "easy") == 0) {
    deletions = 30;
 
  } else if (strcmp(difficulty, "hard") == 0) {
    deletions = 60;
 
  } else {
    deletions = 40;
  }

  // randomly select numbers to delete until numbers deleted equals deletions
  while (deletions > 0) {
    int randomRow = rand() % 9;
    int randomCol = rand() % 9;

    int num = grid_get(grid, randomRow, randomCol);
    if (num != 0) {
      grid_set(grid, randomRow, randomCol, 0);

      // set the num at row and col to 0 if there is still a unique solution after doing so
      if (check_unique(grid, 0, 0, 0) == 0) {
        deletions--;
     
      // else set the num back to the original num, but do not count it as a deletion
      } else {
        grid_set(grid, randomRow, randomCol, num);
      }
    }
  }
}

