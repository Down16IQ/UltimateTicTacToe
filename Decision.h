#ifndef DECISION_H
#define DECISION_H

#include <iostream>
#include <conio.h>
using std::cout;

void print_decision(int **area, const int SIZE);
void print_array_decision(int* area, const int SIZE);
void convert_cell(int& x, int& y, int decision);
// This is not needed because it is declarated in UTTT Class
//int get_decision(UltimateTicTacToe& value);

#endif // !DECISION_H