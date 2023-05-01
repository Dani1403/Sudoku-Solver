#pragma once
#ifndef SUDOKU_PUZZLE_H_
#define SUDOKU_PUZZLE_H_
#define GRID_SIZE 9
class SudokuPuzzle {
	int grid[GRID_SIZE][GRID_SIZE];
public:
	SudokuPuzzle();
	void generatePuzzle();
	bool solvePuzzle();
	void getHint(int& row, int& col, int& value);
	int getValue(int row, int col) const;
	void setValue(int row, int col, int value);
};


#endif /*SUDOKU_PUZZLE_H_*/
