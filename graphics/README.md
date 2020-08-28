# Graphics Module
# TEAM JST CS50 Summer 2020

## How it works

Graphics takes in a file as input and animates it using the provided cs1lib.py file. The animation is done in Python. Here are the steps to use and animate the sudoku

## Creating the Input File

1. For graphics to work, `input.txt` and `output.txt` files are needed.
2. They can be created through compilation of create in the sudoku directory
3. To create input.txt and output.txt all one needs to do is `make test` in the sudoku directory
4. This automatically creates `input.txt` (randomly created sudoku) and the `output.txt` (solved sudoku) and moves them into the graphics directory.

## Using the Output File

1. From there the `output.txt` file needs to be copied (either the content) or the file into the directory where `sudoku.py` exists, so it can take in `output.txt` as the input.
2. `sudoku.py` takes in the output.txt file and animates it using cs1lib. 

## Pseudocode
1. The program takes in the output.txt file.
2. It creates an empty 2-d array and initializes it with all zeros.
3. The program goes through the output.txt file and reads in the solved sudoku values.
4. It then updates each cell with the solved sudoku values.
5. Start graphics then runs and animates the solved sudoku.

# Functions

* `draw_grid(file)`
* `main()`
* `start_graphics(main, width, height, title)`
