#pragma once

#include <vector>
using std::vector;

/*
class [START]
*/
/**************************************************************************/
/**************************************************************************/
/**************************************************************************/
class NQueens
{
	// matrix for storing queens position.
	vector<vector<int>> chessTable;

public:
	//constructor used to initialize the size of the Queens problem.
	NQueens(int _numOfQueens);
	~NQueens();

	// function that runs the NQueens simulation.
	void solve();

/**************************************************************************/
/**************************************************************************/
/**************************************************************************/

private:
	// initialize the placement of the queens.
	bool setQueens(int _numOfQueens);

	//checks if position is susceptiable to attack.
	bool isPlaceValid(int rowIndex, int colIndex) const;

	//prints out chess board.
	void printQueens() const;
};
/**************************************************************************/
/**************************************************************************/
/**************************************************************************/
/*
class [END]
*/

