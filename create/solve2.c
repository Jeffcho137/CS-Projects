int check_unique(grid_t grid, int row, int col)
{
  if (row == 9) {
    return 1;
  }

  if (col == 9) {
    return check_unique(grid, row + 1, 0, s);
  }

  if (grid_get(grid, row, col) != 0) {
    return check_unique(grid, row, col + 1, s);
  }



  int total = 0;
  for (int i = 1; i <= 9; i++) {
    grid_set(grid, row, col, i);

    if (valid_num(grid, row, col)) {
      total += check_unique(grid, row, col + 1, s);
      if (total > 1) {
        grid_set(grid, row, col, 0);
        return total;
      }  
    }
  }

  grid_set(grid, row, col, 0);

  return total;

}

