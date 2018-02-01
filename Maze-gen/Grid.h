#pragma once
#include <vector>
#include "Cell.h"

class Grid
{
private:
	int maxX;
	int maxY;
	std::vector<Cell*> cells;
	std::vector<Cell*> unvisitedCell;
	std::vector<Cell*> visitedCell;
public:
	Grid(int sizeX, int sizeY);
	void genMaze();
	Cell * pickRandomUnvisitedCell();
	~Grid();
};

