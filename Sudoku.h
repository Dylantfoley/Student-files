#pragma once
#ifndef sudoku_h
#define sudoku_h

#include "eSpot.h"
#include <string>

class Sudo
{
public:
	Sudo(const string & PUZZLE);

	//recursive backtracking search - similar to nQueens
	void solve(int V);

	void printPanel();

	int solve();


private:
	int board[9][9];
	vector <eSpot> blankSpots;
};

#endif