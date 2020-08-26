/* 
 * create.h - header file for create.c
 *
 * create.c creates a sudoku puzzle
 *
 * teamjst CS 50 Summer 2020
 */

#ifndef __CREATE_H
#define __CREATE_H

#include <stdio.h>
#include <stdbool.h>
#include "grid.h"

/**************** create_puzzle() ****************/
/*
 * Caller provides:
 *   string difficulty (can be NULL)
 *
 * Returns:
 *   grid initialized as a valid sudoku puzzle with 45 numbers removed
 *   NULL if error creating grid
 *   caller is responsible for freeing grid
 */   
grid_t *create_puzzle();


#endif  // __CREATE_H
