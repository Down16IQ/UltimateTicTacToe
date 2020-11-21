#include "UltimateTicTacToeClass.h"

UltimateTicTacToe::UltimateTicTacToe()
	: row_current_area (0), column_current_area (0), row (0), column (0), decision (0), chosen_area (0), current_area (0), victory (0)
{
	area = new int**[AREAS];
	area_status = new int*[SIZE];

	for (size_t i = 0; i < SIZE; i++)
	{
		area_status[i] = new int[SIZE] {};
	}

	for (size_t i = 0; i < AREAS; i++)
	{
		area[i] = new int* [SIZE] {};
		for (int j = 0; j < SIZE; j++) {
			area[i][j] = new int[SIZE];
			for (size_t h = 0; h < SIZE; h++)
			{
				area[i][j][h] = 0;
			}
		}
	}
}