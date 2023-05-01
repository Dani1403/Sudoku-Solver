#include "sudokupuzzle.h"

SudokuPuzzle::SudokuPuzzle() {
	// TODO Auto-generated constructor stub
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			grid[i][j] = 0;
		}
	}
}


void SudokuPuzzle::generatePuzzle() {
	// TODO Auto-generated method stub
}

bool SudokuPuzzle::solvePuzzle() {
	// TODO Auto-generated method stub
	return false;
}

void SudokuPuzzle::getHint(int& row, int& col, int& value) {
	// TODO Auto-generated method stub
}

int SudokuPuzzle::getValue(int row, int col) const {
	// TODO Auto-generated method stub
	return grid[row][col];
}

void SudokuPuzzle::setValue(int row, int col, int value) {
	// TODO Auto-generated method stub
}

