#pragma once
#ifndef SUDOKU_PUZZLE_H_
#define SUDOKU_PUZZLE_H_

#include <iostream>
#include <cstdlib>

#define GRID_SIZE 9
#define SQUARE_SIZE 3
#define NUM_VALUES 9
#define EMPTY 0
#define DIFFICULTY 40

class SudokuPuzzle {
	int grid[GRID_SIZE][GRID_SIZE];
public:
	SudokuPuzzle();
	void generatePuzzle();
	int solvePuzzle(bool findAll);
	void getHint(int& row, int& col, int& value);
	int getValue(int row, int col) const;
	void setValue(int row, int col, int value);
};


#endif /*SUDOKU_PUZZLE_H_*/
