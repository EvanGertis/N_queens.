#pragma once

#include "pch.h"
#include <vector>

/*
class [START]
*/
/**************************************************************************/
/**************************************************************************/
/**************************************************************************/
namespace NQ {
	class NQueens
	{
		// matrix for storing queens position.
		std::vector<std::vector<int>> chessTable;

		// reset the number of queens.
		int numOfQueens = 0;

	public:
		//constructor used to initialize the size of the Queens problem.
		NQueens(int _numOfQueens);
		~NQueens();

		// function that runs the NQueens simulation.
		std::wstring solve();

		/**************************************************************************/
		/**************************************************************************/
		/**************************************************************************/

	private:
		// initialize the placement of the queens.
		bool setQueens(int colIndex);

		//checks if position is susceptiable to attack.
		bool isPlaceValid(int rowIndex, int colIndex) const;

		//prints out chess board.
		std::wstring printQueens() const;
	};
	/**************************************************************************/
	/**************************************************************************/
	/**************************************************************************/
	/*
	class [END]
	*/
}
