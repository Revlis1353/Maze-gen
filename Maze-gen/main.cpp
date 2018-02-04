#include <iostream>
#include "Grid.h"

int main() {
	Grid *grid = new Grid(25, 25);

	grid->genMaze();
	
	std::cout << "Success!" << std::endl;
	grid->printGrid();
	system("pause");
	return 0;
}