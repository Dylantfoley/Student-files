#include "eSpot.h"

//constructor
eSpot::eSpot(int x, int y)
	:ROW(x), COL(y)
{}

void eSpot::computePossibleDigits(int grid[9][9])
{
	for (int digit = 1; digit <= 9; digit++)
	{
		if (validDigit(digit, grid))
			possibleDigits.push_back(digit);

	}
}

bool eSpot::validDigit(int D, int board[9][9])
{
	//check row for digit D
	for (int i = 0; i < 9; i++)
	{
		if (board[ROW][i] == D)
			return false;
		//check column
		if (board[i][COL] == D)
			return false;
	}
	//check "square"
	int x = ROW / 3 * 3;
	int y = COL / 3 * 3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			if (board[x + i][y + j] == D)
				return false;
	}
	return true;
}


vector <int> eSpot::getPossibleDigits()
{
	return possibleDigits;

}

void eSpot::placeDigit(int D, int grid[9][9])
{
	grid[ROW][COL] = D;
}
