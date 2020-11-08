#ifndef ULTIMATETICTACTOECLASS_H
#define ULTIMATETICTACTOECLASS_H

#include <iostream>
#include <string>
using std::cout;
using std::stoi;

class UltimateTicTacToe {
private:
	// Consts to set them as condition in loops
	int const SIZE = 3, AREAS = 9;
	// 9 areas 3x3
	int area[9][3][3]{};
	int total_signs[3][3]{};
	// Status in terms of continuation of the game
	int area_status[3][3]{};
	// Variables to control the flow of game
	int victory = 0;
	int penultimate_area = 0;
	int last_area = 0;
	int current_area = 0;
	int chosen_area = 0;
	int decision = 0;
	int row = 0, column = 0;
	int row_last = 0, column_last = 0;
public:
	
	void print_area();
	int check_victory(int **area, int player);
	bool check_draw(int** area);

	int get_SIZE();
	int get_area_status_index(int row_, int column_);
	int** get_area_status();
	int get_victory();
	int get_current_decision();
	int get_penultimate_area();
	int get_last_area();
	int get_current_area();
	int get_chosen_area();
	int get_area_index(int thickness, int width, int height);
	int** get_area(int decision);
	int get_row_last();
	int get_column_last();
	int get_row();
	int get_column();

	void set_area_status(int player, int row, int column);
	void set_victory(int v);
	void set_current_decision(int decision);
	void set_row_column();
	void set_last_row_column();
	void set_penultimate_area(int penultimate_area);
	void set_last_area(int last_area);
	void set_current_area(int current_area);
	void set_chosen_area(int chosen_area);
	void set_sign(int player);

	friend int get_decision(int thickness, UltimateTicTacToe& value, int option);
};

#endif // !ULTIMATETICTACTOECLASS_H