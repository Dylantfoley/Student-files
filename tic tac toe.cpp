#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//function protoypes
int minimax(string player, char board[], int & optmin, int depth);
bool gameOver(char board[], int & score);
void printBoard(char board[]);
void initializeBoard(char board[]);

int main()
{
	char board[9];

	initializeBoard(board);

	int finalScore = 0;
	int position;
	int i = 0; //track whose turn it is
	int optmin = 0;

	while (!gameOver(board, finalScore))
	{
		i++;
		if (i % 2 == 0)	//Users turn
		{
			printBoard(board);
			cout << "Enter your position";
			cin >> position;
			board[position] = 'X';
		}
		else   // COMPUTERS Turn
		{
			minimax("min", board, optmin, 0);
			board[optmin] = 'O';
			printBoard(board);
		}
	}


		if (finalScore == 1)
			cout << "you won";
		else if (finalScore == -1)
			cout << "COMPUTER WINS!!";
		else if (finalScore == 0)
			cout << "TIE GAME!!!";
		system("pause");

}


bool gameOver(char board[], int & score)
{
	char winner = '_'; //assuming nobody wins
					   //check for rows
	for (int i = 0; i < 9; i += 3)
	{
		if (board[i] == board[i + 1] && board[i + 1] == board[i + 2])
			winner = board[i];
	}

	//check columns
	for (int i = 0; i<3; i++)
	{
		if (board[i] == board[i + 3] && board[i + 3] == board[i + 6])
			winner = board[i];
	}

	//check diagonally
	if (board[0] == board[4] && board[4] == board[8])
	{
		winner = board[0];
	}
	if (board[2] == board[4] && board[4] == board[6])
	{
		winner = board[2];
	}
			if (winner != '_') //then we have a winner
			{
				if (winner == 'X')
					score = 1; //user won
				else
					score = -1; //Computer won

				return true;
			}
			else //either tie or game is not over
			{
				 //how to check if the game is not over
				for (int i = 0; i<9; i++)
				{
					if (board[i] == '_')
						return false; //game is not over
				}
	//if every block is filled and we still dont have a winner 
	score = 0;//it is a tie
	return true;
			}//game is over with a tie
}

int minimax(string player, char board[], int & optmin, int depth)
{
	//handling base case
	int finalScore;
	if (gameOver(board, finalScore) == true)
		return finalScore;

	int score = 0;
	int maxScore = -2;
	int minScore = 2;

	for (int i = 0; i < 9; i++) //check for candidate moves
	{
		if (board[i] == '_') //if this cell is empty
		{
			if (player == "max")
			{
				board[i] = 'X';
				score = minimax("min", board, optmin, depth + 1);
				board[i] = '_'; //backtracking
				if (score > maxScore)
					maxScore = score;
			}
			else //computer's turn
			{
				board[i] = 'O';
				score = minimax("max", board, optmin, depth + 1);
				board[i] = '_'; //backtracking
				if (score < minScore)
				{
					minScore = score;

					if (depth == 0) //recursion back to where it started
						optmin = i;
				}
			}

		}

	}
	if (player == "max")
		return maxScore;
	else
		return minScore;

}

void printBoard(char board[])
{
	cout << endl;
	cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
	cout << "-----------" << endl;
	cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
	cout << "-----------" << endl;
	cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
	cout << endl;
}

void initializeBoard(char board[])
{
	for (int i = 1; i <= 9; i++)
		board[i - 1] = '_';
	for (int i = 1; i <= 9; i++)
	{
		if (i % 3 == 0)
			cout << i << endl;
		else
			cout << i << " | ";
	}
}
