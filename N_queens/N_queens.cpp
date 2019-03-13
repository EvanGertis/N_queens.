// N_queens.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
File : N_queens.cpp
Purpose : contains the main entry point for the N_queens simulation.
Date : 03/11/2018
Author : Evan Gertis
*/


#include "pch.h"
#include "olcGameEngine.h"


class OneLoneCoder_Platform : public olcConsoleGameEngine
{
public:
	OneLoneCoder_Platform(std::wstring board, int boardWidth, int boardHeight) {
		m_sAppName = L"N_queens simulation";
		this->sLevel = board;
		this->nLevelHeight = boardHeight;
		this->nLevelWidth = boardWidth;
	}
private:
	std::wstring sLevel;

	//game tile dimensions.
	int nLevelWidth;
	int nLevelHeight;

protected:
	virtual bool OnUserCreate() {

		nLevelHeight = this->nLevelHeight;
		nLevelWidth = this->nLevelWidth;

		sLevel = this->sLevel;
		return true;
	}

	virtual bool OnUserUpdate(float fElapsedTime) {
		auto GetTile = [&](int x, int y) {
			if (x >= 0 && x < nLevelWidth && y >= 0 && y < nLevelHeight) {
				return sLevel[y * nLevelWidth + x];
			}
			else {
				return L' ';
			}
		};

		auto SetTile = [&](int x, int y, wchar_t c) {
			if (x >= 0 && x < nLevelWidth && y >= 0 && y < nLevelHeight) {
				return sLevel[y*nLevelWidth + x] = c;
			}
		};

		//Draw board.
		int nVisibleTilesX = ScreenWidth();
		int nVisibleTilesY = ScreenHeight();
		int nTileWidth = 16;
		int nTileHeight = 16;

		//Draw tiles map.
		for (int x = -1; x < nVisibleTilesX + 1; x++)
		{
			for (int y = -1; y < nVisibleTilesY + 1; y++) {
				wchar_t sTileID = GetTile(x, y);

				switch (sTileID)
				{
				case L'-':
					Fill(x*nTileWidth, y*nTileHeight, (x + 1) * nTileWidth, (y + 1) * nTileHeight, PIXEL_SOLID, FG_CYAN);
				case L'*':
					Fill(x*nTileWidth, y*nTileHeight, (x + 1) * nTileWidth, (y + 1) * nTileHeight, PIXEL_SOLID, FG_CYAN);
				default:
					break;
				}
			}
		}

		return true;
	}

	

};

int main()
{
	int n = 7;
	std::wstring chessBoard;

	NQ::NQueens problem{ n };
	chessBoard = problem.solve();

	OneLoneCoder_Platform game(chessBoard, n, n);
	if (game.ConstructConsole(160, 120, n, n))
		game.Start();

	return 0;

}