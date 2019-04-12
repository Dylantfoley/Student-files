#include "Sudoku.h"
#include <sstream> 
#include <iostream>
#include <ctime>

Sudo::Sudo(const string & PUZZLE)
{
	stringstream str(PUZZLE);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			str >> board[i][j]; // extract a value and put it in a spot on the board
				if(board[i][j] == 0) // if value = 0, add to blank spots
				{
					eSpot newSpot(i, j);
					blankSpots.push_back(newSpot);
				}
		}
	}
	//for each epty spot, compute it's candidate digits
	cout << "The original board is:  " << endl;
	printPanel();
	cout << "There are " << blankSpots.size() << "blank spots" << endl;

	for (int i = 0; i < blankSpots.size(); i++)
	{
		blankSpots[i].computePossibleDigits(board);
		
		/* sort blank spots from most contrainted(less candidate digits) 
		to least constraints(most condidate degits) */
	}
}

//recursive backtracking
void Sudo::solve(int N)
{
	//base case
	if (N == blankSpots.size())
	{
		cout << "Solution has been found. \n";
		//found solution
		printPanel();
		return;
	}

	vector<int> myDigits = blankSpots[N].getPossibleDigits();
	//recursive case
	for (int i = 0; i < myDigits.size(); i++)
	{
		if (blankSpots[N].validDigit(myDigits[i], board) == true)
		{
			blankSpots[N].placeDigit(myDigits[i], board);
			solve(N + 1);// next blank spot
			blankSpots[N].placeDigit(0, board); //backtracking
		}
	}
}

int Sudo::solve()
{
	clock_t start = clock();

	solve(0);

	clock_t end = clock();

	return (end - start) * 1000 / CLOCKS_PER_SEC;
}

void Sudo::printPanel()
{
	for (int ROW = 0; ROW < 9; ROW++)
	{
		for (int COL = 0; COL < 9; COL++)
		{
			cout << board[ROW][COL] << " ";
		}
		cout << endl;
	}
}