#include "sudokupuzzle.h"

bool sudokuSolverAux(int grid[GRID_SIZE][GRID_SIZE], int row, int col);


SudokuPuzzle::SudokuPuzzle() {
	// TODO Auto-generated constructor stub
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			grid[i][j] = EMPTY;
		}
	}
}

void SudokuPuzzle::generatePuzzle() {
	// TODO Auto-generated method stub
}

bool SudokuPuzzle::solvePuzzle() {
	return sudokuSolverAux(grid, 0, 0);
}

void SudokuPuzzle::getHint(int& row, int& col, int& value) {
	// TODO Auto-generated method stub
}

int SudokuPuzzle::getValue(int row, int col) const {
	return grid[row][col];
}

void SudokuPuzzle::setValue(int row, int col, int value) {
	// TODO Auto-generated method stub
}


/*
 * checks if the given row already contains a given digit, except for the given column
 * @param grid : the sudoku grid
 * @param row : the row to check
 * @param col : the column of the digit
 * @param digit : the digit to check
 * return true if the row is valid, false otherwise
 */
bool isRowValid(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int digit) {
    for (int i = 0; i < GRID_SIZE; i++)
    {
        if (grid[row][i] == digit && i != col)
        {
            return false;
        }
    }
    return true;
}

/*
 * checks if the given column already contains a given digit, except for the given row
 * @param grid : the sudoku grid
 * @param row : the row of the digit
 * @param col : the column to check
 * @param digit : the digit to check
 * return true if the column is valid, false otherwise
 */
bool isColumnValid(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int digit) {
    for (int i = 0; i < GRID_SIZE; i++)
    {
        if (grid[i][col] == digit && i != row)
        {
            return false;
        }
    }
    return true;
}

/*
 * checks if the square of the given row and column already contains a given digit, except for the given row and column
 * @param grid : the sudoku grid
 * @param row : the row of the digit
 * @param col : the column of the digit
 * @param digit : the digit to check
 * return true if the square is valid, false otherwise
 */
bool isSquareValid(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int digit) {
    int rowStart = row - row % SQUARE_SIZE;
    int colStart = col - col % SQUARE_SIZE;
    for (int i = rowStart; i < rowStart + SQUARE_SIZE; i++)
    {
        for (int j = colStart; j < colStart + SQUARE_SIZE; j++)
        {
            if (grid[i][j] == digit && i != row && j != col)
            {
                return false;
            }
        }
    }
    return true;
}

/*
 * checks you can place the given digit in the given row and column
 * @param grid : the sudoku grid
 * @param row : the row of the digit
 * @param col : the column of the digit
 * @param digit : the digit to check
 * return true if the move is legal, false otherwise
 */
bool isMoveLegal(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int digit) {
    if (!isRowValid(grid, row, col, digit) || !isColumnValid(grid, row, col, digit) || !isSquareValid(grid, row, col, digit))
    {
        return false;
    }
    return true;
}

/*
 * solves the sudoku grid using backtracking algorithm
 * @param grid : the sudoku grid
 * @param row : current row
 * @param col : current column
 */
bool sudokuSolverAux(int grid[GRID_SIZE][GRID_SIZE], int row, int col) {
    if (row == GRID_SIZE - 1 && col == GRID_SIZE)
    {
        return true;
    }
    if (col == GRID_SIZE)
    {
        row++;
        col = 0;
    }
    if (grid[row][col] != 0)
    {
        return sudokuSolverAux(grid, row, col + 1);
    }
    for (int digit = 1; digit <= NUM_VALUES; digit++)
    {
        if (!isMoveLegal(grid, row, col, digit))
        {
            continue;
        }
        grid[row][col] = digit;
        if (sudokuSolverAux(grid, row, col + 1))
        {
            return true;
        }
        grid[row][col] = 0;
    }
    return false;
}