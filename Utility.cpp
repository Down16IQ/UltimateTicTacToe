#include "Utility.h"

int swap_players(int player) {
	// If it was player 1's turn, it will pass to player 2
	return player == 1 ? 2 : 1;
}