#include "UltimateTicTacToeClass.h"
#include "Scan.h"

int UltimateTicTacToe::check_victory(int **area, int player, int row, int column) {
	// Vertical scan
	if (vertical_scan(area, player, column))
		return player;

	// Horizontal scan
	if (horizontal_scan(area, player, row))
		return player;

	// Hypotenuse scan
	// Checks cell 1, 5, 9 which are converted via convert_cell
	if (decision == 0 || decision == 8) {
		// +4
		return diagonal_scan(area, player, 1, 4, 3);
	}
	// Checks cell 1, 3, 5, 7, 9 which are converted via convert_cell
	if (decision == 4) {
		// +2
		return diagonal_scan(area, player, 1, 2, 5);
	}
	// Checks cell 3, 5, 7 which are converted via convert_cell
	if (decision == 2 || decision == 6) {
		// +2
		return diagonal_scan(area, player, 3, 2, 3);
	}
	// There are no winning "sign set"
	return 0;
}

bool UltimateTicTacToe::check_draw(int **area) {
	// If current area has 9 signs on - draw
	// This method will not be called if this area already has status not 0
	int total_signs = 0;
	for (int row = 0; row < 3; row++)
		for (int column = 0; column < 3; column++)
			if (area[row][column] > 0)
				total_signs++;

	if (total_signs == 9)
		return 1;
	return 0;
}