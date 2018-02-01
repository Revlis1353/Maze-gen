#include <cstdlib>
#include <ctime>
#include "Grid.h"


Grid::Grid(int sizeX, int sizeY) : maxX(sizeX), maxY(sizeY) {
	int i, j;
	for (i = 0; i < sizeY; i++) {
		for (j = 0; j < sizeX; j++) {
			Cell * tempCell = new Cell(j, i);
			unvisitedCell.push_back(tempCell);
			cells.push_back(tempCell);
		}
	}
	srand((int)time(0));
}


Grid::~Grid() {
	//remove cells in vector

}

void Grid::genMaze() {
	//Set start point
	pickRandomUnvisitedCell() -> changeToVisited();
	//###loop
	while (unvisitedCell.size() > 0) {
		//Pick random cell
		Cell * startCell = pickRandomUnvisitedCell();
		Cell * endCell = startCell;

		//Make way to exist maze passage
		while (!endCell->isVisited) {
			int direction = rand() % 4;
			switch (direction) {

			case 0:
				if(endCell->getY + 1 == maxY)
					break;
				endCell->setDirection(direction);
				endCell = cells[maxX * (endCell->getY + 1) + endCell->getX];
				break;
			case 1:
				if (endCell->getX + 1 == maxX)
					break;
				endCell->setDirection(direction);
				endCell = cells[maxX * endCell->getY + endCell->getX + 1];
				break;
			case 2:
				if (endCell->getY == 0)
					break;
				endCell->setDirection(direction);
				endCell = cells[maxX * (endCell->getY - 1) + endCell->getX];
				break;
			case 3:
				if (endCell->getX == 0)
					break;
				endCell->setDirection(direction);
				endCell = cells[maxX * endCell->getY + endCell->getX - 1];
				break;
			}
		}
		//Now endCell is located in maze
		//I'll Track way from startCell to endCell
	}
}

Cell * Grid::pickRandomUnvisitedCell() {
	int tempIndex = rand() % unvisitedCell.size();
	Cell * tempCell = unvisitedCell[tempIndex];
	unvisitedCell.erase(unvisitedCell.begin() + tempIndex);
	return tempCell;
}