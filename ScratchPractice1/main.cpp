#include <iostream>
#include "GameManager.h"

bool Start() {
	char again = 'q';
	GameManager newGame;

	while (newGame.Winner() == 0)
	{
		newGame.StartTurn();
	}
	switch (newGame.Winner())
	{
	case 1:
		std::cout << "Player 1 wins! " << std::endl;
		break;
	case 2:
		std::cout << "Player 2 wins! " << std::endl;
		break;
	case 3:
		std::cout << "Tie game! " << std::endl;
		break;
	}

		
	std::cout << "Would you like to play again? (y/n)";
	std::cin >> again;

	while (again != 'y' && again != 'n')
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<char>::max(), '\n');
		std::cout << "Invalid selection " << std::endl;
		std::cout << "Please enter (y/n): ";
		std::cin >> again;
			
	}
	if (again == 'y') 
	{ 
		return true; 
	}
	else 
	{ 
		return false; 
	}
}

int main() {
	while (Start()) {}
	std::cout << "Thanks for playing! Press any key to exit" << std::endl;
	system("pause");
}

