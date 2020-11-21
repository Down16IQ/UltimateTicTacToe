#include "UTTTLogic.h"
#include "UltimateTicTacToeClass.h"
#include "Decision.h"
#include "Utility.h"

// To random player
#include <time.h>
// using std
#include <iostream>
// Print messages
using std::cout;

void UTTT_logic() {
	// To get random player
	srand(time(NULL));

	// Declaring object
	UltimateTicTacToe game;

	// Random player
	int player = rand() % 2 +1;
	player = swap_players(player);

	// Variable to control if player was sent to already finished area or not
	bool chosen = false;

	// To remember row and column for draw if
	int row, column;

	// Output to user
	cout << "      Game area\n     Turn player " << player << "\n\n";
	game.print_area(game);
	cout << "\nWhere do you want to start?\nDigit any of these numbers\n";
	print_decision(game.get_area(game.get_current_area()));

	// Get answer and set current area
	game.set_current_area(get_decision(game.get_current_area(), game, 1));

	// Set row and column via converting decision
	game.set_row_column();

	// Whole game loop
	// Works until status of victory changes from 0 to 1 - 3 (Player 1 or 2 or Draw)
	while (game.get_victory() == 0) {
		// Clear screen
		system("CLS");

		// Reset bool variable
		chosen = false;

		// Info about the current player and his sign
		cout << "    Turn player " << player << "\n    Your sign is ";
		player == 2 ? cout << "O\n\n" : cout << "X\n\n";

		// Print whole area
		game.print_area(game);

		// Message about current area and question about decision
		cout << "\nCurrent area: " << game.get_current_area() + 1;

		// If player is sent to already finished area
		if (game.get_area_status_index(game.get_row(), game.get_column())) {
			cout << "\nThis area is finished, which area do you want to play on?\n";

			// Print choice of areas
			print_decision(game.get_area_status());

			// Get choice and set it as current/chosen area
			game.set_chosen_area(get_decision(0, game, 2));
			game.set_current_area(game.get_chosen_area());

			// Convert row and column to print choice area correctly
			game.set_row_column();
			//game.set_last_row_column();

			// Set area choose to true to pass different parameters in the future
			chosen = true;

			// Clear screen
			system("CLS");

			// Info about the current player and his sign
			cout << "    Turn player " << player << "\n    Your sign is ";
			player == 2 ? cout << "O\n\n" : cout << "X\n\n";

			// Print whole area
			game.print_area(game);

			// Message about chosen area
			cout << "\nCurrent area: " << game.get_current_area() + 1;
		}

		// Question about choice of cell
		cout << "\nOn which cell do you want to put your sign?\nDigit any of these numbers\n";

		// Print choices
		print_decision(game.get_area(game.get_current_area()));

		// Get decision
		game.set_current_decision(get_decision(game.get_current_area(), game, 1));

		// Set current and last row and column via converting decision
		//game.set_last_row_column();
		game.set_row_column();
		//game.set_row_column_current_area();

		// Set sign according to decided cell
		game.set_sign(player);

		// Convert cell to indexes		One line if
		// This is needed here to control win/draw correctly (without assigning code will break)
		// and to check in draw 'if' if there is already non null value
		convert_cell(row, column, chosen ? game.get_chosen_area() : game.get_current_area());

		// Check victory on area
		if (game.check_victory(game.get_area(game.get_current_area()), player, game.get_row(), game.get_column(), chosen ? game.get_chosen_area() : game.get_current_area())) {

			// Change area status to victory of current player
			game.set_area_status(player, row, column);

			// Message about winner on current area
			cout << "\nPlayer " << player << " won on area " << game.get_current_area() + 1 << '\n';

			// Pause game to let player see the message above, because on next loop screen will be clean
			system("PAUSE");
		}

		// Check draw on area
		if (!game.get_area_status_index(row, column) && game.check_draw(game.get_area(game.get_current_area()))) {

			// Change area status to victory of current player
			game.set_area_status(3, row, column); // 3 means draw

			// Message about draw
			cout << "\nDraw on area " << game.get_current_area() + 1 << '\n';

			// Pause game to let player see the message above, because on next loop screen will be clean
			system("PAUSE");
		}

		// Check victory on main area
		if (game.check_victory(game.get_area_status(), player, game.get_row_current_area(), game.get_column_current_area(), game.get_current_area()))
			game.set_victory(player);

		// Check draw on main area
		if (!game.get_victory() && game.check_draw(game.get_area_status()))
			game.set_victory(3);

		// Swap player
		player = swap_players(player);

		// Next turn opponent will make his choice on x area,
		// that depends on last player's decision
		game.set_current_area(game.get_current_decision());
	}

	// Clean screen
	system("CLS");

	// Print area and make spaces
	cout << "      Game area\n" << "\n\n";
	game.print_area(game);
	cout << "\n\n";

	// Message about winner or draw
	game_result(game.get_victory());
	cout << "\n\n\n";

	// Pause game to let player see the message about result of game and area, because console will be closed if it was launched via .exe
	system("PAUSE");
}