#include "Sudoku.h"
#include <fstream>
#include <iostream>
#include <ctime>

using namespace std;

string getPuzzleText(ifstream & infile);

int main()
{

	string puzzleFileName;

	cout << "Enter the puzzle file name: ";
	cin >> puzzleFileName;

	ifstream infile(puzzleFileName);

	if (!infile)
	{
		cout << "Error openiong file. \n" << endl;
		exit(1);
	}

	string puzzle = getPuzzleText(infile);

	//create object 
	Sudo sudokuPuzzle(puzzle);

	//start timer for puzzle
	//clock_t start = clock();
	//sudokuPuzzle.solve(0);

	//stop timer
	//clock_t end = clock();

	int elapsedtime = sudokuPuzzle.solve();

	cout << "The program too " << elapsedtime << " milliseconds to solve the puzzle." << endl;

	system("pause");
		return 0;
}

string getPuzzleText(ifstream & infile)
{
	cout << "reading the puzzle file...... \n";

	string output = "";

	string line;


	while (!infile.eof())
	{
		getline(infile, line);
		output += line + " \n";
	}

	return output;
}