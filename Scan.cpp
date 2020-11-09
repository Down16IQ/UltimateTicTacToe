#include "Scan.h"
#include "Decision.h"

int vertical_scan(int **area, int player, int column) {
	// Vertical scan
	// Checks whole column starting up from row 0 to 2
	for (int i = 0, right_sign = 0; i < 3; i++) {
		if (area[i][column] != player)
			return 0;
		if (++right_sign == 3)
			return player;
	}
	return 0;
}

int horizontal_scan(int** area, int player, int row) {
	// Horizontal scan
	// Checks whole row starting up from column 0 to 2
	for (int i = 0, right_sign = 0; i < 3; i++) {
		if (area[row][i] != player)
			return 0;
		if (++right_sign == 3)
			return player;
	}
	return 0;
}

int diagonal_scan(int **area, int player, int decision, int amount_to_add, int amount_of_possibilities) {
	// Variables to store current cell to indexes
	// Ex.: cell 6 (5) will have index 1 (row) and 2 (column)
	int row, column;

	// Add amount_to_add to decision to check X cell, indexes of which are calculated inside the loop
	for (int tries = 0; tries < amount_of_possibilities; decision += amount_to_add, tries++) {
		convert_cell(row, column, decision - 1);
		// If any of cells is taken not by current player - there is no winning "sign set"
		if (area[row][column] != player)
			return 0;
	}
	// If there are only player's signs
	return player;
}