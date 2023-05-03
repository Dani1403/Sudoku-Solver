#include "sudokupuzzle.h"

int sudokuSolverAux(int grid[GRID_SIZE][GRID_SIZE], int row, int col, bool findAll);

SudokuPuzzle::SudokuPuzzle() {
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			grid[i][j] = EMPTY;
		}
	}
}

void SudokuPuzzle::shuffleGrid() {
    for (int group = 0; group < GROUP_SIZE; group++) {
        int startRow = group * GROUP_SIZE;
        int endRow = startRow + GROUP_SIZE - 1;
        for (int i = 0; i < GRID_SIZE; i++) {
			int row1 = rand() % (endRow - startRow + 1) + startRow;
			int row2 = rand() % (endRow - startRow + 1) + startRow;
            for (int col = 0; col < GRID_SIZE; col++) {
				int temp = grid[row1][col];
				grid[row1][col] = grid[row2][col];
				grid[row2][col] = temp;
			}
		}
    }
    for (int group = 0; group < GROUP_SIZE; group++) {
		int startCol = group * GROUP_SIZE;
		int endCol = startCol + GROUP_SIZE - 1;
        for (int i = 0; i < GRID_SIZE; i++) {
            int col1 = rand() % (endCol - startCol + 1) + startCol;
            int col2 = rand() % (endCol - startCol + 1) + startCol;
            for (int row = 0; row < GRID_SIZE; row++) {
                int temp = grid[row][col1];
                grid[row][col1] = grid[row][col2];
                grid[row][col2] = temp;
            }
        }
    }
}

void SudokuPuzzle::generatePuzzle() {
    this->clearGrid();
    this->solvePuzzle(false);
    int numSquares = DIFFICULTY;
    while (numSquares > 0)
    {
		int row = rand() % GRID_SIZE;
		int col = rand() % GRID_SIZE;
        int value = this->getValue(row, col);
        if (value != EMPTY)
        {
			this->setValue(row, col, EMPTY);
            if (this->solvePuzzle(true) != 1) 
            {
                this->setValue(row, col, value);
                numSquares++;
            }
			numSquares--;
		}
	}
}


int SudokuPuzzle::solvePuzzle(bool findAll) {
	return sudokuSolverAux(grid, 0, 0, findAll);
}

void SudokuPuzzle::getHint(int& row, int& col, int& value) {
	// TODO Auto-generated method stub
}

int SudokuPuzzle::getValue(int row, int col) const {
	return grid[row][col];
}

void SudokuPuzzle::setValue(int row, int col, int value) {
    grid[row][col] = value;
}

void SudokuPuzzle::clearGrid() {
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
			grid[i][j] = EMPTY;
		}
	}
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
 * returns the number of solutions
 */
int sudokuSolverAux(int grid[GRID_SIZE][GRID_SIZE], int row, int col, bool findAll)
{
    if (row == GRID_SIZE)
    {
        return 1;
    }
    if (col == GRID_SIZE)
    {
        return sudokuSolverAux(grid, row + 1, 0, findAll);
    }
    if (grid[row][col] != 0)
    {
        return sudokuSolverAux(grid, row, col + 1, findAll);
    }
    int counter = 0;
    for (int digit = 1; digit <= NUM_VALUES; digit++)
    {
        if (isMoveLegal(grid, row, col, digit))
        {
            grid[row][col] = digit;
            if (findAll)
            {
                counter += sudokuSolverAux(grid, row, col + 1, true);
            }
            else if (sudokuSolverAux(grid, row, col + 1, false) == 1)
            {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return findAll ? counter : 0;
}