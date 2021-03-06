#ifndef ULTIMATETICTACTOECLASS_H
#define ULTIMATETICTACTOECLASS_H

class UltimateTicTacToe {

private:
	// Consts to set them as condition in loops to make reading more easier
	// or to set them as amount of cells in arrays/matrixes
	static int const SIZE = 3, AREAS = 9;

	// 9 areas 3x3
	int ***area;

	// Status in terms of continuation of the game
	// Main area that takes result of games
	int **area_status;

	// Variables to control the flow of game

	// Result of game is needed to control the end of game and to display the winner or draw
	int victory;
	// Current area is needed to convert its index in regular passes
	int current_area;
	// Chosen area is needed to convert its index if it will be on win/draw move
	int chosen_area;
	// Decision is needed to remember which cell user have selected
	int decision;
	// Row and column are needed to remember current area's indexes
	int row, column;
	// Last row and column are needed to remember last area's indexes
	// To know where the victory were, if it were
	int row_current_area, column_current_area;

public:

	// Constructor
	UltimateTicTacToe();

	// All Setters
	void set_victory(int v);
	void set_current_decision(int decision);
	void set_sign(int player);
	void set_row_column();
	// Area
	void set_area_status(int player, int row, int column);
	void set_current_area(int current_area);
	void set_chosen_area(int chosen_area);


	// All Getters
	int get_victory();
	int get_current_decision();
	// Row and column
	int get_row();
	int get_column();
	int get_row_current_area();
	int get_column_current_area();
	// Area
	int get_current_area();
	int get_chosen_area();


	// Area Getters
	int get_area_status_index(int row, int column);
	int** get_area_status();
	int get_area_index(int thickness, int width, int height);
	int** get_area(int decision);


	// Print Area
	void print_area(UltimateTicTacToe& value);


	// Checks
	int check_victory(int** area, int player, int row, int column, int area_to_check);
	bool check_draw(int** area);


	// Friend methods
	friend int get_decision(int thickness, UltimateTicTacToe& value, int option);
};

#endif // !ULTIMATETICTACTOECLASS_H