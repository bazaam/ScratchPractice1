#pragma once
#include <iostream>
class GameManager
{
private:
	// 9 is a majik number
	int board[9] = { 0 }; // how large is an int?  Does it seem like over kill?
	bool cellLock[9] = {};
	int selection; 
	int player; // might want unsigned int since player will never be negative?
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

