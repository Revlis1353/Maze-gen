#include "Grid.h"

Grid::Grid(int sizeX, int sizeY) {
	wall_north = new bool[sizeX*sizeY];
	wall_east = new bool[sizeX*sizeY];
	isWall = new bool[sizeX*sizeY];
	direction = new int[sizeX*sizeY];
}


Grid::~Grid() {
	delete wall_east;
	delete wall_north;
	delete isWall;
	delete direction;
}

void Grid::genMaze() {
	//Set start point

	//###loop
		//Pick random cell

		//Make way to exist maze passage
}