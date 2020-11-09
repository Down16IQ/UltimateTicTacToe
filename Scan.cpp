#include "Scan.h"
#include "Decision.h"

int vertical_scan(int **area, int player, int column) {
	// Vertical scan
	// Checks whole row of column column
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
	// Checks whole column of row row
	for (int i = 0, right_sign = 0; i < 3; i++) {
		if (area[row][i] != player)
			return 0;
		if (++right_sign == 3)
			return player;
	}
	return 0;
}

int hypotenuse_scan(int **area, int player, int decision, int amount_to_add, int amount_of_possibilities) {
	int row, column;

	for (int tries = 0; tries < amount_of_possibilities; decision += amount_to_add, tries++) {
		convert_cell(row, column, decision - 1);
		if (area[row][column] != player)
			return 0;
	}
	return player;
}