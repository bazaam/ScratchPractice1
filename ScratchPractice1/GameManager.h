#pragma once
#include <iostream>
class GameManager
{
private:
	int board[9] = { 0 }; // Is this reset anywhere?  How does game 2 work?
	bool cellLock[9] = {};
	int selection;
	int player;
	bool valid;
	bool tieGame;

public:
	GameManager();
	~GameManager();
	int StartTurn();
	void PrintBoard();
	int Winner();
	char numToChar(int val);
};

