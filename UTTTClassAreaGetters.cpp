#include "UltimateTicTacToeClass.h"

int UltimateTicTacToe::get_area_status_index(int row, int column) {
	// In case of get_decision it will pass different row and column,
	// so I need to pass them as a parameter, not to use the class' one
	return area_status[row][column];
}

int** UltimateTicTacToe::get_area_status() {
	// Create a pointer to a pointer
	int** array_to_return = 0;
	// Create an array
	array_to_return = new int* [SIZE];

	for (int h = 0; h < SIZE; h++) {
		// Array to matrix
		array_to_return[h] = new int[SIZE];

		// Coppy x row of area_status to new line of matrix to return
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
	// Create a pointer to a pointer
	int** array_to_return = 0;
	// Create an array
	array_to_return = new int* [SIZE];

	for (int h = 0; h < SIZE; h++) {
		// Array to matrix
		array_to_return[h] = new int[SIZE];

		// Coppy x row of y (that depends on player's decision)
		// area to new line of matrix to return
		for (int w = 0; w < SIZE; w++) {
			array_to_return[h][w] = area[decision][h][w];
		}
	}

	return array_to_return;
}