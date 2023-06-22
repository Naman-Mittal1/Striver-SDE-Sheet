bool isValid(int grid[9][9], int num, int row, int col) {
    // if num already exists in the current row
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num) {
            return false;
        }
    }

    // if num already exists in the current column
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == num) {
            return false;
        }
    }

    // if num already exists in the current 3x3 subgrid
    int startRow = 3 * (row / 3);
    int startCol = 3 * (col / 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool findEmptyCell(int grid[9][9], int& row, int& col) {
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku(int grid[9][9]) {
    int row, col;
    if (!findEmptyCell(grid, row, col)) {
        // No empty cell remaining, puzzle solved
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, num, row, col)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) {
                return true;
            }
            grid[row][col] = 0; // Backtrack
        }
    }

    return false;
}

bool isItSudoku(int matrix[9][9]) {
    int grid[9][9];

    // Copy the matrix into the grid
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            grid[i][j] = matrix[i][j];
        }
    }

    return solveSudoku(grid);
}
