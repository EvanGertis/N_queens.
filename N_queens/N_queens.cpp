// N_queens.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
File : N_queens.cpp
Purpose : contains the main entry point for the N_queens simulation.
Date : 03/11/2018
Author : Evan Gertis
Credit: 
	OneLoneCoder
	https://www.github.com/onelonecoder
	https://www.onelonecoder.com
	https://www.youtube.com/javidx9
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

	//2D camera.
	float fCameraPosX = 0.0f;
	float fCameraPosY = 0.0f;

protected:
	virtual bool OnUserCreate() {
		
		nLevelHeight = this->nLevelHeight;
		nLevelWidth = this->nLevelWidth;

		sLevel = this->sLevel;
		return true;
	}

	virtual bool OnUserUpdate(float fElapsedtime) {
		//Utility lambdas.
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
				return sLevel[y * nLevelWidth + x] = c;
			}
		};

		//Draw level.
		int nTileWidth = 16;
		int nTileHeight = 16;
		int nVisibleTilesX = ScreenWidth() / nTileWidth;
		int nVisibleTilesY = ScreenHeight() / nTileHeight;

		// Calculate Top-Leftmost visible tile.
		float fOffsetX = fCameraPosX - (float)nVisibleTilesX / 2.0f;
		float fOffsetY = fCameraPosY - (float)nVisibleTilesY / 2.0f;

		// Clamp camera to game boundaries.
		if (fOffsetX < 0) fOffsetX = 0;
		if (fOffsetY < 0) fOffsetY = 0;

		if (fOffsetX > nLevelWidth - nVisibleTilesX) fOffsetX = nLevelWidth - nVisibleTilesX;
		if (fOffsetY > nLevelHeight - nVisibleTilesY) fOffsetY = nLevelHeight - nVisibleTilesY;

		// Draw tiles map.
		for (int x = -1; x < nVisibleTilesX + 1; x++)
		{
			for (int y = -1; y < nVisibleTilesY + 1; y++)
			{
				wchar_t sTileID = GetTile(x + fOffsetX, y + fOffsetY);

				//decide what to draw on the tile.
				switch (sTileID)
				{
				case L'.':
					Fill(x * nTileWidth, y * nTileHeight, (x + 1) * nTileWidth, (y + 1) * nTileHeight, PIXEL_SOLID, FG_CYAN);
					break;
				case L'#':
					Fill(x * nTileWidth, y * nTileHeight, (x + 1) * nTileWidth, (y + 1) * nTileHeight, PIXEL_SOLID, FG_RED);
					break;
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
	//Do not set n greater than 8 or less than 4 (there aren't any solutions anyways for 1, 2, 3).
	int n = 4;
	std::wstring chessBoard;

	NQ::NQueens problem{ n };
	chessBoard = problem.solve();

	/*for(int i = 0; i < sizeof(chessBoard)/sizeof(chessBoard[0]); i++)
									std::wprintf(L"%lc ",chessBoard[i]);*/

	OneLoneCoder_Platform game(chessBoard, n, n);
	if (game.ConstructConsole(128, 120, n, n))
		game.Start();

	return 0;

}