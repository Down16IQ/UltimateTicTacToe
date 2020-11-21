#include "Utility.h"

// using std
#include <iostream>

int swap_players(int player) {
	// If it was player 1's turn, it will pass to player 2
	return player == 1 ? 2 : 1;
}

char convert_number_to_sign(int** area, int row, int column, int option) {
		// Option 0 regular one																							Option 1 to show area status on its right
	return !option ? area[row][column] == 0 ? '.' : area[row][column] == 1 ? 'x' : area[row][column] == 2 ? 'o' : 'D' : area[row][column] == 1 ? 'X' : area[row][column] == 2 ? 'O' : area[row][column] == 3 ? 'D' : 'A';
}

void game_result(int result) {
	result < 3 ? std::cout << "Player " << result << " won!" : std::cout << "Draw";
}
