#include "Scan.h"
#include "Decision.h"

int hypotenuse_scan(int **area, int player, int decision, int amount_to_add, int amount_of_possibilities) {
	int x, y;

	for (int i = decision, tries = 0; tries < amount_of_possibilities; i += amount_to_add, tries++) {
		convert_cell(x, y, i + 1);
		if (area[x][y] != player)
			return 0;
	}
	return player;
}

int vertical_scan(int **area, int player, int column) {
	// Vertical scan
	// Checks whole row of y column
	for (int i = 0, right_sign = 0; i < 3; i++) {
		if (area[i][column] != player)
			return 0;
		if (++right_sign == 3)
			return player;
	}
	return 0;
}

int horizontal_scan(int **area, int player, int row) {
	// Horizontal scan
	// Checks whole column of x row
	for (int i = 0, right_sign = 0; i < 3; i++) {
		if (area[row][i] != player)
			return 0;
		if (++right_sign == 3)
			return player;
	}
	return 0;
}