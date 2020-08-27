# TEAM JST CS50 Summer 2020
# Sudoku animation graphics
#
# animates the solved sudoku board with the solution
# utilizes cs1 library

from cs1lib import *

# constants
width = 720
height = 800

# output file from directory in graphics
s_file = "output.txt"

# draws the sudoku given a file
def draw_grid(file):

    # define the 2-d array of 0s to be updated
    grid_array = [["0","0","0","0","0","0","0","0","0"],
                  ["0","0","0","0","0","0","0","0","0"],
                  ["0","0","0","0","0","0","0","0","0"],
                  ["0","0","0","0","0","0","0","0","0"],
                  ["0","0","0","0","0","0","0","0","0"],
                  ["0","0","0","0","0","0","0","0","0"],
                  ["0","0","0","0","0","0","0","0","0"],
                  ["0","0","0","0","0","0","0","0","0"],
                  ["0","0","0","0","0","0","0","0","0"]]

    # takes in an output file provided by user
    grid = open(file, "r")
    line = grid.readline()
    col = 0
    row = 0

    # updating the values in the array
    while line != "":
        for value in line.split():
            grid_array[row][col] = value
            row += 1

            if row == 9:
                row = 0
                col += 1

        line = grid.readline()

    i = 0
    set_font_size(15)

    # go through each row and column
    while i < 9:
        j = 0
        while j < 9:

            # filling in the values
            draw_text(grid_array[i][j], (i*80 + 30), (j*80 + 60))
            j += 1
        i += 1
    grid.close()


def main():

    # setting a purple background
    set_clear_color(1, 0, 1)
    clear()

    # drawing the lines & borders
    x = width - 80
    while x > 0:
        set_stroke_width(1)
        if x == 240 or x == 480:  # thick lines for boxes
            set_stroke_width(3)
        draw_line(x, height - 80, x, 0)
        draw_line(width, x, 0, x)
        x -= 80

    draw_grid(s_file)

start_graphics(main, width=width, height=height, title="Sudoku Animated")