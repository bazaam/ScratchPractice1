#include "GameManager.h"



GameManager::GameManager()
{
	selection = 0;
	player = 0;
	valid = false;
	tieGame = true;

}


GameManager::~GameManager()
{
}

int GameManager::StartTurn() 
{
	PrintBoard();

	while (!valid) 
	{
		std::cout << std::endl << "Player " << player + 1 << ", pick a square (1 - 9): ";
		std::cin >> selection;
		if (std::cin.fail()) 
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			std::cout << "Please pick a number from 1 to 9!!" << std::endl;
		}
		else if ((selection < 1) | (selection > 9)) // https://codeburst.io/software-anti-patterns-magic-numbers-7bc484f40544
		{
			std::cout << "Please pick a number from 1 to 9!!" << std::endl;
		}
		else if (cellLock[selection - 1])
		{
			std::cout << "That cell has been selected already!!" << std::endl;
		}
		else
		{
			board[selection - 1] = player + 1;
			cellLock[selection - 1] = true;
			valid = true;
		}
	}
	player = 1 - player;
	valid = false;
	return 0;
	
}

void GameManager::PrintBoard() 
{
	// Define LINE_COUNT somewhere, either #define or "static const"
	// Define CELLS_PER_LINE 
	// for ( line = 0; line < LINECOUNT; ++line)
	std::cout << std::endl << " " 
		<< numToChar(board[0]) << " " << "|" << " " << numToChar(board[1]) << " " << "|" << " " << numToChar(board[2]) << std::endl // make me a function called print numbers or whatever, pass in line 0 * CELLS_PER_LINE
		<< " -   -   - " << std::endl << " "  // make me a function and call me print spacer
		<< numToChar(board[3]) << " " << "|" << " " << numToChar(board[4]) << " " << "|" << " " << numToChar(board[5]) << std::endl // make me a function called print numbers or whatever, pass in line 1 * CELLS_PER_LINE
		<< " -   -   - " << std::endl << " " // call print spacer function
		<< numToChar(board[6]) << " " << "|" << " " << numToChar(board[7]) << " " << "|" << " " << numToChar(board[8]) << std::endl;// make me a function called print numbers or whatever, pass in line 2 * CELLS_PER_LINE
	return;
}

int GameManager::Winner()
{
	for (int i = 0; i < 9; i++)  // Majik
	{
		if (board[i] == 0) { tieGame = false;  break; }
		
	}
	if (tieGame) { return 3; }
	// this looks like a horrible block, can you make this a function or algorithm instead of hand coding the options?
	if ((board[0] == board[1]) && (board[0] == board[2])) { return board[0]; }
	if ((board[0] == board[3]) && (board[0] == board[6])) { return board[0]; }
	if ((board[0] == board[4]) && (board[0] == board[8])) { return board[0]; }
	if ((board[1] == board[4]) && (board[1] == board[7])) { return board[1]; }
	if ((board[2] == board[4]) && (board[2] == board[6])) { return board[2]; }
	if ((board[3] == board[4]) && (board[3] == board[5])) { return board[3]; }
	if ((board[6] == board[7]) && (board[6] == board[8])) { return board[6]; }
	return 0;
}

char GameManager::numToChar(int val)
{
	switch (val)
	{
		case 0: // majik
			return '~';
		case 1:
			return 'X';
		case 2:
			return 'O';
	}
}
