#include "Decision.h"
#include "UltimateTicTacToeClass.h"

// using std
#include <iostream>
// getch
#include <conio.h>

void print_decision(int **area) {
	// Row change
	for (int row = 0, number = 0; row < 3; row++) {
		std::cout << "\t";
		// Column change
		for (int column = 0; column < 3; column++) {
			number++;
			area[row][column] == 0 ? std::cout << number : std::cout << "x";
			std::cout << " ";
			// 0 = no sign 1 = player's 1 sign 2 = player's 2 sign
		}
		std::cout << '\n';
	}
}

void convert_cell(int& x, int& y, int decision) {
	// Cell number to 2D array index
	switch (decision) {
	case 0: x = 0; y = 0; break;
	case 1: x = 0; y = 1; break;
	case 2: x = 0; y = 2; break;
	case 3: x = 1; y = 0; break;
	case 4: x = 1; y = 1; break;
	case 5: x = 1; y = 2; break;
	case 6: x = 2; y = 0; break;
	case 7: x = 2; y = 1; break;
	case 8: x = 2; y = 2; break;
	default: break;
	}
}

////////////////////////////////////////////////
// I need to fix it to remove option variable //
////////////////////////////////////////////////
int get_decision(int thickness, UltimateTicTacToe& value, int option) {
	// Variables to store decision and its indexes
	int decision, row, column;

	while (true) {
		do {
			decision = _getch();
			// _getch takes ASCII table value, that is 49 for 1 and 57 for 9
			// so I substract 48 to take value from 1 to 9
			// and -1 to take value from 0 to 8
			decision -= 49;

			if (decision < 0 || decision > 8)
				std::cout << "You can't choice the number out of range. Retry.\n";
		} while (decision < 0 || decision > 8);

		// Convert decision to matrix indexes
		convert_cell(row, column, decision);

		// Option 1 is for regular areas
		// Option 2 is for main area
		if (option == 1) {
			if (!value.get_area_index(thickness, row, column))
				return decision;
		}
		else
			if (!value.get_area_status_index(row, column))
				return decision;

		if (option == 1)
			std::cout << "You can't choice this one because it is already signed. Retry.\n";
		else
			std::cout << "You can't choice this one because it is already finished. Retry.\n";
	}
}
