#pragma once
#include "pch.h"



NQ::NQueens::NQueens(int _numOfQueens) : numOfQueens(_numOfQueens)
{
	chessTable.resize(numOfQueens);
	
	// create 2D array with as many rows and columns as the number of queens.
	for (auto &chessRow : chessTable) {
		chessRow.resize(numOfQueens);
	}

}

NQ::NQueens::~NQueens()
{
}

std::wstring NQ::NQueens::solve()
{	
	std::wstring board;

	//solve the problem starting with the first column (0).
	if (setQueens(0)) {
		return printQueens();
	}
	else {
		printf("There is no solution..\n");
		return L" ";
	}
}

bool NQ::NQueens::setQueens(int colIndex)
{
	//if we have considered as many queens as the number of rows/columns the we are done.
	if (colIndex == numOfQueens) {
		return true;
	}

	//consider all the rows in a single column to check where to put the queen.
	for (int rowIndex = 0; rowIndex < numOfQueens; rowIndex++)
	{	
		// chek if the given location is valid (queen cannot attack another queen)
		if (isPlaceValid(rowIndex, colIndex)) {

			// valid place so put a queen at this location.
			chessTable[rowIndex][colIndex] = 1;

			//check the next queen (next column) (every column has one queen)
			// we manage to put a queen in the next column -> return true.
			if (setQueens(colIndex + 1)) {
				return true;
			}

			//we failed to put a given queen in a given column: backtracking.
			//1: denotes a queen and 0: is an empty spac so we reinitialize the location.
			//keep iterating and consider the next row.
			chessTable[rowIndex][colIndex] = 0;
		}
	}

	//we have considered all the rows with out any result which means there is no solution.
	//we are not able to put the queens such that they can not attack each other.
	//we backtrack.
	return false;
}

bool NQ::NQueens::isPlaceValid(int rowIndex, int colIndex) const
{
	//there can not be another queen in the same row: they would be able to attack each other.
	for (int i = 0; i < colIndex; i++)
	{
		if (chessTable[rowIndex][i] == 1) {
			return false;
		}
	}

	// there is a queen in the diagonal (top left to bottom right direction)
	for (int i = rowIndex, j = colIndex; i >= 0 && j >=  0; i--, j--)
	{
		if (chessTable[i][j] == 1) {
			return false;
		}
	}

	// there is a queen in the diagonal (top right to bottom left direction)
	for (int i = rowIndex, j = colIndex; i < numOfQueens && j >= 0; i++, j--)
	{
		if (chessTable[i][j] == 1) {
			return false;
		}
	}

	return true;
}

std::wstring NQ::NQueens::printQueens() const
{
	std::wstring board;

	//there is a queen where the table contains a 1 else there are no queens (0 value)
	//* represents the queens and - is an empty state.
	for (size_t i = 0; i < chessTable.size(); i++)
	{
		for (size_t j = 0; j < chessTable.size(); j++)
		{
			if (chessTable[i][j] == 1) {
				board += L"#";
			}
			else {
				board += L".";
			}
		}
	}

	return board;
}
