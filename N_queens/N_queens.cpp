// N_queens.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
File : N_queens.cpp
Purpose : contains the main entry point for the N_queens simulation.
Date : 03/11/2018
Author : Evan Gertis
*/


#include "pch.h"
#include <iostream>

int main()
{
	NQueens problem{ 8 };
	problem.solve();
}