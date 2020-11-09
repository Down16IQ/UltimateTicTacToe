#include "UltimateTicTacToeClass.h"

int UltimateTicTacToe::get_area_status_index(int row, int column) {
	// Without these variables it would check the last area,
	// because row and column change after user's choice
	// ca stands for current area
	return area_status[row][column];
}

int** UltimateTicTacToe::get_area_status() {
	int** array_to_return = 0;
	array_to_return = new int* [SIZE];

	for (int h = 0; h < SIZE; h++) {
		array_to_return[h] = new int[SIZE];

		for (int w = 0; w < SIZE; w++) {
			array_to_return[h][w] = area_status[h][w];
		}
	}

	return array_to_return;
}

int UltimateTicTacToe::get_area_index(int thickness, int width, int height) {
	return area[thickness][width][height];
}

int** UltimateTicTacToe::get_area(int decision) {
	int** array_to_return = 0;
	array_to_return = new int* [SIZE];

	for (int h = 0; h < SIZE; h++) {
		array_to_return[h] = new int[SIZE];

		for (int w = 0; w < SIZE; w++) {
			array_to_return[h][w] = area[decision][h][w];
		}
	}

	return array_to_return;
}