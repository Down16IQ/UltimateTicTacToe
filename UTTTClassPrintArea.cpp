#include "UltimateTicTacToeClass.h"
#include "Utility.h"

void UltimateTicTacToe::print_area(UltimateTicTacToe& value) {
	// Change the row of matrix
	for (int i_counter = 0, section_of_areas = 0, row_matrix = 0, row_status = 0; i_counter < AREAS; i_counter++, row_matrix++) {

		// I need to increment status' matrix row only on 1 4 and 7
		if (i_counter != 0 && i_counter % 3 == 0)
			row_status++;

		// Change the column of matrix												AREAS + 1 to print current status of last area on line
		for (int j_counter = 0, column_matrix = 0, area_in_section = 0, column_status = 0; j_counter < AREAS + 1; j_counter++, column_matrix++) {

			// I need to increment status' matrix column only on 1 4 and 7
			if (j_counter != 0 && j_counter % 3 == 0)
				column_status++;

			// Print status of area
			if (j_counter == AREAS && (i_counter == 1 || i_counter == 4 || i_counter == 7))
				cout << convert_number_to_sign(get_area_status(), row_status, column_status, 1) << "    ";

			// If status of last area on line was printed - break
			if (j_counter == AREAS)
				break;

			// Print sings instead of printing matrix's value	0 = .   1 = X	 2 = O
			cout << convert_number_to_sign(get_area(area_in_section + section_of_areas), row_matrix, column_matrix, 0) << " ";
			//area[area_in_section + section_of_areas][row_matrix][column_matrix] == 1 ? cout << "X " : area[area_in_section + section_of_areas][row_matrix][column_matrix] == 2 ? cout << "O " : cout << ". ";

			if (j_counter == 2 || j_counter == 5) {
				// -1 because it will increment by 1 in next loop
				column_matrix = -1;

				// Pass to next area in section
				area_in_section++;

				// Space between areas in line and current status of area on its right if it is the second line of it
				if (i_counter == 1 || i_counter == 4 || i_counter == 7)
					cout << convert_number_to_sign(get_area_status(), row_status, column_status, 1) << "    ";
				else
					cout << "     ";
			}
		}

		// Print main area at the end of second line
		if (i_counter >= 3 && i_counter <= 5) {
			if (i_counter != 4)
				cout << '\t';
			cout << '\t';
			for (int column_matrix = 0; column_matrix < 3; column_matrix++) {
				cout << convert_number_to_sign(get_area_status(), row_matrix, column_matrix, 0) << ' ';
				// 3 = draw (D)
			}
		}

		// Newline to print next line of an area
		cout << '\n';
		if (i_counter == 2 || i_counter == 5) {
			// -1 because it will increment by 1 in next loop
			row_matrix = -1;
			// Pass to next section of areas
			section_of_areas += 3;
			// Space between line of areas
			if (i_counter == 2) {
				cout << "\n\t\t\t\t      Main area\n";
			}
			else
				cout << "\n\n\n";
		}
	}
}