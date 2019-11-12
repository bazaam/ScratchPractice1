#pragma once
#include <iostream>
class GameManager
{
private:
	int board[9] = { 0 };
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

