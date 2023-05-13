#pragma once
#ifndef SUDOKU_PUZZLE_H_
#define SUDOKU_PUZZLE_H_

#include <iostream>
#include <cstdlib>

#define GRID_SIZE 9
#define GROUP_SIZE 3
#define SQUARE_SIZE 3
#define NUM_VALUES 9
#define EMPTY 0
#define DIFFICULTY 40

class SudokuPuzzle {
	int grid[GRID_SIZE][GRID_SIZE];
public:
	/*
	* Default constructor
	* Initializes the grid to be empty
	* @param none
	* @return none
	*/
	SudokuPuzzle();

	/*
	* Generates a new sudoku puzzle with a unique solution
	* Remove numbers from a random solved grid according to the difficulty
	* @param none
	* @return 
	*		void
	*/
	void generatePuzzle();

	/*
	* solves the sudoku puzzle
	* @param findAll : if true, finds all solutions to the puzzle
	* @return the number of solutions to the puzzle
	* if findAll is true, returns the number of solutions to the puzzle
	* if findAll is false, returns 1 if the puzzle is solved, 0 otherwise
	*/
	int solvePuzzle(bool findAll);

	/*
	* return the first hint in the puzzle
	* @param row : the row of the hint
	* @param col : the column of the hint
	* @param value : the value of the hint
	* @return
	*		void
	*/
	void getHint(int& row, int& col, int& value);

	/*
	* getter and setter for the grid
	*/
	int getValue(int row, int col) const;
	void setValue(int row, int col, int value);

	/*
	* clears the grid
	* @param none
	* @return
	* 		void
	* 	
	*/
	void clearGrid();

	/*
	* shuffles the grid by swapping rows and columns
	* @param none
	* @return
	* 		void
	*/
	void shuffleGrid();
};


#endif /*SUDOKU_PUZZLE_H_*/
