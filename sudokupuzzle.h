#pragma once
#ifndef SUDOKU_H_
#define SUDOKU_H_

class Sudoku {
	int grid[9][9];
public:
	void SudokuPuzzle();
	void generate();
	bool solve();
	void getHint(int& row, int& col, int& value);
	int getValue(int row, int col) const;
	void setValue(int row, int col, int value);
};


#endif /*SUDOKU_H_*/
