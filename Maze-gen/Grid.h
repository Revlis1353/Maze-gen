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
	void buildWall(int dir, int lastdir, Cell * currentCell);
	Cell * pickRandomUnvisitedCell();
	int findIndexwithCell(Cell * data);
	void printGrid();
	~Grid();
};

