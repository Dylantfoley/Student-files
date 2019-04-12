#ifndef eSpot_H
#define eSPOT_H
#include <vector>

using namespace std;

class eSpot
{
public:
	eSpot(int x = 0, int y = 0);

	bool validDigit(int D, int board[9][9]); // D = digit, board = grid

	vector <int> getPossibleDigits();

	void computePossibleDigits(int board[9][9]);

	void placeDigit(int D, int board[9][9]);

private:
	int ROW;
	int COL;
	vector <int> possibleDigits;
};

#endif eSPot_H