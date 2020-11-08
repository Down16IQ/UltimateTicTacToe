#ifndef SCAN_H
#define SCAN_H

#include <iostream>

int hypotenuse_scan(int **area, int player, int decision, int amount_to_add, int amount_of_possibilities);
int vertical_scan(int **area, int player, int column);
int horizontal_scan(int **area, int player, int row);

#endif // !DETECTCLASS_H