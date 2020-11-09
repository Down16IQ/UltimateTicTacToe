#include "UltimateTicTacToeClass.h"
#include "Decision.h"

void UltimateTicTacToe::set_area_status(int winner, int row, int column) {
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

void UltimateTicTacToe::set_current_area(int current_area) {
	this->current_area = current_area;
}

void UltimateTicTacToe::set_chosen_area(int chosen_area) {
	this->chosen_area = chosen_area;
}

void UltimateTicTacToe::set_sign(int player) {
	area[current_area][row][column] = player;
	// Player 1 = X	   Player 2 = O
}