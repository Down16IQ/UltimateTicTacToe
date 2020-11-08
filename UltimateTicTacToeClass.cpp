#include "UltimateTicTacToeClass.h"
#include "Decision.h"
#include "Scan.h"
#include <time.h>
#include <iostream>

void UltimateTicTacToe::print_area() {
	for (int i = 0, section_of_areas = 0, row_matrix = 0; i < AREAS; i++, row_matrix++) {
		for (int j = 0, column_matrix = 0, area_in_section = 0; j < AREAS; j++, column_matrix++) {
			area[area_in_section + section_of_areas][row_matrix][column_matrix] == 1 ? cout << "X " : area[area_in_section + section_of_areas][row_matrix][column_matrix] == 2 ? cout << "O " : cout << ". ";
			// 0 = e	1 = X	 2 = O
			if (j == 2 || j == 5) {
				// -1 because it will increment by 1 in next loop
				column_matrix = -1;
				// Pass to next area in section
				area_in_section++;
				// Space between areas in line
				cout << "   ";
			}
		}

		// Print main area at the end of second line
		if (i >= 3 && i <= 5) {
			cout << '\t';
			for (int column_matrix = 0; column_matrix < 3; column_matrix++) {
				// 3 = draw (D)
				area_status[row_matrix][column_matrix] == 1 ? cout << "X " : area_status[row_matrix][column_matrix] == 2 ? cout << "O " : area_status[row_matrix][column_matrix] == 3 ? cout << "D " : cout << ". ";
			}
		}

		// Newline to print next line of an area
		cout << '\n';
		if (i == 2 || i == 5) {
			// -1 because it will increment by 1 in next loop
			row_matrix = -1;
			// Pass to next section of areas
			section_of_areas += 3;
			// Space between line of areas
			if (i == 2) {
				cout << "\t\t\t      Main area\n";
			}
			else
				cout << "\n\n";
		}
	}
}

int UltimateTicTacToe::get_SIZE() {
	return SIZE;
}

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

int UltimateTicTacToe::get_victory() {
	return victory;
}

int UltimateTicTacToe::get_current_decision() {
	return decision;
}

int UltimateTicTacToe::get_current_area() {
	return current_area;
}

int UltimateTicTacToe::get_chosen_area() {
	return chosen_area;
}

int UltimateTicTacToe::get_penultimate_area() {
	return penultimate_area;
}

int UltimateTicTacToe::get_last_area() {
	return last_area;
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

int UltimateTicTacToe::get_row_last() {
	return row_last;
}

int UltimateTicTacToe::get_column_last() {
	return column_last;
}

int UltimateTicTacToe::get_row() {
	return row;
}

int UltimateTicTacToe::get_column() {
	return column;
}

int UltimateTicTacToe::check_victory(int **area, int player) {
	// Vertical scan
	if (vertical_scan(area, player, column))
		return player;

	// Horizontal scan
	if (horizontal_scan(area, player, row))
		return player;

	// Hypotenuse scan
	// Checks cell 1, 5, 9 which convert via convert_cell
	if (decision == 1 || decision == 9) {
		// +4
		return hypotenuse_scan(area, player, 1, 4, 3);
	}
	// Checks cell 1, 3, 5, 7, 9 which convert via convert_cell
	if (decision == 5) {
		// +2
		return hypotenuse_scan(area, player, 5, 2, 5);
	}
	// Checks cell 3, 5, 7 which convert via convert_cell
	if (decision == 3 || decision == 7) {
		// +2
		return hypotenuse_scan(area, player, 3, 2, 3);
	}
	// There are no winning move
	return 0;
}

bool UltimateTicTacToe::check_draw(int **area) {
	int total_signs = 0;
	for (int row = 0; row < SIZE; row++)
		for (int column = 0; column < SIZE; column++)
			if (area[row][column] > 0)
				total_signs++;

	if (total_signs == 9)
		return 1;
	return 0;
}

void UltimateTicTacToe::set_area_status(int winner, int row, int column) {
	// Not this->
	area_status[row][column] = winner;
}

void UltimateTicTacToe::set_victory(int victory) {
	this->victory = victory;
}

void UltimateTicTacToe::set_current_decision(int decision) {
	this->decision = decision;
}

void UltimateTicTacToe::set_row_column() {
	convert_cell(row, column, decision);
}

void UltimateTicTacToe::set_last_row_column() {
	row_last = row;
	column_last = column;
}

void UltimateTicTacToe::set_current_area(int current_area) {
	this->current_area = current_area;
}

void UltimateTicTacToe::set_chosen_area(int chosen_area) {
	this->chosen_area = chosen_area;
}

void UltimateTicTacToe::set_penultimate_area(int penultimate_area) {
	this->penultimate_area = penultimate_area;
}

void UltimateTicTacToe::set_last_area(int last_area) {
	this->last_area = last_area;
}

void UltimateTicTacToe::set_sign(int player) {
	area[current_area][row][column] = player;
	// Player 1 = X	   Player 2 = O
	total_signs[row][column]++;
}