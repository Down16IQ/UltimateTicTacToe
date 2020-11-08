#include "UTTTLogic.h"
#include "UltimateTicTacToeClass.h"
#include "Decision.h"
#include "Utility.h"

void UTTT_logic() {
	// To get random player
	srand(time(NULL));

	// Declaring object
	UltimateTicTacToe game;

	// Random player
	int player = rand() % 2 +1;
	player = swap_players(player);

	bool chosen = false;

	cout << "      Game area\n     Turn player " << player << "\n\n";
	game.print_area();
	cout << "\nWhere do you want to start?\nDigit any of these numbers\n";

	print_decision(game.get_area(game.get_current_area()), game.get_SIZE());

	game.set_current_area(get_decision(game.get_current_area(), game, 1));

	// Set row and column via converting decision
	game.set_row_column();

	while (!game.get_victory()) {
		// Clean screen
		system("CLS");

		chosen = false;

		// Info about the current player and his sign
		cout << "    Turn player " << player << "\n    Your sign is ";
		player == 2 ? cout << "O\n\n" : cout << "X\n\n";

		// Print whole area
		game.print_area();

		// Message about current area and quastion about decision
		cout << "\nCurrent area: " << game.get_current_area() + 1;

		// If current area is finished
		if (game.get_area_status_index(game.get_row(), game.get_column())) {
			cout << "\nThis area is finished, which area do you want to play on?\n";
			print_decision(game.get_area_status(), game.get_SIZE());
			game.set_chosen_area(get_decision(0, game, 2));
			game.set_current_area(game.get_chosen_area());
			game.set_row_column();
			game.set_last_row_column();
			chosen = true;

			system("CLS");

			cout << "    Turn player " << player << "\n    Your sign is ";
			player == 2 ? cout << "O\n\n" : cout << "X\n\n";
			game.print_area();
			cout << "\nCurrent area: " << game.get_current_area() + 1;
		// If it is not
		}
		cout << "\nOn which cell do you want to put your sign?\nDigit any of these numbers\n";

		// Print choices
		print_decision(game.get_area(game.get_current_area()), game.get_SIZE());

		// Get decision
		game.set_current_decision(get_decision(game.get_current_area(), game, 1));

		// Set current and last row and column via converting decision
		game.set_last_row_column();
		game.set_row_column();

		// Set sign
		game.set_sign(player);
		
		// Check victory on area
		if (game.check_victory(game.get_area(game.get_current_area()), player)) {
			int row, column;
			convert_cell(row, column, chosen ? game.get_chosen_area() : game.get_current_area());
			game.set_area_status(player, row, column);
			cout << "\nPlayer " << player << " won on area " << game.get_current_area() + 1 << '\n';
			system("PAUSE");
		}

		// Check draw on area
		if (game.check_draw(game.get_area(game.get_current_area())) && !game.get_area_status_index(game.get_row(), game.get_column())) {
			int row, column;
			convert_cell(row, column, chosen ? game.get_chosen_area() : game.get_current_area());
			game.set_area_status(3, row, column); // 3 means draw
			cout << "\nDraw on area " << game.get_current_area() + 1 << '\n';
			system("PAUSE");
		}

		// Check victory on main area
		if (game.check_victory(game.get_area_status(), player))
			game.set_victory(player);

		// Check draw on main area
		if (game.check_draw(game.get_area_status()) && !game.get_victory())
			game.set_victory(0);

		// Swap player
		player = swap_players(player);

		// Next turn opponent will make his choice on x area,
		// that depends on last player's decision
		game.set_last_area(game.get_current_area());
		game.set_current_area(game.get_current_decision());
	}

	system("CLS");
	cout << "      Game area\n" << "\n\n";
	game.print_area();
	cout << "\n\n";
	game.get_victory() > 0 ? cout << "Player " << game.get_victory() << " won!" : cout << "Draw";
	cout << "\n\n\n";
	system("PAUSE");
}