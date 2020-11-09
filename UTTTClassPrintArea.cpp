#include "UltimateTicTacToeClass.h"

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